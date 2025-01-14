﻿
#include <Analysis/LinearLineOfSightAnalysis.h>
#include <tool/CodeTransformHelp.h>


GeoGlobe::LinearLineOfSightAnalysis::LinearLineOfSightAnalysis(MapNode* mapNode)
{
	m_bFinished = false;
	setMapNode(mapNode);

	_startLineTraker  = new LineTraker3DElement(getMapNode());  
	_startLineTraker->setDefaultDragMode(LineTraker3DElement::DRAGMODE_VERTICAL);
	_startLineTraker->setCullingActive(false);
	addChild(_startLineTraker);

	_endLineTraker = new LineTraker3DElement(getMapNode());
	_endLineTraker->setDefaultDragMode(LineTraker3DElement::DRAGMODE_VERTICAL);
	_endLineTraker->setCullingActive(false);
	_nStep = 0;
}

GeoGlobe::LinearLineOfSightAnalysis::~LinearLineOfSightAnalysis()
{
}

MapNode* GeoGlobe::LinearLineOfSightAnalysis::getMapNode() 
{ 
	return _mapNode.get();
}

void GeoGlobe::LinearLineOfSightAnalysis::setMapNode( MapNode* mapNode )
{
	MapNode* oldMapNode = getMapNode();
	if ( oldMapNode != mapNode )
	{
		_mapNode = mapNode;
	}
}

void GeoGlobe::LinearLineOfSightAnalysis::traverse(osg::NodeVisitor& nv)
{
	if (nv.getVisitorType() == osg::NodeVisitor::EVENT_VISITOR)
	{
		osgGA::EventVisitor* ev = static_cast<osgGA::EventVisitor*>(&nv);
		for(osgGA::EventQueue::Events::iterator itr = ev->getEvents().begin() ; itr != ev->getEvents().end() ; ++itr)
		{
			osgGA::GUIEventAdapter* ea = dynamic_cast<osgGA::GUIEventAdapter*>(itr->get());
			if ( ea && handle(*ea, *(ev->getActionAdapter())))
				ea->setHandled(true);
		}
	}
	osg::Group::traverse(nv);
}

bool GeoGlobe::LinearLineOfSightAnalysis::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	if (ea.getHandled()) 
		return false;

	osgViewer::View* view = dynamic_cast<osgViewer::View*>(&aa);
	if (!view) 
		return false;

	if (!_mapNode.valid()) 
		return false;

	if (_nStep == 3)
		return false;
	
	//第0步，起始Traker完成后，创建billboard，开始第1步
	if (_nStep == 0 && _startLineTraker->IsFinished())
	{
		//0->1
		_nStep++;

		GeoPoint geoPt = _startLineTraker->getPosition();
		_los = new LinearLineOfSightNode(_mapNode,geoPt,geoPt);
		addChild(_los);

		_endLineTraker->addPositionChangedCallback(new GeoGlobe::LOSDraggerCallback(_los, false ) );
		addChild(_endLineTraker);

		//构建起点billboard
		std::ostringstream s1;
		s1 << "起点\n"<<"经度："<<geoPt.x()<<"\n纬度："<<geoPt.y()<<"\n高程："<<geoPt.z()<<"\n";
		_starBillboard = CreateBillboard(geoPt,s1.str());
	}
	//第1步，鼠标移动，绘制可视分析线和不可见点
	else if (_nStep == 1 && ea.getEventType() == osgGA::GUIEventAdapter::MOVE && _los.valid())
	{
		double lon, lat, h;
		if (!getLocationAt(view, ea.getX(), ea.getY(), lon, lat,h))
			return false;

		GeoPoint geoEndPt = GeoPoint(getMapNode()->getMapSRS(),lon,lat,h,ALTMODE_ABSOLUTE);
		_los->setEnd(geoEndPt);

		//不可见点更新	
		UpdateHitBillboard();
	}
	//由第1步到第2步，鼠标点击
	else if (_nStep == 1 && ea.getEventType() == osgGA::GUIEventAdapter::PUSH && _los.valid())
	{
		//1->2
		_nStep ++;
		return false;
	}
	//第2步，鼠标移动，开始endlineTraker
	else if (_nStep == 2)
	{
		GeoPoint geoEndPt = _endLineTraker->getPosition();
		
		_los->setEnd(geoEndPt);

		//构建终点billboard
		std::ostringstream s1;
		s1 << "终点\n"<<"经度："<<geoEndPt.x()<<"\n纬度："<<geoEndPt.y()<<"\n高程："<<geoEndPt.z()<<"\n";
		if (!_endBillboard.valid())
			_endBillboard = CreateBillboard(geoEndPt,s1.str());

		_endBillboard->setPosition(geoEndPt);
		_endBillboard->setDynamic( true );
		std::string na = CodeHelp::String_To_UTF8(s1.str());
		_endBillboard->setText(na);	

		//不可见点更新
		UpdateHitBillboard();
	}
	//由第2步到第3步，结束操作
	if (_endLineTraker->IsFinished())
	{
		m_bFinished = true;
		//防止可视域分析在结束后继续根据地形分析
		_los->setMapNode(NULL);
		//2->3
		_nStep ++;
		//完成分析
		return false;
	}
	return false;
}

bool GeoGlobe::LinearLineOfSightAnalysis::getLocationAt(osgViewer::View* view, double x, double y, double &lon, double &lat, double &h)
{
	osgUtil::LineSegmentIntersector::Intersections results;            
	if ( getMapNode() &&  view->computeIntersections( x, y, results, 0x1 ) )
	{
		// find the first hit under the mouse:
		osgUtil::LineSegmentIntersector::Intersection first = *(results.begin());
		osg::Vec3d point = first.getWorldIntersectPoint();

		double lat_rad, lon_rad, height;       
		getMapNode()->getMap()->getProfile()->getSRS()->getEllipsoid()->convertXYZToLatLongHeight( 
			point.x(), point.y(), point.z(), lat_rad, lon_rad, height );

		lat = osg::RadiansToDegrees( lat_rad );
		lon = osg::RadiansToDegrees( lon_rad );
		h = height;
		return true;
	}
	return false;
}

osg::ref_ptr<GeoGlobe::PlaceName::GeoBillboard> GeoGlobe::LinearLineOfSightAnalysis::CreateBillboard(GeoPoint geoPt,std::string strContent)
{
	//构建billboard
	std::string na = CodeHelp::String_To_UTF8(strContent);
	osgEarth::Symbology::Style chapin;

	chapin.getOrCreate<osgEarth::IconSymbol>()->declutter() = false;
	chapin.getOrCreate<osgEarth::IconSymbol>()->occlusionCull() = false;
	chapin.getOrCreate<osgEarth::TextSymbol>()->declutter() = false;
	chapin.getOrCreate<osgEarth::TextSymbol>()->occlusionCull() = false;
	chapin.getOrCreate<osgEarth::Symbology::TextSymbol>()->size()=18.0f;
	//chapin.getOrCreate<osgEarth::Symbology::TextSymbol>()->halo()->color()=Color::White;
	chapin.getOrCreate<osgEarth::Symbology::TextSymbol>()->fill()->color()=Color::White;
	chapin.getOrCreate<osgEarth::Symbology::TextSymbol>()->font() = "msyh.ttc";
	chapin.getOrCreate<osgEarth::Symbology::TextSymbol>()->encoding() = osgEarth::Symbology::TextSymbol::ENCODING_UTF8;
	osg::ref_ptr<GeoGlobe::PlaceName::GeoBillboard> pn = new GeoGlobe::PlaceName::GeoBillboard(geoPt,na,chapin,true);
	pn->setCullingActive(false);
	addChild(pn);

	return pn.release();
}

bool GeoGlobe::LinearLineOfSightAnalysis::UpdateHitBillboard()
{
	//不可见点更新
	if (_los->getHasLOS() && _hitBillboard.valid())
	{
		removeChild(_hitBillboard);
		_hitBillboard = NULL;
		return false;
	}

	if (_los->getHasLOS())
		return false;

	std::ostringstream s1;
	s1 << "不可视点\n"<<"经度："<<_los->getHit().x()<<"\n纬度："<<_los->getHit().y()<<"\n高度："<<_los->getHit().z()<<"\n";
	if (!_hitBillboard.valid())
		_hitBillboard = CreateBillboard(_los->getHit(),s1.str());

	std::string na = CodeHelp::String_To_UTF8(s1.str());
	_hitBillboard->setPosition(_los->getHit());
	_hitBillboard->setDynamic( true );
	_hitBillboard->setText(na);	

	return false;
}

bool GeoGlobe::LinearLineOfSightAnalysis::IsFinished()
{
	return m_bFinished;
}
