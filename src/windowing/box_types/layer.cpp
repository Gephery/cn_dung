//
// Created by Max Grucella on 6/23/17.
//

#include "layer.h"

#include <iostream>
#include "../winda.h"
#include "../../events/built_in_packets/click_packet.h"

Layer::Layer(SDL_Rect *rect, SDL_Point* center, int z) : BaseBox(center)
{
  rect_ = rect;
  clip_ = rect;
  fill_color_ = NULL;
  outline_color_ = NULL;
  z_ = z;
  type_ = BOX_OF_BOX;
}

std::map<int, std::list<BaseBox*>> Layer::GetInnerBoxes()
{
  return inner_boxes_;
}

void Layer::AddWindaBox(BaseBox* box)
{
  inner_boxes_[box->GetY() + box->GetHeight()].push_back(box);
}

Layer::~Layer()
{
  Destroy();
}

void Layer::Draw()
{
  if (draw_)
  {
    SDL_Renderer *renderer = Winda::GetRenderer();
    if (rect_ != NULL) {

      if (fill_color_ != NULL) {
        // Fill rect with specified color
        SDL_SetRenderDrawColor(renderer, fill_color_->r, fill_color_->g,
                               fill_color_->b, fill_color_->a);
        SDL_RenderFillRect(renderer, rect_);
      }

      if (outline_color_ != NULL) {
        // Outline rect with specified color
        SDL_SetRenderDrawColor(renderer, outline_color_->r, outline_color_->g,
                               outline_color_->b, outline_color_->a);
        SDL_RenderDrawRect(renderer, rect_);
      }
    }
    for (auto collection : inner_boxes_) {
      for (auto box : collection.second) // Just in case two have same y
      {
        box->Draw();
      }
    }
  }
}

SDL_Color* Layer::GetFillColor()
{
  return fill_color_;
}

void Layer::SetFillColor(SDL_Color* fill_color)
{
  fill_color_ = fill_color;
}

SDL_Color* Layer::GetOutlineColor()
{
  return outline_color_;
}

void Layer::SetOutlineColor(SDL_Color* outline_color)
{
  outline_color_ = outline_color;
}

void Layer::UnsafelySetZ(int new_z)
{
  z_ = new_z;
}

int Layer::GetZ()
{
  return z_;
}

void Layer::ChangeOfY(BaseBox* box, int new_y)
{
  auto yer = inner_boxes_[box->GetY() + box->GetHeight()];
  std::remove(yer.begin(), yer.end(), box);
  box->UnsafelySetY(new_y);
  AddWindaBox(box);
}

void Layer::SetHeight(int height)
{
  rect_->h = height;
  clip_->h = height;
}

void Layer::SetWidth(int width)
{
  rect_->w = width;
  clip_->w = width;
}

ClickEvent* Layer::HuntInnerBox(ClickEvent *click)
{
  if (IsPointInBox(click->x, click->y))
  {
    for (auto inner = inner_boxes_.rbegin();
         inner != inner_boxes_.rend(); ++inner)
    {
      for (auto sim_y = inner->second.rbegin(); sim_y != inner->second.rend(); ++sim_y)
      {
        if ((*sim_y)->IsPointInBox(click->x, click->y))
        {
          if (*sim_y != nullptr)
          {
            if ((*sim_y)->GetType() == BoxTypes::BOX_OF_BOX)
            {
              click = ((Layer *) *sim_y)->HuntInnerBox(click);
            }
            else
            {
              click->z = this->z_;
              click->clicked = *sim_y;
              click->fully_set = true;
              return click;
            }
          }
        }
      }
    }
    if (!click->fully_set)
    {
      click->z = this->z_;
      click->clicked = this;
      click->fully_set = true;
      return click;
    }
  }
  return click;
}


