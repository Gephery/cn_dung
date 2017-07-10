//
// Created by Max Grucella on 7/2/17.
//

#ifndef CODE_NAME_BOX_OF_SPRITE_H
#define CODE_NAME_BOX_OF_SPRITE_H

#include <string>
#include <SDL2/SDL_rect.h>
#include "../base_box.h"

/**
  * Box hooked to a spite/mob.
  */
class BoxOfSprite : public BaseBox
{
  public:
    BoxOfSprite(std::string path, SDL_Point* upper_left);
    ~BoxOfSprite();
  private:
};

#endif //CODE_NAME_BOX_OF_SPRITE_H
