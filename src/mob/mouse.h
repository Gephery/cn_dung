//
// Created by Max Grucella on 7/11/17.
//

#ifndef CODE_NAME_MOUSE_H
#define CODE_NAME_MOUSE_H

#include "mob.h"

class Mouse : public Mob
{
  public:
    Mouse(std::string name, Layer* layer, SDL_Point* top_left);

  private:
};


#endif //CODE_NAME_MOUSE_H