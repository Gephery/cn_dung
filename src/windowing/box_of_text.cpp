//
// Created by Max Grucella on 6/23/17.
//

#include "base_box.h"

BoxOfText::BoxOfText(SDL_Point* upper_left, std::string* text, SDL_Color* text_color,
                     FontSize fontSize) : BaseBox(upper_left)
{
  writeable_ = false;
  font_type_ = FontCode::MONO;
  font_size_ = fontSize;
  text_color_ = text_color;
  SetText(text);
  type_ = BOX_OF_READ_TEXT;
  clip_->h = rect_->h;
  clip_->w = rect_->w;
}

void BoxOfText::SetTextColor(SDL_Color* color)
{
  text_color_ = color;
}

SDL_Color* BoxOfText::GetTextColor()
{
  return text_color_;
}

void BoxOfText::SetText(std::string* text)
{

  if (text_ == NULL || text_ != text)
  {
    text_ = text;
    img_ = Fonter::TexturizeText(font_type_, font_size_, text_color_, *text_,
                                 Winda::GetRenderer(), rect_);
  }
}

std::string* BoxOfText::GetText()
{
  return text_;
}

void BoxOfText::SetFontType(FontCode type)
{
  font_type_ = type;
}

FontCode BoxOfText::GetFontType()
{
  return font_type_;
}

void BoxOfText::SetFontSize(FontSize size)
{
  font_size_ = size;
}

FontSize BoxOfText::GetFontSize()
{
  return font_size_;
}

BoxOfText::~BoxOfText()
{
  Destroy();
  delete(text_color_);
  delete(text_);
}

void BoxOfText::SetWriteable(bool write)
{
  writeable_ = write;
}

bool BoxOfText::IsWriteable() {
  return writeable_;
}
