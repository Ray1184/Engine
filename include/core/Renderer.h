/**
 * File Renderer.h
 */
#pragma once

#include <vector>
#include <functional>
#include <core/Mesh.h>
#include <core/AdvModelItem.h>
#include <core/Texture.h>
#include <core/Transformation.h>
#include <core/gl/GLShader.h>
#include <core/items/Entity.h>
#include <core/Camera.h>
#include <core/gl/GLWindow.h>


namespace hpms
{
    class Renderer : public HPMSObject
    {

    public:

        virtual void QuadMeshInit() = 0;

        virtual void MeshInit(const hpms::Mesh& mesh) = 0;

        virtual void
        ModelsDraw(const std::unordered_map<const AdvModelItem*, std::vector<Entity*>>& modelToEntitiesMap,
                   Shader* s, Camera* c, Window* w,
                   std::function<void(Entity*, Shader*, Camera*, Window* w)> pipelineCallback) = 0;

        virtual void QuadsDraw(const std::string& textureName) = 0;

        virtual void MeshCleanup(const hpms::Mesh& mesh) = 0;

        virtual void TextureInit(const hpms::Texture& text) = 0;

        virtual void TextureCleanup(const hpms::Texture& text) = 0;

        virtual void QuadMeshCleanup() = 0;

        virtual void ClearAllBuffers() = 0;

        virtual void ClearDepthBuffer() = 0;

    };
}
