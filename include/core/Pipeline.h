/*!
 * File Pipeline.h
 */

#pragma once

#include <core/gl/GLWindow.h>
#include <core/Scene.h>
#include <core/Camera.h>
#include <core/gl/GLRenderer.h>
#include <core/FrameBuffer.h>

namespace hpms
{
    class Pipeline : public HPMSObject
    {
    public:
        virtual void Init(Window* window, Scene* scene, Renderer* renderer, FrameBuffer* frameBuffer) = 0;

        virtual void
        Render(Window* window, Scene* scene, Camera* camera, Renderer* renderer, FrameBuffer* frameBuffer) = 0;

        virtual void Cleanup(Scene* scene, Renderer* renderer, FrameBuffer* frameBuffer) = 0;
    };
}
