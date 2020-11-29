/*!
 * File AdvModelItem.h
 */

#pragma once

#include <unordered_map>
#include <core/StdModelItem.h>
#include <core/Animation.h>
#include <core/items/SceneNode.h>
#include <core/AnimNode.h>


namespace hpms
{
    class AdvModelItem : public StdModelItem
    {
    private:

        std::string key;
        std::vector<Animation> animations;
        AnimNode* armatureNode;


    public:

        PODS_SERIALIZABLE(
                1,
                PODS_OPT(meshes),
                PODS_OPT(animations)

        );

        AdvModelItem(const std::string& key) : key(key)
        {}

        AdvModelItem() : armatureNode(armatureNode)
        {
            char buffer[32];
            hpms::RandomString(buffer, 32);
            key = std::string(buffer);
        }

        virtual ~AdvModelItem()
        {
            hpms::SafeDelete(armatureNode);
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

        inline AnimNode* GetArmatureNode() const
        {
            return armatureNode;
        }

        inline void SetArmatureNode(AnimNode* armatureNode)
        {
            AdvModelItem::armatureNode = armatureNode;
        }

        inline const std::string Name() const override
        {
            return "AdvModelItem";
        }



    };
}


