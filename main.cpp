#include "src/windowing/winda.h"
#include "src/windowing/box_types/box_of_text.h"
#include "src/windowing/box_types/layer.h"
#include "src/events/main_info_manager.h"
#include "src/windowing/layer_manager.h"
#include "src/events/built_in_handlers/default_handlers.h"
#include "src/mob/mouse.h"
#include "src/events/built_in_handlers/player_move_handler.h"
#include "src/world/world_object.h"
#include "src/world/world_manager.h"

int main(void)
{

  // Testing zone
  bool yea = Winda::Init();
  bool yea_ttf = Fonter::LoadFonts();
  auto c_handler = new ClickHandlerTest();
  auto move_handler = new PlayerMoveHandler();
  MainInfoManager::AddHandler(c_handler);
  MainInfoManager::AddHandler(move_handler);
  MainInfoManager::HookHandler(handy::DefaultEvents::E_CLICK_ONCE, handy::Priority::NORMAL, c_handler->GetHandlerCode());
  MainInfoManager::HookHandler(handy::DefaultEvents::E_MOVE_MOB, handy::Priority::NORMAL, move_handler->GetHandlerCode());
  WorldManager::Init(16, 5, 5);
  //Testing ZONE--------------------------------------
  SDL_Rect box;
  box.x = 0;
  box.y = 0;
  box.w = 100;
  box.h = 100;

  SDL_Rect box_two;
  box_two.x = 0;
  box_two.y = 0;

  SDL_Point cen;
  cen.x = 105;
  cen.y = 100 + 16*6;
  SDL_Color text_color;
  text_color.r = 6;
  text_color.g = 207;
  text_color.b = 229;
  text_color.a = 255;

  std::string pig = "This little piggy";
  BaseBox* piece_two = new BoxOfText(&cen, &pig, &text_color, FontSize::FIFTY);
  Layer* main_box = new Layer(&box, &cen, 0);
  main_box->SetFillColor(&text_color);
  main_box->SetHeight(1500);
  main_box->SetWidth(1500);
  LayerManager::RegisterBox(main_box);

  main_box->AddWindaBox(piece_two);
  SDL_Point pentso;
  pentso.x = 100;
  pentso.y = 100;
  Mouse* mouse = new Mouse("Gephery", main_box, &pentso);
  WorldObject* ground = new WorldObject(main_box, &cen, "../assets/grass.png");
  Winda::SetPlayer(mouse);
  unsigned long indi = WorldManager::RegisterMob(mouse);
  //End testing Zone------------------------------------
  if (yea)
  {
    auto start_t = SDL_GetTicks();
    // Way the game can stop
    // NOTE: Game may not close as fast as window, may do background stuff first.
    SDL_Event event;
    while (MainInfoManager::running)
    {
      while (SDL_PollEvent(&event) != 0)
      {
        MainInfoManager::HandleEvent(&event);
      }
      MainInfoManager::RunActiveEvents();
      LayerManager::DrawFullNClean();
    }
    SDL_Delay(1000/30 - (SDL_GetTicks() - start_t));
  }
  return 0;
}
