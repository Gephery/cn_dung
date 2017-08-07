//
// Created by Max Grucella on 7/4/17.
//

#ifndef CODE_NAME_DEFAULT_HANDLERS_H
#define CODE_NAME_DEFAULT_HANDLERS_H


#include "../handy_handler.h"

class ClickHandlerTest : public HandyHandler
{
  public:
    ClickHandlerTest();
    virtual bool main(InfoPacket* info);
  private:
};


#endif //CODE_NAME_DEFAULT_HANDLERS_H
