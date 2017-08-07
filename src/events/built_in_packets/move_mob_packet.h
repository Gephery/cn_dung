//
// Created by Max Grucella on 7/14/17.
//

#ifndef CODE_NAME_MOVE_MOB_PACKET_H
#define CODE_NAME_MOVE_MOB_PACKET_H


#include <SDL2/SDL_system.h>
#include "../info_packet.h"

class MoveMobPacket : public InfoPacket
{
  public:
    MoveMobPacket();
    SDL_Keysym sym;
    void* mob;
  private:
};


#endif //CODE_NAME_MOVE_MOB_PACKET_H
