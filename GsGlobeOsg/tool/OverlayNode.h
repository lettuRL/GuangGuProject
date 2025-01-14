/* -*-c++-*- OpenSceneGraph - Copyright (C) 1998-2006 Robert Osfield
 *
 * This library is open source and may be redistributed and/or modified under
 * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or
 * (at your option) any later version.  The full license is in LICENSE file
 * included with this distribution, and on the openscenegraph.org website.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * OpenSceneGraph Public License for more details.
*/

#ifndef OSGSIM_OVERLAYNODE
#define OSGSIM_OVERLAYNODE 1

#include <osg/buffered_value>
#include <osg/Camera>
#include <osg/Texture2D>
#include <osg/TexGenNode>
#include <osg/Geode>

#include <osgUtil/CullVisitor>

namespace GeoGlobe {

/** OverlayNode is for creating texture overlays on scenes, with the overlay texture being generated
  * by pre rendering an Overlay Subgraph to a texture, then projecting this resulting texture on the scene.*/
class  OverlayNode : public osg::Group
{
    public :

        enum OverlayTechnique
        {
            OBJECT_DEPENDENT_WITH_ORTHOGRAPHIC_OVERLAY,
            VIEW_DEPENDENT_WITH_ORTHOGRAPHIC_OVERLAY,
            VIEW_DEPENDENT_WITH_PERSPECTIVE_OVERLAY
        };

		void setProjectDirection(osg::Vec3d viewDirection);

        OverlayNode(OverlayTechnique technique=OBJECT_DEPENDENT_WITH_ORTHOGRAPHIC_OVERLAY);

        OverlayNode(const OverlayNode& es, const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY);

        META_Node(osgSim, OverlayNode);

        virtual void traverse(osg::NodeVisitor& nv);


        void setOverlayTechnique(OverlayTechnique technique);
        OverlayTechnique getOverlayTechnique() const { return _overlayTechnique; }

        /** Set the implementation to be used when creating the overlay texture. */
        void setRenderTargetImplementation(osg::Camera::RenderTargetImplementation impl);

        /** Set the overlay subgraph which will be rendered to texture.*/
        void setOverlaySubgraph(osg::Node* node);
		void removeOverlaySubgraph(osg::Node* node);

        template<class T> void setOverlaySubgraph(const osg::ref_ptr<T>& node) { setOverlaySubgraph(node.get()); }
		template<class T> void removeOverlaySubgraph(const osg::ref_ptr<T>& node) { removeOverlaySubgraph(node.get()); }

        /** Get the overlay subgraph which will be rendered to texture.*/
        osg::Node* getOverlaySubgraph() { return _overlaySubgraph.get(); }

        /** Get the const overlay subgraph which will be render to texture.*/
        const osg::Node* getOverlaySubgraph() const { return _overlaySubgraph.get(); }


        /** Inform the OverlayNode that the overlay texture needs to be updated.*/
        void dirtyOverlayTexture();

        /** Set whether the OverlayNode should update the overlay texture on every frame.*/
        void setContinuousUpdate(bool update) { _continuousUpdate = update; }

        /** Get whether the OverlayNode should update the overlay texture on every frame.*/
        bool getContinuousUpdate() const { return _continuousUpdate; }

        /** Set the base height that the overlay subgraph will be projected down to.
          * Normally you'll set this to just below ground level, if you set it too high
          * then the overlay texture can end up being clipped in certain viewing directions,
          * while if its too low then there will be a limit to how close you can get to the
          * terrain before pixaltion becomes an issue.*/
        void setOverlayBaseHeight(double baseHeight) { _overlayBaseHeight = baseHeight; }

        /** Get the base height that the overlay subgraph will be projected down to.*/
        double getOverlayBaseHeight() const { return _overlayBaseHeight; }

        /** Set the clear color to use when rendering the overlay subgraph.*/
        void setOverlayClearColor(const osg::Vec4& color) { _overlayClearColor = color; }

        /** Get the clear color to use when rendering the overlay subgraph.*/
        const osg::Vec4& getOverlayClearColor() const { return _overlayClearColor; }

        /** Set the TexEnv mode used to combine the overlay texture with the base color/texture of the OverlayNode's decorate subgraph.*/
        void setTexEnvMode(GLenum mode);

        /** Get the TexEnv mode used to combine the overlay texture with the base color/texture of the OverlayNode's decorate subgraph.*/
        GLenum getTexEnvMode() const { return _texEnvMode; }

        /** Set the texture unit that the texture should be assigned to.*/
        void setOverlayTextureUnit(unsigned int unit);

        /** Get the texture unit that the texture should be assigned to.*/
        unsigned int getOverlayTextureUnit() const { return _textureUnit; }

        /** Set the texture size hint. The size hint is used to request a texture of specified size.*/
        void setOverlayTextureSizeHint(unsigned int size);

        /** Get the texture size hint.*/
        unsigned int getOverlayTextureSizeHint() const { return _textureSizeHint; }


        /** Set whether to use a mutex to ensure ref() and unref() are thread safe.*/
        virtual void setThreadSafeRefUnref(bool threadSafe);

        /** Resize any per context GLObject buffers to specified size. */
        virtual void resizeGLObjectBuffers(unsigned int /*maxSize*/);

        /** If State is non-zero, this function releases any associated OpenGL objects for
           * the specified graphics context. Otherwise, releases OpenGL objexts
           * for all graphics contexts. */
        virtual void releaseGLObjects(osg::State* = 0) const;

    protected :

        virtual ~OverlayNode() {}

        void init();
        void init_OBJECT_DEPENDENT_WITH_ORTHOGRAPHIC_OVERLAY();
        void init_VIEW_DEPENDENT_WITH_ORTHOGRAPHIC_OVERLAY();
        void init_VIEW_DEPENDENT_WITH_PERSPECTIVE_OVERLAY();

        void traverse_OBJECT_DEPENDENT_WITH_ORTHOGRAPHIC_OVERLAY(osg::NodeVisitor& nv);
        void traverse_VIEW_DEPENDENT_WITH_ORTHOGRAPHIC_OVERLAY(osg::NodeVisitor& nv);
        void traverse_VIEW_DEPENDENT_WITH_PERSPECTIVE_OVERLAY(osg::NodeVisitor& nv);


        void updateMainSubgraphStateSet();

        typedef osg::buffered_value< int > TextureObjectValidList;

        mutable TextureObjectValidList _textureObjectValidList;

        OverlayTechnique _overlayTechnique;


        // overlay subgraph is render to a texture
        osg::ref_ptr<osg::Node>         _overlaySubgraph;

        osg::ref_ptr<osg::StateSet>     _overlayStateSet;
        osg::ref_ptr<osg::StateSet>     _mainStateSet;

        // texture to render to, and to read from.
        GLenum                          _texEnvMode;
        unsigned int                    _textureUnit;
        unsigned int                    _textureSizeHint;
        osg::Vec4                       _overlayClearColor;

        bool                            _continuousUpdate;
        double                          _overlayBaseHeight;
        bool                            _updateCamera;

        osg::Camera::RenderTargetImplementation _renderTargetImpl;

        struct OverlayData : public osg::Referenced
        {

            void setThreadSafeRefUnref(bool threadSafe);
            void resizeGLObjectBuffers(unsigned int maxSize);
            void releaseGLObjects(osg::State* state= 0) const;

            osg::ref_ptr<osg::Camera>       _camera;
            osg::ref_ptr<osg::StateSet>     _overlayStateSet;
            osg::ref_ptr<osg::StateSet>     _mainSubgraphStateSet;
            osg::ref_ptr<osg::TexGenNode>   _texgenNode;
            osg::ref_ptr<osg::Texture2D>    _texture;
            osg::Polytope                   _textureFrustum;
            osg::ref_ptr<osg::Geode>        _geode;

            osg::ref_ptr<osg::Program>      _mainSubgraphProgram;

            osg::ref_ptr<osg::Uniform>      _y0;
            osg::ref_ptr<osg::Uniform>      _lightingEnabled;
        };

        typedef std::map<osgUtil::CullVisitor*, osg::ref_ptr<OverlayData> > OverlayDataMap;

        OpenThreads::Mutex              _overlayDataMapMutex;
        OverlayDataMap                  _overlayDataMap;
		osg::Vec3d						m_vecViewDirection;
        OverlayNode::OverlayData* getOverlayData(osgUtil::CullVisitor* cv);

};

}

#endif
