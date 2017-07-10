//
// Created by Max Grucella on 6/29/17.
//

#include "info_packet.h"

int InfoPacket::GetEventCode()
{
  return event_code_;
}

void InfoPacket::name()
{

}

InfoPacket::InfoPacket()
{
  event_code_ = 0;
}
