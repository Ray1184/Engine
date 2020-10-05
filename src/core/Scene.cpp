/*!
 * File Scene.cpp
 */

#include <core/Scene.h>

void hpms::Scene::AddRenderObject(hpms::RenderObject* obj)
{

    if (auto* node = dynamic_cast<SceneNode*>(obj))
    {

        for (Actor* actor : node->GetActorsList())
        {
            if (auto* entity = dynamic_cast<Entity*>(actor))
            {
                itemsMap[entity->GetModelItem()].push_back(entity);
            }
        }
        nodes.push_back(node);

    }

    if (auto* entity = dynamic_cast<Entity*>(obj))
    {

        itemsMap[entity->GetModelItem()].push_back(entity);

    }

    if (auto* pic = dynamic_cast<Picture*>(obj))
    {
        if (pic->GetMode() == PictureMode::FOREGROUND)
        {
            if (std::find(forePictures.begin(), forePictures.end(), pic) == forePictures.end())
            {
                forePictures.push_back(pic);
            }
        } else if (pic->GetMode() == PictureMode::BACKGROUND)
        {
            if (std::find(backPictures.begin(), backPictures.end(), pic) == backPictures.end())
            {
                backPictures.push_back(pic);
            }
            currentBackPicture = pic;
        } else if (pic->GetMode() == PictureMode::DEPTH_MASK)
        {
            if (std::find(depthPictures.begin(), depthPictures.end(), pic) == depthPictures.end())
            {
                depthPictures.push_back(pic);
            }
            currentDepthPicture = pic;
        }
    }

}
