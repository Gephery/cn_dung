#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "src/graphics/sprite.h"
#include "src/windowing/game_winda.h"

int main(void)
{

  // Testing zone
  bool yea = GameWinda::Init();
  //Testing ZONE---------------------------------------
  SpritePiece* piece = new SpritePiece((char *) "../assets/laz.png", GameWinda::GetSurface()->format);
  SDL_Surface* img = piece->GetImg();

  SDL_Rect rect;
  rect.x = 0;
  rect.y = 0;
  rect.h = img->h;
  rect.w = img->w;
  SDL_Surface* temp_win = SDL_GetWindowSurface(GameWinda::GetWindow());
  Uint32 color = SDL_MapRGB(GameWinda::GetSurface()->format, 255, 255, 255);
  //SDL_FillRect(img, NULL, color);
  SDL_BlitSurface(img, NULL, temp_win, &rect);
  SDL_UpdateWindowSurface(GameWinda::GetWindow());

  //End testing Zone------------------------------------
  if (yea) {
    // Way the game can stop
    // NOTE: Game may not close as fast as window, may do background stuff first.
    bool running = true;
    SDL_Event event;

    while (running)
    {
      // Only run if there is an event waiting to be checked.
      // TODO add more event handling for user input
      while (SDL_PollEvent(&event))
      {
        if (event.type == SDL_QUIT)
        {
          running = false;
          GameWinda::Quit();
          break;
        }
      }
    }
  }
  return 0;
}
