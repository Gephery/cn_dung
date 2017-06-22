#ifndef CODE_NAME_GAME_WINDA_H
#define CODE_NAME_GAME_WINDA_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "fonter.h"

class GameWinda
{
  public:
    static bool Init();
    static void Quit();
    static SDL_Window*  GetWindow();
    static SDL_Surface*  GetSurface() { return main_surface_; }
  protected:
    static SDL_Window* main_window_;
    static SDL_Surface* main_surface_;
    static int* screen_width_;
    static int* screen_height_;
};

#endif //CODE_NAME_GAME_WINDA_H
