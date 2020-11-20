/*!
 * File InterpolationCalculator.h
 */

#pragma once

#include <core/Animation.h>
#include <glm/glm.hpp>

namespace hpms
{
    class InterpolationCalculator
    {
        static void Calculate(std::vector<Animation>& anims, int fromFrameIndex, int toFrameIndex, int iterations);

        static void CalculateIteration(std::vector<Frame>& frames, const Frame& fromFrame, const Frame& toFrame, int iteration, int iterations, int indexFrom, int indexTo);

        static glm::mat4 Interpolate(glm::mat4& m1, glm::mat4& m2, float time);
    };
}



