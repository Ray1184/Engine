/*!
 * File AdvModelItem.h
 */

#pragma once

#include <unordered_map>
#include <core/StdModelItem.h>
#include <core/Animation.h>
#include <glm/mat4x4.hpp>


namespace hpms
{
    class AdvModelItem : public StdModelItem
    {
    private:

        std::string key;
        std::vector<Animation> animations;
        std::vector<std::string> boneNames;


    public:

        PODS_SERIALIZABLE(
                1,
                PODS_OPT(meshes),
                PODS_OPT(animations)

        );


        AdvModelItem(const std::string& key) : key(key)
        {}

        AdvModelItem()
        {
            char buffer[32];
            hpms::RandomString(buffer, 32);
            key = std::string(buffer);
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


