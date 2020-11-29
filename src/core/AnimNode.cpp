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
