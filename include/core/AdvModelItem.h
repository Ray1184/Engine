/*!
 * File AdvModelItem.h
 */

#pragma once

#include <unordered_map>
#include <core/StdModelItem.h>
#include <core/Animation.h>
#include <glm/mat4x4.hpp>
#include <core/SceneNode.h>


namespace hpms
{
    struct ArmaturePart
    {
        std::string boneName;

        PODS_SERIALIZABLE(
                1,
                PODS_OPT(boneName)
        );
    };
    class AdvModelItem : public StdModelItem
    {
    private:

        std::string key;
        std::vector<Animation> animations;
        std::vector<ArmaturePart> armatureParts;
        std::unordered_map<std::string, int> bonesIndexByName;
        std::unordered_map<std::string, hpms::SceneNode*> animationNodes;
        int currentFrameIndex;
        bool initialized;


    public:

        PODS_SERIALIZABLE(
                1,
                PODS_OPT(meshes),
                PODS_OPT(animations),
                PODS_OPT(armatureParts)

        );


        AdvModelItem(const std::string& key) : key(key), initialized(false)
        {}

        AdvModelItem() : initialized(false)
        {
            char buffer[32];
            hpms::RandomString(buffer, 32);
            key = std::string(buffer);
        }

        virtual ~AdvModelItem()
        {
            for (auto& entry : animationNodes)
            {
                hpms::SafeDelete(entry.second);
            }
        }

        void Init();

        void Update() const;

        inline SceneNode* GetAnimNodeByBoneName(const std::string& boneName)
        {
            return animationNodes[boneName];
        }

        inline const std::vector<Animation>& GetAnimations() const
        {
            return animations;
        }

        inline std::vector<Animation>* GetAnimationsPtr()
        {
            return &animations;
        }

        inline void SetAnimations(const std::vector<Animation>& animations)
        {
            AdvModelItem::animations = animations;
        }

        inline const Animation* GetAnimationWithIndex(unsigned int index) const
        {
            return &animations[index];
        }

        inline int GetCurrentFrameIndex() const
        {
            return currentFrameIndex;
        }

        inline void SetCurrentFrameIndex(int currentFrameIndex)
        {
            AdvModelItem::currentFrameIndex = currentFrameIndex;
        }

        const std::vector<ArmaturePart>& GetArmatureParts() const
        {
            return armatureParts;
        }

        void SetBoneNames(const std::vector<ArmaturePart>& armatureParts)
        {
            AdvModelItem::armatureParts = armatureParts;
        }

        inline const std::string Name() const override
        {
            return "AdvModelItem";
        }


    };
}


