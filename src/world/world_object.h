//
// Created by Max Grucella on 7/14/17.
//

#ifndef CODE_NAME_GROUND_H
#define CODE_NAME_GROUND_H

#include <SDL2/SDL_rect.h>
#include <string>

class Layer;
class BoxOfSprite;

class WorldObject
{
  public:
    WorldObject(Layer* layer, SDL_Point* top_left, std::string path_to_asset);
  private:
    Layer* owning_layer_;
    BoxOfSprite* ground_;
};


#endif //CODE_NAME_GROUND_H
