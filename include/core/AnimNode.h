/*!
 * File AnimNode.h
 */


#pragma once

#include <string>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <iostream>
#include <common/Utils.h>
#include <pods/pods.h>
#include <core/Transform.h>


namespace hpms
{
    class AnimNode : public HPMSObject
    {
    private:
        std::vector<AnimNode> children;
        std::vector<Transform> transformations;
        std::string name;
        AnimNode* parent;

    public:

        PODS_SERIALIZABLE(
                1,
                PODS_OPT(children),
                PODS_OPT(transformations),
                PODS_OPT(name),
                PODS_OPT(*parent)
        );

        AnimNode()
        {}

        AnimNode(std::string pname, AnimNode* pparent) : name(pname), parent(pparent)
        {

        }


        inline void AddTransform(const glm::mat4 mat)
        {
            transformations.push_back(mat);
        }

        inline const std::vector<AnimNode>& GetChildren() const
        {
            return children;
        }

        inline void AddChild(const AnimNode& node)
        {
            children.push_back(node);
        }

        inline void SetChildren(const std::vector<AnimNode>& children)
        {
            AnimNode::children = children;
        }

        inline const std::vector<Transform>& GetTransformations() const
        {
            return transformations;
        }

        inline void SetTransformations(const std::vector<Transform>& transformations)
        {
            AnimNode::transformations = transformations;
        }

        inline const std::string& GetName() const
        {
            return name;
        }

        inline void SetName(const std::string& name)
        {
            AnimNode::name = name;
        }

        inline AnimNode* GetParent() const
        {
            return parent;
        }

        inline void SetParent(AnimNode* parent)
        {
            AnimNode::parent = parent;
        }

        inline const std::string Name() const

        override
        {
            return "AnimNode";
        }

        static AnimNode Find(const std::string& name, const AnimNode& parent);

        static unsigned int GetAnimationFrames(const AnimNode& parent);

        static glm::mat4 GetParentTransforms(AnimNode* node, unsigned int framePos);

    };
}