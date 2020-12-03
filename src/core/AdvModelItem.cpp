/*!
 * File AdvModelItem.cpp
 */

#include <core/AdvModelItem.h>

void hpms::AdvModelItem::Init()
{
    if (!initialized)
    {
        initialized = true;
        unsigned int index = 0;
        for (auto& armaturePart : armatureParts)
        {
            bonesIndexByName[armaturePart] = index++;
            SceneNode* animNode = hpms::SafeNew<SceneNode>("ANIMNODE_" + armaturePart);
            animationNodes[armaturePart] = animNode;
        }
    }
}

void hpms::AdvModelItem::Update() const
{
    for (auto& entry : animationNodes)
    {
        int currentIndex = bonesIndexByName.at(entry.first);
        entry.second->SetWorldTransform(
                animations[currentIndex].GetFrames()[currentFrameIndex].frameTransformations[currentIndex].jointMatrix);
        entry.second->UpdateTree(false);
    }
}

