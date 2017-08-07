//
// Created by Max Grucella on 6/29/17.
//

#ifndef CODE_NAME_INFO_PACKET_H
#define CODE_NAME_INFO_PACKET_H

#include <functional>
#include <list>

class InfoPacket
{
  public:
    InfoPacket();
    virtual void name();
    int GetEventCode();
    int event_code_;
    bool fully_set; // Only throw events that have all fields set, this should be true when all are set.
  private:
};


#endif //CODE_NAME_INFO_PACKET_H
