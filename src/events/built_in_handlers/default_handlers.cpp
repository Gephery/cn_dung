//
// Created by Max Grucella on 7/4/17.
//

#include "default_handlers.h"

#include "../built_in_packets/click_packet.h"
#include "../../windowing/winda.h"
#include "../../windowing/base_box.h"
#include "../main_info_manager.h"

bool ClickHandlerTest::main(InfoPacket* info)
{
  ClickEvent* click = (ClickEvent*) info;
  if (click->clicked->GetType() == BoxTypes::BOX_OF_SPRITE
      || click->clicked->GetType() == BoxTypes::BOX_OF_READ_TEXT)
  {
    Winda::SetSelectedBox(click->clicked);
    click->clicked->SetFlip(SDL_FLIP_HORIZONTAL);
  }
  return true;
}

ClickHandlerTest::ClickHandlerTest()
{
  handler_code_ = handy::DefaultHandlers::H_CLICK_ONCE_TEST;
}

