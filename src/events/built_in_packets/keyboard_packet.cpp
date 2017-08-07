//
// Created by Max Grucella on 7/12/17.
//

#include "keyboard_packet.h"

#include "../main_info_manager.h"

KeyboardPacket::KeyboardPacket()
{
  event_code_ = handy::DefaultEvents::E_KEYBOARD_PRESS;
}
