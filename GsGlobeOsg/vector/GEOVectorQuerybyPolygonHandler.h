#ifndef OSGEARTH_GEOVECTORQUERYBYPOLYGON_QUERY_TOOL_H
#define OSGEARTH_GEOVECTORQUERYBYPOLYGON_QUERY_TOOL_H 1

#include <osgGA/GUIEventHandler>
#include <osg/View>
#include <osgViewer/Viewer>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Vec3d>
#include <osg/Camera>
#include <osg/Matrix>
#include <osg/Drawable>
#include <osg/StateSet>
#include <osg/StateAttribute>
#include <osg/Depth>
#include <osg/LineWidth>
#include <osgUtil/LineSegmentIntersector>

#include <osgEarth/MapNode>
#include <osgEarthUtil/Controls>
#include <osgEarthFeatures/Common>
#include <osgEarthFeatures/Feature>
#include <osgEarthSymbology/Geometry>
#include <osgEarthSymbology/Style>
#include <osgEarth/StringUtils>
#include <osgEarthAnnotation/FeatureNode>

#include <vector>

#include "GEOVectorAttributeQuery.h"
#include "LineIntersectTest.h"
#include "GeoFeature_SqliteApi.h"
#include "GEOFeature_XMLApi.h"
#include "GEOWFSFeatureOptions.h"

#define HLGeode "highlightGeode"
namespace GeoGlobe {
	namespace GeoVector
	{
		enum MOUSEDOWNTYPE
		{
			LEFTCLICK,
			RIGHTCLICK,
			LDOUBLECLICK,
			RDOUBLECLICK
		};
		using namespace osgEarth;

		//父类，多边形查询基础类
		class GEOVectorQuerybyPolygonHandler : public osgGA::GUIEventHandler
		{
		public:
			struct VectorQueryCallback : public osg::Referenced 
			{
				struct EventArgs 
				{
					const osgGA::GUIEventAdapter* _ea;
					osgGA::GUIActionAdapter* _aa;
					osg::Vec3d               _worldPoint;
				};

				// called when a valid feature is found under the mouse coords
				virtual void onHit(std::vector<AttributeTable>& tables,const EventArgs& args){}

				// called when no feature is found under the mouse coords
				virtual void onMiss( const EventArgs& args ) { }
			};//sturct vectorquerycallback

		public:
			GEOVectorQuerybyPolygonHandler(
				osg::Group* root,
				MapNode* mapNode,
				VectorQueryCallback* callbackToAdd
				) : _root(root),_mapNode(mapNode)
			{
				initQueryHandler();
				if (callbackToAdd)
				{
					addCallback(callbackToAdd);
				}
			};

			virtual MapNode* getMapNode(){return _mapNode.get();}

			virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa)
			{
				bool handled =false;
				bool leftattempt=false;
				bool rightattempt=false;

				
				leftattempt = 
					ea.getEventType() == osgGA::GUIEventAdapter::RELEASE &&
					_lmouseDown &&
					fabs(ea.getX()-_mouseDownX) <=3.0 &&
					fabs(ea.getY()-_mouseDownY) <=3.0;

				if (leftattempt && getMapNode())
				{
					if (_dbmouseDown)
					{
						_worldPoints->clear();
						_llhPoints->clear();
						GEOVectorHighlightCommom::removeHighlightGeode(_root,"highlightGeode");
						_dbmouseDown=false;
						_featureNodePoly->getFeature()->getGeometry()->clear();
						_featureNodePoly->init();
					}
					osgViewer::View* view = static_cast<osgViewer::View*>(aa.asView());

					MousepstoWorldps(view,osg::Vec2f(ea.getX(),ea.getY()),_worldPoints);
					_worldPoints->dirty();

					pushfeaturePoint(_featureNodePoly,_worldPoints->back(),MOUSEDOWNTYPE::LEFTCLICK);

					_lmouseDown = false;
				}

				rightattempt = 
					ea.getEventType() == osgGA::GUIEventAdapter::RELEASE &&
					_rmouseDown;

				if (rightattempt && getMapNode())
				{
					popfeaturePoint(_featureNodePoly,MOUSEDOWNTYPE::RIGHTCLICK);
					_rmouseDown=false;
					
				}
				else if (
					ea.getEventType() == osgGA::GUIEventAdapter::PUSH &&
					ea.getModKeyMask() == 0 &&
					ea.getButtonMask() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON
					)
				{
					_lmouseDown = true;
					_mouseDownX = ea.getX();
					_mouseDownY = ea.getY();
				}
				else if (
					ea.getEventType() == osgGA::GUIEventAdapter::PUSH &&
					ea.getModKeyMask() == 0 &&
					ea.getButtonMask() == osgGA::GUIEventAdapter::RIGHT_MOUSE_BUTTON
					)
				{
					_rmouseDown = true;
				}
				return handled;
			}
		public:
			virtual void initQueryHandler()
			{
				_rmouseDown=false;
				_lmouseDown=false;
				_dbmouseDown = false;

				_worldPoints = new osg::Vec3dArray;
				_llhPoints = new osg::Vec3dArray;


				osg::ref_ptr<osgEarth::Symbology::Polygon> poly = new osgEarth::Symbology::Polygon();    
				osg::ref_ptr<Feature> feature = new Feature(poly, _mapNode->getMapSRS());
				_featureNodePoly = new osgEarth::Annotation::FeatureNode(feature );  
				_featureNodePoly->setStyle(GeoGlobe::GeoVector::GEOVectorHighlightCommom::buildStyle(osgEarth::Symbology::Color::Red,5.0));
				_root->addChild(_featureNodePoly);
				
			}
            //获取最终的拾取多边形
			virtual bool getQueryPolygon(//¹¹ÔìµÄ²éÑ¯¶à±ßÐÎÓë¼ª°ÂÍ¼ÐÎÏàÍ¬£¬×îºóÒ»¸öµãÓëµÚÒ»¸öÏàÍ¬
				osg::Vec3dArray* worldPoints,
				osg::Vec3dArray* llhPoints
				)
			{
				if (worldPoints->size()<1)
				{
					return false;
				}
				//get the lat and lon querypolygon
				for (osg::Vec3dArray::iterator itr = worldPoints->begin();
					itr!=worldPoints->end();
					itr++)
				{
					osg::Vec3d& pt=*(itr);
					GeoPoint tempt;
					tempt.fromWorld(_mapNode->getMapSRS(),pt);
					llhPoints->push_back(tempt.vec3d());
				}
				osg::Vec3d pt = *(llhPoints->rbegin());
				if (*(llhPoints->begin())!=pt)
				{
					llhPoints->push_back(*(llhPoints->begin()));
				}
				return true;
			}

            //窗口坐标转换为世界坐标
			virtual void MousepstoWorldps(
				osgViewer::View* view,
				osg::Vec2f& mousePoints,
				osg::Vec3dArray* worldPoints
				)
			{
				osg::Vec2f pt = mousePoints;
				if (pt.x()<0)
				{
					pt.x()=0;
				}
				if (pt.y()<0)
				{
					pt.y()=0;
				}
				osgUtil::LineSegmentIntersector::Intersections hits;
				if (view->computeIntersections(pt.x(),pt.y(),hits))
				{
					worldPoints->push_back(hits.begin()->getWorldIntersectPoint());
				}
				return;
			}
			//向拾取多边形中加点
			virtual void pushfeaturePoint(
				osgEarth::Annotation::FeatureNode* featurenode,
				osg::Vec3d& wpt,
				MOUSEDOWNTYPE mtype)
			{
				Feature* feature = featurenode->getFeature();
				if ( feature )            
				{
					if (mtype == MOUSEDOWNTYPE::LEFTCLICK)//continue choose the point
					{
						GeoPoint featurePoint;
						featurePoint.fromWorld( feature->getSRS(),  wpt);
						feature->getGeometry()->push_back(featurePoint.vec3d()); 
						featurenode->init();
					}
					if (mtype == MOUSEDOWNTYPE::RIGHTCLICK)//end choose
					{
						
					}
				}

			}
			//拾取多边形减少点的个数
			virtual void popfeaturePoint(
				osgEarth::Annotation::FeatureNode* featurenode,
				MOUSEDOWNTYPE mtype)
			{
				if (mtype == MOUSEDOWNTYPE::LEFTCLICK)//continue choose the point
				{
					
				}
				if (mtype == MOUSEDOWNTYPE::RIGHTCLICK)//back
				{
					Feature* feature = featurenode->getFeature();

					if ( feature )  
					{
						 feature->getGeometry()->pop_back(); 
						 featurenode->init();
					}
				}

			}
			//获取拾取多边形的包围盒
			virtual void getBoundBox(osg::Vec3dArray* llhPoints,osgEarth::Bounds& bds)
			{
				double xmin=DBL_MAX;
				double ymin=DBL_MAX;
				double xmax=-DBL_MAX;
				double ymax=-DBL_MAX;
				for (osg::Vec3dArray::iterator itr=llhPoints->begin();
					itr!=llhPoints->end();
					itr++)
				{
					osg::Vec3d& pt=*(itr);
					if (pt.x()<xmin)
					{
						xmin=pt.x();
					}
					if (pt.y()<ymin)
					{
						ymin=pt.y();
					}
					if (pt.x()>xmax)
					{
						xmax=pt.x();
					}
					if (pt.y()>ymax)
					{
						ymax=pt.y();
					}
				}
				bds.set(xmin, ymin, -DBL_MAX, xmax, ymax, DBL_MAX);
				return;
			}

			//do the intersect test

			virtual ~GEOVectorQuerybyPolygonHandler()
			{
				
			}

			virtual void addCallback(VectorQueryCallback* cb)
			{
				if (cb)
				{
					_vqcallbacks.push_back(cb);
				}
			}
			
		public:
			osg::ref_ptr<osg::Group> _root;
			osg::observer_ptr<MapNode> _mapNode;
			bool _lmouseDown,_rmouseDown,_dbmouseDown;
			float _mouseDownX,_mouseDownY;

			
			osg::ref_ptr<osg::Vec3dArray> _worldPoints;
			osg::ref_ptr<osg::Vec3dArray> _llhPoints;//ËµÃ÷£¬²éÑ¯¶à±ßÐÎÓë¼ª°ÂµÄ¶à±ßÐÎ¹¹ÔìÏàÍ¬£¬×îºóÒ»¸öµãÓëµÚÒ»¸öµãÏàÍ¬£¬ÓëWFS·þÎñ²»Í¬£¬WFS·þÎñ¶à±ßÐÎ×îºóÒ»¸öµãÓëµÚÒ»¸ö²»Í¬
			
			
			osg::ref_ptr<osgEarth::Annotation::FeatureNode> _featureNodePoly;

			typedef std::vector<osg::observer_ptr<VectorQueryCallback>> VectorQueryCallbacks;
			VectorQueryCallbacks _vqcallbacks;
		};//class virtual handler

		//本地矢量数据的多边形查询类
		class GeoVecFCSQuerybyPolyHandler : public GEOVectorQuerybyPolygonHandler
		{
		public://handle
			GeoVecFCSQuerybyPolyHandler(std::string xmlPath,osg::Group* root,MapNode* mapNode,
				VectorQueryCallback* callbackToAdd=0L);
			~GeoVecFCSQuerybyPolyHandler()
			{
				if (_geoFeaClasses)
				{
					delete[] _geoFeaClasses;
				}
			}
			 virtual bool handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa );

		public://xmlPath
			bool init(std::string xmlPath);

			void QueryInSqlite(osg::Vec3dArray* llhPoints,std::vector<AttributeTable>& attrTables);
			void createAttributeTable(Config fields,GEOFeatureClass* gfc,int oid,osgEarth::Features::AttributeTable& attr);
			void highlightVector(std::vector<int>& oids,GEOFeatureClass* geoFeaClass,osg::Group* root,MapNode* mapNode);
			void getIntersectVectors(osg::Vec3dArray* llhPoints,std::vector<int>& oids,GEOFeatureClass* geoFeaClass);
		protected:
			std::string _xmlPath;
			bool _xmlValid;
			GEOFeatureClass* _geoFeaClasses;
			unsigned _dataCount;
			std::vector<osgEarth::Features::AttributeTable> _attributeTables;
		};

		//wfs矢量服务要素多边形查询类
		class GeoVecWFSQuerybyPolyHandler : public GEOVectorQuerybyPolygonHandler
		{
		public:
			GeoVecWFSQuerybyPolyHandler(
				const GeoGlobe::GeoVector::GEOWFSFeatureOptions& options,
				osg::Group* root,MapNode* mapNode,
				VectorQueryCallback* callbackToAdd=0L);
			~GeoVecWFSQuerybyPolyHandler()
			{
				if (_gmlFeaClass)
				{
					delete _gmlFeaClass;
				}
			}
			virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);
		public:

			bool getQueryResponseXML(osg::Vec3dArray* llhPoints,std::string& cachePath);
			std::string createWFSQueryURL(osg::Vec3dArray* llhPoints);
			std::string createOGCFilter(osg::Vec3dArray* llhPoints);
			void saveResponse(const std::string& buffer,const std::string& filename);
			void highlightVector(GEOWFSFeatureClass* gmlFeaClass);
			void createAttributeTable(GEOWFSFeatureClass* gmlFeaClass,osgEarth::Features::AttributeTable& attrs);

		public:
			std::string _xmlqcPath;
			std::string _wfsUrl;
			std::string _typeName;
			GEOWFSFeatureClass* _gmlFeaClass;
			std::vector<osgEarth::Features::AttributeTable> _attributeTables;
		};

		class GeoVecFCSQuerybyPointHandler : public GeoVecFCSQuerybyPolyHandler
		{
		public://handle
			GeoVecFCSQuerybyPointHandler(std::string xmlPath,osg::Group* root,MapNode* mapNode,
				VectorQueryCallback* callbackToAdd=0L);
			~GeoVecFCSQuerybyPointHandler()
			{
			}
			virtual bool handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa );

			float _dis;//µã²éÑ¯Ê±µÄ¾àÀëÏÞ¶¨
		};

		
		/////////////////////////////---------------------------------------

		//将属性值读出
	    class VectorReadoutCallback : public GEOVectorQuerybyPolygonHandler::VectorQueryCallback
	{
	public:
		VectorReadoutCallback( osgEarth::Util::Controls::Container* container );

	public:
		virtual void onHit(std::vector<AttributeTable>& tables,const EventArgs& args);

		virtual void onMiss( const EventArgs& args );

	protected:
		void clear();
		osgEarth::Util::Controls::Grid* _grid;

		/** dtor */
		virtual ~VectorReadoutCallback() { }
	};
	}//namespace geovector
}



#endif// OSGEARTH_GEOVECTORQUERYBYPOLYGON_QUERY_TOOL_H