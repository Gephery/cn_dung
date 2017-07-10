//
// Created by Max Grucella on 6/23/17.
//

#include "sprite_area.h"
#include "../texture_manager.h"

BoxOfSprite::BoxOfSprite(std::string path, SDL_Point* upper_left) : BaseBox(upper_left)
{
  SetTexture(TextureManager::LoadAsset(path, rect_));
  type_ = BOX_OF_SPRITE;
  clip_->w = rect_->w;
  clip_->h = rect_->h;
}

BoxOfSprite::~BoxOfSprite()
{
  Destroy();
}

