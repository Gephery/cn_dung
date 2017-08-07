//
// Created by Max Grucella on 7/14/17.
//

#include "move_mob_packet.h"

#include "../main_info_manager.h"

MoveMobPacket::MoveMobPacket()
{
  event_code_ = handy::E_MOVE_MOB;
}
