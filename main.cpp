#include <SDL2/SDL.h>
#include "src/windowing/winda.h"
#include "src/windowing/box_types/box_of_text.h"
#include "src/windowing/box_types/sprite_area.h"
#include "src/windowing/box_types/layer.h"
#include "src/events/main_info_manager.h"
#include "src/windowing/boxxer.h"
#include "src/events/built_in_handlers/default_handlers.h"

int main(void)
{

  // Testing zone
  bool yea = Winda::Init();
  bool yea_ttf = Fonter::LoadFonts();
  auto c_handler = new ClickHandlerTest();
  MainInfoManager::AddHandler(c_handler);
  MainInfoManager::HookHandler(handy::DefaultEvents::E_CLICK_ONCE, handy::Priority::NORMAL, c_handler->GetHandlerCode());
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
  cen.x = 0;
  cen.y = 0;
  SDL_Color text_color;
  text_color.r = 0;
  text_color.g = 255;
  text_color.b = 0;
  text_color.a = 255;

  std::string pig = "This little piggy";
  BaseBox* piece_two = new BoxOfText(&cen, &pig, &text_color, FontSize::FIFTY);
  BaseBox* piece = new BoxOfSprite("../assets/laz.png", &cen);
  Layer* main_box = new Layer(&box, &cen, 0);
  main_box->SetFillColor(&text_color);
  main_box->SetHeight(1500);
  main_box->SetWidth(1500);
  Boxxer::RegisterBox(main_box);

  main_box->AddWindaBox(piece);
  main_box->AddWindaBox(piece_two);
  //End testing Zone------------------------------------
  if (yea)
  {

    // Way the game can stop
    // NOTE: Game may not close as fast as window, may do background stuff first.
    SDL_Event event;
    while (MainInfoManager::running)
    {
      Boxxer::DrawFullNClean();
      while (SDL_PollEvent(&event) != 0)
      {
        MainInfoManager::HandleEvent(&event);
        MainInfoManager::RunActiveEvents();
      }
    }
  }
  return 0;
}
