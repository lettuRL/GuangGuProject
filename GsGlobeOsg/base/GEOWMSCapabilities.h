/* -*-c++-*- */
/* osgEarth - Dynamic map generation toolkit for OpenSceneGraph
* Copyright 2008-2014 Pelican Mapping
* http://osgearth.org
*
* osgEarth is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

#ifndef OSGEARTHUTIL_GEO_WMS_H
#define OSGEARTHUTIL_GEO_WMS_H 1

#include <osgEarthUtil/Common>
#include <osg/Referenced>
#include <osg/ref_ptr>
#include <osgEarth/Common>

#include <osgDB/ReaderWriter>
#include <osg/Version>
#include <osgDB/Options>


#include <string>
#include <vector>

namespace GeoGlobe 
{
    /**
    * A WMS Style
    */
    class  GEOWMSStyle : public osg::Referenced
    {
    public:
        GEOWMSStyle();
        GEOWMSStyle(const std::string& name, const std::string& title);

        /** dtor */
        virtual ~GEOWMSStyle() { }

        /**
        *Gets the name of the style
        */
        const std::string& getName() {return _name;}

        /**
        *Sets the name of the style
        */
        void setName(const std::string &name) {_name = name;}

        /**
        *Gets the title of the style
        */
        const std::string& getTitle() {return _title;}

        /**
        *Sets the title of the style
        */
        void setTitle(const std::string &title) {_title = title;}
        
    protected:
        std::string _name;
        std::string _title;
    };

    /**
    *A WMS layer
    */
    class GEOWMSLayer : public osg::Referenced
    {
    public:
        GEOWMSLayer();

        /** dtor */
        virtual ~GEOWMSLayer() { }

        /**
        *Gets the name of the layer
        */
        const std::string& getName() {return _name;}

        /**
        *Sets the name of the layer
        */
        void setName(const std::string &name) {_name = name;}

        /**
        *Gets the title of the layer
        */
        const std::string& getTitle() {return _title;}

        /**
        *Sets the title of the layer
        */
        void setTitle(const std::string &title) {_title = title;}

        /**
        *Gets the abstract of the layer
        */
        const std::string& getAbstract() {return _abstract;}

        /**
        *Sets the abstract of the layer
        */
        void setAbstract(const std::string &abstract) {_abstract = abstract;}

        /**
        *Gets the lat lon extents of the layer
        */
        void getLatLonExtents(double &minLon, double &minLat, double &maxLon, double &maxLat);

        /**
        *Sets the lat lon extents of the layer
        */
        void setLatLonExtents(double minLon, double minLat, double maxLon, double maxLat);

        /**
        *Gets the extents of the layer
        */
        void getExtents(double &minX, double &minY, double &maxX, double &maxY);

        /**
        *Sets the extents of the layer
        */
        void setExtents(double minX, double minY, double maxX, double maxY);


        /**A list of Styles*/
        typedef std::vector<GEOWMSStyle> StyleList;

        /**
        *Gets this Layer's list of defined Styles
        */
        StyleList& getStyles() {return _styles;}

        /**A list of spatial references*/
        typedef std::vector<std::string> SRSList;

        /**
        *Gets this Layer's list of spatial references
        */
        SRSList& getSpatialReferences() {return _spatialReferences;}

        /**A list of Layers*/
        typedef std::vector< osg::ref_ptr<GEOWMSLayer> > LayerList;

        /**
        *Gets this Layer's list of child Layers
        */
        LayerList& getLayers() {return _layers;}

        /**
        *Gets this Layer's parent layer
        */
        GEOWMSLayer* getParentLayer() {return _parentLayer;}

        /**
        *Sets this Layer's parent layer
        */
        void setParentLayer( GEOWMSLayer* layer ) {_parentLayer = layer;}

        /**
        *Finds the child Layer with the given name.
        *@returns
        *       The Layer with the given name or NULL if not found.
        */
        GEOWMSLayer* getLayerByName(const std::string &name);
    protected:
        std::string _name;
        std::string _title;
        std::string _abstract;
        double _minLon, _minLat, _maxLon, _maxLat;
        double _minX, _minY, _maxX, _maxY;
        StyleList _styles;
        SRSList _spatialReferences;

        LayerList _layers;
        GEOWMSLayer* _parentLayer;
    };

    /**
    *WMS Capabilities
    */
    class GEOWMSCapabilities : public osg::Referenced
    {
    public:
        GEOWMSCapabilities();

        /** dtor */
        virtual ~GEOWMSCapabilities() { }

        /**
        *Gets the WMS capabilities version
        */
        const std::string& getVersion() {return _version;}

        /**
        *Sets the WMS capabilities version
        */
        void setVersion(const std::string& version) {_version = version;}

        /**A list of supported formats*/
        typedef std::vector<std::string> FormatList;

        /**
        *Gets the list of supported formats
        */
        FormatList& getFormats() {return _formats;}

        /**
        *Gets the Layer's for the Capabilities.
        */
        GEOWMSLayer::LayerList& getLayers() {return _layers;}

        /**
        *Suggests an extension to use for WMS layers defined for the service.
        *This function will analyze the list of formats contained in the Capabilities request
        *and recommend the first format that has an OpenSceneGraph ReaderWriter that can support
        *it's extension.
        *@returns
        *       The suggested extension.
        */
        std::string suggestExtension();

        /**
        *Finds the child Layer with the given name.
        *@returns
        *       The Layer with the given name or NULL if not found.
        */
        GEOWMSLayer* getLayerByName(const std::string &name);

    protected:
        FormatList _formats;
        GEOWMSLayer::LayerList _layers;
        std::string _version;
    };

    /*
    * Reads Capabilities from a URL or file
    */
    class GEOWMSCapabilitiesReader
    {
    public:
        static GEOWMSCapabilities* read( const std::string &location, const osgDB::ReaderWriter::Options *options=NULL );
        static GEOWMSCapabilities* read( const std::string &url, const std::string &location,const osgDB::ReaderWriter::Options* options=NULL);
		static GEOWMSCapabilities* read( std::istream &in );
    private:
        GEOWMSCapabilitiesReader(){}
        GEOWMSCapabilitiesReader(const GEOWMSCapabilitiesReader &cr){}

        /** dtor */
        virtual ~GEOWMSCapabilitiesReader() { }
    };

} // namespace GeoGlobe

#endif //OSGEARTHUTIL_GEO_WMS_H
