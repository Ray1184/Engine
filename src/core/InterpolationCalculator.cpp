/*!
 * File InterpolationCalculator.cpp
 */

#include <core/InterpolationCalculator.h>
#include <cmath>
#include <glm/ext.hpp>
#include <common/Utils.h>

void hpms::InterpolationCalculator::Calculate(std::vector<Animation>* anims, int fromFrameIndex, int toFrameIndex, int iterations)
{
    if (anims->empty())
    {
        return;
    }
    if (anims->size() == 1)
    {
        anims->emplace_back();
    }

    Animation baseAnim = anims->at(0);
    Animation interpolationAnim = anims->at(1);
    std::vector<Frame> interpolatedFrames;


    Frame fromFrame = baseAnim.GetFrames()[fromFrameIndex];
    Frame toFrame = baseAnim.GetFrames()[toFrameIndex];


    int length = pow(2, iterations) + 1;
    interpolatedFrames.reserve(length);
    interpolatedFrames[0] = fromFrame;
    interpolatedFrames[length - 1] = toFrame;

    CalculateIteration(interpolatedFrames, fromFrame, toFrame, 0, iterations, 0, length - 1);
    interpolationAnim.SetFrames(interpolatedFrames);
}

void hpms::InterpolationCalculator::CalculateIteration(std::vector<Frame>& frames, const Frame& fromFrame, const Frame& toFrame, int iteration, int iterations, int indexFrom, int indexTo)
{
    if (iterations == 0)
    {
        LOG_ERROR("At least 1 iteration it's needed for linear interpolation.");
    }
    Frame interpolated;
    for (int i = 0; i < MAX_JOINTS; i++)
    {
        glm::mat4 t1 = fromFrame.frameTransformations[i].jointMatrix;
        glm::mat4 t2 = toFrame.frameTransformations[i].jointMatrix;
        glm::mat4 t3 = Interpolate(t1, t2, 1);
        FrameTransform ft;
        ft.jointMatrix = t3;
        interpolated.frameTransformations.push_back(ft);
    }
    int pos = (indexFrom / indexTo) + 1;
    frames[pos] = interpolated;

    if (iteration <= iterations)
    {
        CalculateIteration(frames, fromFrame, interpolated, iteration + 1, iterations, indexFrom, pos);
        CalculateIteration(frames, interpolated, toFrame, iteration + 1, iterations, pos, indexTo);
    }
}

glm::mat4 hpms::InterpolationCalculator::Interpolate(glm::mat4& m1, glm::mat4& m2, float time)
{
    glm::quat rot0 = glm::quat_cast(m1);
    glm::quat rot1= glm::quat_cast(m2);

    glm::quat finalRot = glm::slerp(rot0, rot1, time);
    glm::mat4 finalMat = glm::mat4_cast(finalRot);

    finalMat[3] = m1[3] * (1 - time) + m2[3] * time;

    return finalMat;
}
