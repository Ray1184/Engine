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
    class AdvModelItem : public StdModelItem
    {
    private:

        std::string key;
        std::vector<Animation> animations;
        std::vector<std::string> boneNames;
        std::unordered_map<std::string, int> bonesIndexByName;
        std::unordered_map<std::string, hpms::SceneNode*> animationNodes;
        int currentFrameIndex;
        bool initialized;


    public:

        PODS_SERIALIZABLE(
                1,
                PODS_OPT(meshes),
                PODS_OPT(animations),
                PODS_OPT(boneNames)

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

        const std::vector<std::string>& GetBoneNames() const
        {
            return boneNames;
        }

        void SetBoneNames(const std::vector<std::string>& boneNames)
        {
            AdvModelItem::boneNames = boneNames;
        }

        inline const std::string Name() const override
        {
            return "AdvModelItem";
        }


    };
}


