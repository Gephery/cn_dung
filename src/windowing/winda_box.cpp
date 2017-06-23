#include "winda_box.h"

WindaBox::WindaBox(SDL_Rect* box, SDL_Color* fill_color, SDL_Color* outline_color,
                   double* angle, SDL_Point* center, SDL_RendererFlip flip, BoxTypes type)
{
  rect_ = box;
  fill_color_ = fill_color;
  outline_color_ = outline_color;
  angle_ = angle;
  center_ = center;
  flip_ = flip;
  type_ = type;
}

WindaBox::~WindaBox()
{
  SDL_DestroyTexture(img_);
}

void WindaBox::Draw(SDL_Renderer* renderer, SDL_Rect* clip)
{
  // Outline rect with specified color
  SDL_SetRenderDrawColor(renderer, outline_color_->r, outline_color_->g,
                         outline_color_->b, outline_color_->a);
  SDL_RenderDrawRect(renderer, rect_);

  // Fill rect with specified color
  SDL_SetRenderDrawColor(renderer, fill_color_->r, fill_color_->g,
                         fill_color_->b, fill_color_->a);
  SDL_RenderFillRect(renderer, rect_);

  // Draw texture if there is one
  if (img_ != NULL)
    SDL_RenderCopyEx(renderer, img_, rect_, clip, (const double) *angle_,
                     (const SDL_Point*) center_, (const SDL_RendererFlip) flip_);
}

void WindaBox::Change_Box(SDL_Rect* box)
{
  rect_ = box;
}

SDL_Color* WindaBox::GetFillColor()
{
  return fill_color_;
}

void WindaBox::SetFillColor(SDL_Color* fill_color)
{
  fill_color_ = fill_color;
}

SDL_Color* WindaBox::GetOutlineColor()
{
  return outline_color_;
}

void WindaBox::SetOutlineColor(SDL_Color* outline_color)
{
  outline_color_ = outline_color;
}

SDL_Rect* WindaBox::GetBox()
{
  return rect_;
}

void WindaBox::SetZ(int* new_z)
{
  z_ = new_z;
}

int* WindaBox::GetZ()
{
  return z_;
}

BoxTypes WindaBox::GetType()
{
  return type_;
}

SDL_Texture* WindaBox::GetImg()
{
  return img_;
}

void WindaBox::SetTexture(SDL_Texture* img)
{
  img_ = img;
}

double* WindaBox::GetAngle()
{
  return angle_;
}

void WindaBox::SetAngle(double* angle)
{
  angle_ = angle;
}

SDL_Point* WindaBox::GetCenter()
{
  return center_;
}

void WindaBox::SetCenter(SDL_Point* center)
{
  center_ = center;
}

SDL_RendererFlip WindaBox::GetFlip()
{
  return flip_;
}

void WindaBox::SetFlip(SDL_RendererFlip flip)
{
  flip_ = flip;
}
