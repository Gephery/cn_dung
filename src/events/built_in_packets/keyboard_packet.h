//
// Created by Max Grucella on 7/12/17.
//

#ifndef CODE_NAME_KEYBOARD_PACKET_H
#define CODE_NAME_KEYBOARD_PACKET_H


#include <SDL2/SDL_events.h>
#include "../info_packet.h"

class KeyboardPacket : public InfoPacket
{
  public:
    KeyboardPacket();
    SDL_Keysym sym;
  private:
};


#endif //CODE_NAME_KEYBOARD_PACKET_H
