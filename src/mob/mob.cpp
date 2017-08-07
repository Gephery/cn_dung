//
// Created by Max Grucella on 6/17/17.
//

#include "mob.h"

#include <iostream>
#include "../windowing/box_types/sprite_area.h"
#include "../windowing/box_types/box_of_text.h"
#include "../windowing/layer_manager.h"
#include "../windowing/box_types/layer.h"
#include "../windowing/winda.h"
#include "../events/repeat_event.h"
#include "../world/world_manager.h"
#include "point_of_contact.h"

const Uint8 TILE_SIZE = 16;
const Uint8 FRAME_PEF = 5;
const Uint8 DATA_SKIP_BOXES = TILE_SIZE * 2;
const Uint8 MOTION_NUM = 3;

enum Motion
{
  ATTACK_INDEX = 0,
  WALK_INDEX = 1
};

enum Orientation
{
  SIDE_INDEX = 0,
  FRONT_INDEX = 1,
  BACK_INDEX = 2
};

Mob::Mob(std::string name, Layer* layer, SDL_Point* top_left, std::string asset_path)
{
  mob_dynamic_id = 0;
  current_motion_ = nullptr;
  cancel_mo_event_ = false;
  dx_ = 0;
  dy_ = 0;
  SDL_Color text_color = {255, 255, 255, 255};
  draw_area_ = new BoxOfSprite(asset_path, top_left);
  name_ = new BoxOfText(top_left, &name, &text_color, FontSize::TWENTY);
  draw_area_->SetX(top_left->x);
  draw_area_->UnsafelySetY(top_left->y);
  draw_area_->SetRecHeight(TILE_SIZE);
  draw_area_->SetRecWidth(TILE_SIZE);

  draw_area_->SetClipHeight(16 * 6);
  draw_area_->SetClipWidth(16 * 6);

  name_->SetX(top_left->x);

  // Add text a little higher than character.
  name_->UnsafelySetY(draw_area_->GetY() + name_->GetHeight());

  owning_layer_ = layer;
  layer->AddWindaBox(draw_area_);
  layer->AddWindaBox(name_);
}



void Mob::Move(int current_frame)
{
  LayerManager::ChangeOfY(owning_layer_, draw_area_, draw_area_->GetY() + dy_);
  LayerManager::ChangeOfY(owning_layer_, name_, name_->GetY() + dy_);

  draw_area_->SetX(draw_area_->GetX() + (dx_));
  name_->SetX(name_->GetX() + (dx_));

  ChangeDrawRect(current_frame);

  std::cout << "all moving" << dy_ << " " << dx_ << " ";
}

void Mob::ChangeDrawRect(int current_frame)
{
  std::cout << "changing direc";
  if (dx_ != 0 && dy_ == 0)
  {
    motion_ = WALK_INDEX;
    if (dx_ >= 0)
    {
      orientation_ = SIDE_INDEX;
      draw_area_->SetFlip(SDL_FLIP_HORIZONTAL);
    }
    else if (dx_ < 0)
    {

      orientation_ = SIDE_INDEX;
      draw_area_->SetFlip(SDL_FLIP_NONE);
    }
  }
  else if (dy_ != 0)
  {
    motion_ = ATTACK_INDEX;
  }

  std::cout << "\n current frame: " << current_frame;
  int x = DATA_SKIP_BOXES + current_frame * TILE_SIZE;
  int y = (motion_ * MOTION_NUM * TILE_SIZE) + orientation_ * TILE_SIZE;
  std::cout << " x: " << x << " y: " << y;
  draw_area_->SetRecX(x);
  draw_area_->SetRecY(y);
}

int Mob::GetDx()
{
  return dx_;
}

int Mob::GetDy()
{
  return dy_;
}

void Mob::SetDx(int dx)
{
  std::cout << "\n poo";
  dx_ = dx;
}

void Mob::SetDy(int dy)
{
  dy_ = dy;
}

int Mob::IsAnimating()
{
  return current_motion_ != nullptr;
}

void Mob::SetOrientation(int animation_code)
{
  orientation_ = animation_code;
}

void Mob::StopAnimation()
{
  current_motion_->SetCanceled();
  current_motion_ = nullptr;
}

void Mob::SetAnimating(RepeatEvent* event)
{
  current_motion_ = event;
}

int Mob::GetX()
{
  return draw_area_->GetX();
}

int Mob::GetY()
{
  return draw_area_->GetY();
}

int Mob::GetHeight()
{
  return draw_area_->GetHeight();
}

int Mob::GetWidth()
{
  return draw_area_->GetWidth();
}

SDL_Keysym Mob::GetLastBPressed()
{
  return last_b_pressed_;
}

void Mob::SetBPressed(SDL_Keysym butt)
{
  last_b_pressed_ = butt;
}

void Mob::UpdatePOCS()
{
  int x = draw_area_->GetX();
  int h = draw_area_->GetHeight();
  int y = draw_area_->GetY();
  int w = draw_area_->GetWidth();
  int tile_size = WorldManager::GetTileSize();

  POfContact foot_pc = WorldManager::GetTileIn(x, y + h);
  foot_pc.mob_ = this;
  foot_pc.type_ = DefaultPOCTypes::FOOT;

  POfContact head_pc = WorldManager::GetTileIn(x, y);
  head_pc.mob_ = this;
  foot_pc.type_ = DefaultPOCTypes::HEAD;

  POfContact middle = WorldManager::GetTileIn(x + w/2, y + h/2);
  middle.mob_ = this;
  foot_pc.type_ = DefaultPOCTypes::MIDDLE;

//  for (auto old_poc : pocs_)
//  {
//    if (*old_poc == foot_pc || *old_poc == head_pc || *old_poc == middle)
//    {
//
//    }
//  }
}

std::list<POfContact *> Mob::GetPOfContacts()
{
  
}

