#include "base_box.h"

BaseBox::BaseBox(SDL_Point* upper_left)
{
  // Safety
  SDL_Point* cen = NULL;
  center_ = cen;

  rect_ = new SDL_Rect();
  rect_->x = 0;
  rect_->y = 0;
  clip_ = new SDL_Rect();
  clip_->x = upper_left->x;
  clip_->y = upper_left->y;

  angle_ = 0.0;
  flip_ = SDL_FLIP_NONE;
}

void BaseBox::Destroy()
{

}

BaseBox::~BaseBox()
{
  Destroy();
}

void BaseBox::Draw()
{
  // Draw texture if there is one
  if (img_ != NULL)
  {
    SDL_RenderCopyEx(Winda::GetRenderer(), img_, rect_, clip_, angle_,
                     (const SDL_Point *) center_, (const SDL_RendererFlip) flip_);
  }
}

void BaseBox::ChangeContainer(SDL_Rect *box)
{
  rect_ = box;
}

SDL_Rect* BaseBox::GetContainer()
{
  return rect_;
}

BoxTypes BaseBox::GetType()
{
  return type_;
}

SDL_Texture* BaseBox::GetImg()
{
  return img_;
}

void BaseBox::SetTexture(SDL_Texture* img)
{
  img_ = img;
}

double BaseBox::GetAngle()
{
  return angle_;
}

void BaseBox::SetAngle(double angle)
{
  angle_ = angle;
}

SDL_Point* BaseBox::GetCenter()
{
  return center_;
}

void BaseBox::SetCenter(SDL_Point* center)
{
  center_ = center;
}

SDL_RendererFlip BaseBox::GetFlip()
{
  return flip_;
}

void BaseBox::SetFlip(SDL_RendererFlip flip)
{
  flip_ = flip;
}

void BaseBox::SetClip(SDL_Rect* clip)
{
  clip_ = clip;
}

void BaseBox::SetY(int new_z)
{
  clip_->y = new_z;
}

int BaseBox::GetY()
{
  return clip_->y;
}

void BaseBox::SetX(int new_x)
{
  clip_->x = new_x;
}

int BaseBox::GetX()
{
  return clip_->x;
}

