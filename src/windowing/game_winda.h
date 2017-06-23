#ifndef CODE_NAME_GAME_WINDA_H
#define CODE_NAME_GAME_WINDA_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "fonter.h"

/**
  * Acts as a single contact to access any windowing part.
  *
  * All functions can be accessed anywhere. Windows should be handled by it, so only retrive
  * a component if you want to change it, and if there is a function use it instead.
  */
class GameWinda
{
  public:
    /** Initializes the components necessary for using Game Winda. To be used before the main game loop. */
    static bool Init();

    /** Quits out all the necessary things to stop GameWina things. */
    static void Quit();

    /** Get the window but do not change the pointer. */
    static SDL_Window*  GetWindow();

    /** Get the surface but do not change the pointer. */
    static SDL_Surface*  GetSurface() { return main_surface_; }
  protected:
    static SDL_Window* main_window_; // Seen as the thing that holds everything.
    static SDL_Surface* main_surface_; // Seen as the component used by main_window_ to hold everything.
    static int* screen_width_;
    static int* screen_height_;
};

#endif //CODE_NAME_GAME_WINDA_H
