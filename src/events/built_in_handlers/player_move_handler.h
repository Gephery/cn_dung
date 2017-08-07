//
// Created by Max Grucella on 7/13/17.
//

#ifndef CODE_NAME_PLAYER_MOVE_HANDLER_H
#define CODE_NAME_PLAYER_MOVE_HANDLER_H

#include "../handy_handler.h"

class PlayerMoveHandler : public HandyHandler
{
  public:
    PlayerMoveHandler();
    virtual bool main(InfoPacket* info);
  private:
};


#endif //CODE_NAME_PLAYER_MOVE_HANDLER_H
