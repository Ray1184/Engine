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


namespace hpms
{
    class AnimNode : public HPMSObject
    {
    private:
        std::vector<AnimNode*> children;
        std::vector<glm::mat4> transformations;
        std::string name;
        AnimNode* parent;

    public:


        AnimNode(std::string pname, AnimNode* pparent) : name(pname), parent(pparent)
        {

        }

        ~AnimNode()
        {
            for (AnimNode* child : children)
            {
                hpms::SafeDelete(child);
            }
        }

        inline void AddTransform(const glm::mat4 mat)
        {
            transformations.push_back(mat);
        }

        inline const std::vector<AnimNode*>& GetChildren() const
        {
            return children;
        }

        inline void AddChild(AnimNode* node)
        {
            children.push_back(node);
        }

        inline void SetChildren(const std::vector<AnimNode*>& children)
        {
            AnimNode::children = children;
        }

        inline const std::vector<glm::mat4>& GetTransformations() const
        {
            return transformations;
        }

        inline void SetTransformations(const std::vector<glm::mat4>& transformations)
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

        inline const std::string Name() const override
        {
            return "AnimNode";
        }

        static AnimNode* Find(const std::string& name, AnimNode* parent);

        static unsigned int GetAnimationFrames(AnimNode* parent)
        {
            unsigned int numFrames = parent->GetTransformations().size();
            for (AnimNode* child : parent->GetChildren())
            {
                unsigned int childFrames = GetAnimationFrames(child);
                numFrames = std::max(numFrames, childFrames);
            }
            return numFrames;
        }

        static glm::mat4 GetParentTransforms(AnimNode* node, unsigned int framePos)
        {
            if (node == nullptr)
            {
                return glm::mat4(1.0);

            }
            glm::mat4 parentTransform = GetParentTransforms(node->GetParent(), framePos);
            std::vector<glm::mat4> transformations = node->GetTransformations();


            glm::mat4 nodeTransform(1.0);
            unsigned int transfSize = transformations.size();
            if (framePos < transfSize)
            {
                nodeTransform = transformations.at(framePos);
            } else if (transfSize > 0)
            {
                nodeTransform = transformations.at(transfSize - 1);
            }
            glm::mat4 res = parentTransform * nodeTransform;
            return res;
        }
    };
}