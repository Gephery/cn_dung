#include <SDL2/SDL.h>
#include "src/windowing/winda.h"
#include "src/windowing/base_box.h"

int main(void)
{

  // Testing zone
  bool yea = Winda::Init();
  bool yea_ttf = Fonter::LoadFonts();
  //Testing ZONE---------------------------------------
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
  text_color.r = 255;
  text_color.g = 0;
  text_color.b = 0;
  text_color.a = 255;

  std::string pig = "This little piggy";
  BaseBox* piece_two = new BoxOfText(&cen, &pig, &text_color, FontSize::FIFTY);
  BaseBox* piece = new BoxOfSprite("../assets/laz.png", &cen);
  Layer* main_box = new Layer(&box, &cen, 0);
  Boxxer::RegisterBox(main_box);
  main_box->AddWindaBox(piece_two);
  main_box->AddWindaBox(piece);
  //End testing Zone------------------------------------
  if (yea)
  {

    // Way the game can stop
    // NOTE: Game may not close as fast as window, may do background stuff first.
    bool running = true;
    SDL_Event event;

    while (running)
    {
      Boxxer::DrawFullNClean();
      while (SDL_PollEvent(&event))
      {
        if (event.type == SDL_QUIT)
        {
          running = false;
          Winda::Quit();
          break;
        }
      }
    }
  }
  return 0;
}
