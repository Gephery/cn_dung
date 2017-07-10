//
// Created by Max Grucella on 7/6/17.
//

#include "handy_handler.h"
#include "handy.h"

int HandyHandler::GetHandlerCode() {
  return handler_code_;
}

HandyHandler::HandyHandler()
{
  handler_code_ = 0;
}
