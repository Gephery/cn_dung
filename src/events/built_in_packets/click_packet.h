//
// Created by Max Grucella on 7/2/17.
//

#ifndef CODE_NAME_CLICK_EVENT_H
#define CODE_NAME_CLICK_EVENT_H

#include "../info_packet.h"
class BaseBox;

class ClickEvent : public InfoPacket
{
  public:
    ClickEvent();
    int x;
    int y;
    int z;
    BaseBox* clicked;
  private:
};



#endif //CODE_NAME_CLICK_EVENT_H
