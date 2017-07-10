//
// Created by Max Grucella on 7/10/17.
//

#ifndef CODE_NAME_BUTTON_H
#define CODE_NAME_BUTTON_H

#import <string>
#include <list>
#include <SDL2/SDL_rect.h>
#include "../enums_fonter.h"

class SDL_Point;
class SDL_Color;
class BaseBox;

class Button : public BaseBox
{
public:
  Button(SDL_Point* center, std::string* text, SDL_Rect size);
  void AddVisualBox(BaseBox* visual);
  virtual void Draw();
private:
  std::list<BaseBox*> visuals_;
  bool isActive_;
};


#endif //CODE_NAME_BUTTON_H
