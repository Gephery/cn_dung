//
// Created by Max Grucella on 7/13/17.
//

#include "player_move_handler.h"

#include <SDL2/SDL_system.h>
#include <iostream>
#include "../built_in_packets/keyboard_packet.h"
#include "../../windowing/winda.h"
#include "../../mob/mouse.h"
#include "../repeat_event.h"
#include "../main_info_manager.h"
#include "../built_in_packets/move_mob_packet.h"

const int FRAME_DELAY = 66;
const int FRAME_NUMBER = 5;

PlayerMoveHandler::PlayerMoveHandler()
{
  handler_code_ = handy::H_KEYBOARD_MOVE_PLAYER;
}

bool PlayerMoveHandler::main(InfoPacket *info) {
  auto symbol = ((MoveMobPacket *) info)->sym;
  auto val = symbol.sym;
  Mob* player = (Mob*) (((MoveMobPacket *) info)->mob);
  // Opposite direction change, will stop animation and start new one.
  if ((player->GetDx() < 0 && (val == SDLK_d || val == SDLK_RIGHT)) ||
      (player->GetDx() > 0 && (val == SDLK_a || val == SDLK_LEFT)))
  {
    player->StopAnimation();
  }

  if (!player->IsAnimating())
  {
    player->SetBPressed(symbol);
    RepeatEvent* rpe = nullptr;
    std::cout << " \n" << val;
    std::cout << " \n" << SDLK_a;
    if (val == SDLK_a || val == SDLK_LEFT)
    {
      player->SetDx(-10);
    }
    else if (val == SDLK_d || val == SDLK_RIGHT)
    {
      player->SetDx(10);
    }
    std::function<void *(void *, RepeatEvent *)> func =
      [](void *mouse, RepeatEvent *event) -> void *
      {
        Mouse* real_mouse = (Mouse*) mouse;
        if (real_mouse->IsAnimating())
        {
          real_mouse->Move(event->GetTimesRepeated());
          if (event->GetTimesRepeated() == event->GetTimesThatWillRepeat() - 1)
          {
            SDL_Scancode code = real_mouse->GetLastBPressed().scancode;
            const Uint8* state = SDL_GetKeyboardState(NULL);
            if (state[code] == 1)
            {
              std::cout << " Replayed ";
              event->Replay();
            }
            else
            {
              real_mouse->SetDx(0);
              real_mouse->StopAnimation();
            }
          }
          return mouse;
        }
        return nullptr;
      };
    rpe = new RepeatEvent(func, FRAME_NUMBER, FRAME_DELAY, (void*) player);
    MainInfoManager::ThrowRepeatEvent(rpe);
    player->SetAnimating(rpe);
  }
  return true;
}
