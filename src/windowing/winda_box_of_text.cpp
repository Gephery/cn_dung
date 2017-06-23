//
// Created by Max Grucella on 6/23/17.
//

#include "winda_box.h"

WindaBoxOfText::WindaBoxOfText(SDL_Rect *box, SDL_Color *fill_color,
                               SDL_Color *outline_color, double *angle, SDL_Point *center,
                               SDL_RendererFlip flip, BoxTypes type) : WindaBox(box, fill_color,
                                                                                outline_color,
                                                                                angle, center,
                                                                                flip, type)
{
  // Default text color is black.
  text_color_->r = 0;
  text_color_->g = 0;
  text_color_->b = 0;
  text_color_->a = 255;

  // Default text is "Type here...".
  text_ = "Type here...";

  font_type_ = MONO;
  font_size_ = TWENTY;
}

void WindaBoxOfText::Draw(SDL_Renderer *renderer, SDL_Rect *clip, std::string text)
{
  SetText(text, renderer);
  WindaBox::Draw(renderer, clip);
}

void WindaBoxOfText::SetTextColor(SDL_Color* color)
{
  text_color_ = color;
}

SDL_Color* WindaBoxOfText::GetTextColor()
{
  return text_color_;
}

void WindaBoxOfText::SetText(std::string text, SDL_Renderer* renderer)
{
  if (text_ != text)
  {
    text_ = text;
    img_ = Fonter::TexturizeText(font_type_, font_size_, text_color_, text_, renderer);
  }
}

std::string WindaBoxOfText::GetText()
{
  return text_;
}

void WindaBoxOfText::SetFontType(FontCode type)
{
  font_type_ = type;
}

FontCode WindaBoxOfText::GetFontType()
{
  return font_type_;
}

void WindaBoxOfText::SetFontSize(FontSize size)
{
  font_size_ = size;
}

FontSize WindaBoxOfText::GetFontSize()
{
  return font_size_;
}
