/*!
 * File Animation.h
 */

#pragma once

#include <vector>
#include <glm/mat4x4.hpp>
#include <string>
#include <pods/pods.h>
#include <core/Transform.h>
#include <common/HPMSObject.h>

#define MAX_JOINTS 150

namespace hpms
{


    struct Frame
    {

        std::vector<Transform> frameTransformations;

        Frame()
        {
            frameTransformations.reserve(MAX_JOINTS);
        }

        PODS_SERIALIZABLE(
                1,
                PODS_OPT(frameTransformations)
        )


    };


    class Animation : public HPMSObject
    {

    public:

        PODS_SERIALIZABLE(
                1,
                PODS_OPT(frames),
                PODS_OPT(name),
                PODS_OPT(duration)
        );


        Animation() :
                name(std::string()),
                frames(0),
                duration(0)
        {}

        Animation(std::string pname, std::vector<Frame>& pframes, double pduration) :
                name(pname),
                frames(pframes),
                duration(pduration)
        {}

        inline const std::vector<Frame>& GetFrames() const
        {
            return frames;
        }

        inline void SetFrames(const std::vector<Frame>& frames)
        {
            Animation::frames = frames;
        }

        inline const std::string& GetName() const
        {
            return name;
        }

        inline void SetName(const std::string& name)
        {
            Animation::name = name;
        }

        inline double GetDuration() const
        {
            return duration;
        }

        inline void SetDuration(double duration)
        {
            Animation::duration = duration;
        }

        inline const Frame* GetFrameWithIndex(unsigned int index) const
        {
            return &frames[index];
        }

        inline const std::string Name() const override
        {
            return "Animation";
        }



    private:
        std::vector<Frame> frames;
        std::string name;
        double duration;

    };
}


