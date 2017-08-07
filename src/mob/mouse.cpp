
#include "mouse.h"

Mouse::Mouse(std::string name, Layer *layer,
             SDL_Point *top_left) : Mob(name, layer, top_left,
                                        "../assets/mouse.png")
{

}
