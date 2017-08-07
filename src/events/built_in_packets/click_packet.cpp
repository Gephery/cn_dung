//
// Created by Max Grucella on 7/4/17.
//

#include "click_packet.h"

#include "../main_info_manager.h"

ClickEvent::ClickEvent()
{
  x = 0;
  y = 0;
  z = 0;
  fully_set = false;
  clicked = nullptr;
  event_code_ = handy::DefaultEvents::E_CLICK_ONCE;
}
