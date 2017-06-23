//
// Created by Max Grucella on 6/23/17.
//

#include "winda_box.h"

WindaBoxOfBox::WindaBoxOfBox(SDL_Rect *box, SDL_Color *fill_color,
                             SDL_Color *outline_color, double *angle, SDL_Point *center,
                             SDL_RendererFlip flip, BoxTypes type) : WindaBox(box, fill_color,
                                                                              outline_color,
                                                                              angle, center,
                                                                              flip, type)
{
  inner_boxes_ = new std::list<WindaBox>();
}

void WindaBoxOfBox::Draw(SDL_Renderer *renderer, SDL_Rect *clip)
{
  WindaBox::Draw(renderer, clip);
}

std::list<WindaBox>* WindaBoxOfBox::GetInnerBoxes()
{
  return inner_boxes_;
}

void WindaBoxOfBox::AddWindaBox(WindaBox box)
{
  inner_boxes_->push_back(box);
}
