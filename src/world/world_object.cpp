//
// Created by Max Grucella on 7/14/17.
//
#include "world_object.h"

#include "../windowing/box_types/sprite_area.h"
#include "../windowing/box_types/layer.h"

WorldObject::WorldObject(Layer* layer, SDL_Point* top_left, std::string path_to_asset)
{
  ground_ = new BoxOfSprite(path_to_asset, top_left);

  ground_->SetX(top_left->x);
  ground_->UnsafelySetY(top_left->y);
  ground_->SetRecHeight(16);
  ground_->SetRecWidth(16);

  ground_->SetClipHeight(16 * 6);
  ground_->SetClipWidth(16 * 6);


  layer->AddWindaBox(ground_);
}
