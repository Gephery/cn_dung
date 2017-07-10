//
// Created by Max Grucella on 7/6/17.
//

#ifndef CODE_NAME_HANDY_HANDLER_H
#define CODE_NAME_HANDY_HANDLER_H


#include <functional>
class InfoPacket;

class HandyHandler
{
  public:
    HandyHandler();
    virtual bool main(InfoPacket* info) = 0;
    int GetHandlerCode();
  protected:
    int handler_code_;
};


#endif //CODE_NAME_HANDY_HANDLER_H
