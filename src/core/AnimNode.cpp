/*!
 * File AnimNode.cpp
 */

#include <core/AnimNode.h>

hpms::AnimNode* hpms::AnimNode::Find(const std::string& name, hpms::AnimNode* parent)
{
    AnimNode* res = nullptr;
    if (parent->GetName().compare(name) == 0)
    {
        res = parent;
    } else
    {
        for (AnimNode* child : parent->GetChildren())
        {
            res = Find(name, child);
            if (res != nullptr)
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

unsigned int hpms::AnimNode::GetAnimationFrames(hpms::AnimNode* parent)
{
    unsigned int numFrames = parent->GetTransformations().size();
    for (AnimNode* child : parent->GetChildren())
    {
        unsigned int childFrames = GetAnimationFrames(child);
        numFrames = std::max(numFrames, childFrames);
    }
    return numFrames;
}
