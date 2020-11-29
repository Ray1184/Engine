/*!
 * File AnimNode.cpp
 */

#include <core/AnimNode.h>

hpms::AnimNode hpms::AnimNode::Find(const std::string& name, const hpms::AnimNode& parent)
{
    AnimNode res("dummy", nullptr);
    if (parent.GetName() == name)
    {
        res = parent;
    } else
    {
        for (const AnimNode& child : parent.GetChildren())
        {
            res = Find(name, child);
            if (res.name != "dummy")
            {
                break;
            }
        }
    }
    return res;
}

glm::mat4 hpms::AnimNode::GetParentTransforms(hpms::AnimNode* node, unsigned int framePos)
{
    if (node == nullptr)
    {
        return glm::mat4(1.0);

    }
    glm::mat4 parentTransform = GetParentTransforms(node->GetParent(), framePos);
    std::vector<Transform> transformations = node->GetTransformations();


    glm::mat4 nodeTransform(1.0);
    unsigned int transfSize = transformations.size();
    if (framePos < transfSize)
    {
        nodeTransform = transformations.at(framePos).matrix;
    } else if (transfSize > 0)
    {
        nodeTransform = transformations.at(transfSize - 1).matrix;
    }
    glm::mat4 res = parentTransform * nodeTransform;
    return res;
}

unsigned int hpms::AnimNode::GetAnimationFrames(const hpms::AnimNode& parent)
{
    unsigned int numFrames = parent.GetTransformations().size();
    for (const AnimNode& child : parent.GetChildren())
    {
        unsigned int childFrames = GetAnimationFrames(child);
        numFrames = std::max(numFrames, childFrames);
    }
    return numFrames;
}
