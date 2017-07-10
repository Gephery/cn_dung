//
// Created by Max Grucella on 7/2/17.
//

#ifndef CODE_NAME_BOX_OF_TEXT_H
#define CODE_NAME_BOX_OF_TEXT_H

#include <string>
#include "../fonter.h"
#include "../base_box.h"
#include "../enums_fonter.h"

/**
  * Text box.
  */
class BoxOfText : public BaseBox
{
  public:
    BoxOfText(SDL_Point* center, std::string* text,
              SDL_Color* text_color, FontSize size);
    virtual ~BoxOfText();

    void SetTextColor(SDL_Color* color);
    SDL_Color* GetTextColor();

    void SetText(std::string* text);
    std::string* GetText();

    void SetFontType(FontCode type);
    FontCode GetFontType();

    void SetFontSize(FontSize size);
    FontSize GetFontSize();

    void SetWriteable(bool write);
    bool IsWriteable();
  private:
    bool writeable_;
    SDL_Color* text_color_;
    std::string* text_;
    FontCode font_type_;
    FontSize font_size_;
};

#endif //CODE_NAME_BOX_OF_TEXT_H
