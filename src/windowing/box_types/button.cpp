//
// Created by Max Grucella on 7/10/17.
//

#include "button.h"
#include "../base_box.h"

Button::Button(SDL_Point *center, std::string *text, SDL_Rect size) : BaseBox(center)
{

}

void Button::AddVisualBox(BaseBox* visual)
{
  visuals_.push_front(visual);
}

void Button::Draw()
{

}
