#include "game_winda.h"

SDL_Window* GameWinda::main_window_;
SDL_Surface* GameWinda::main_surface_;
TTF_Font* GameWinda::font_;
int* GameWinda::screen_width_;
int* GameWinda::screen_height_;

bool GameWinda::Init()
{
  bool success = SDL_Init(SDL_INIT_EVERYTHING) == 0;

  if (success) {
    Uint32 sld_flags = SDL_WINDOW_OPENGL | // Telling it there will be openGL.
                       SDL_WINDOW_RESIZABLE |
                       SDL_WINDOW_SHOWN |
                       SDL_WINDOW_MAXIMIZED; // Window starts maximized

    main_window_ = SDL_CreateWindow((const char*) window_name_, 0, 0, 0, 0, sld_flags);

    success = GameWinda::main_window_ != NULL; // Check if window creation a success

    // SDL libs inits
    if (success)
    {
      SDL_GetWindowSize(GameWinda::main_window_, GameWinda::screen_width_, GameWinda::screen_height_); // Sets up easy access w and h.

      GameWinda::main_surface_ = SDL_GetWindowSurface(GameWinda::main_window_);
      success = GameWinda::main_surface_ != NULL;
      SDL_SetWindowResizable(GameWinda::main_window_, SDL_FALSE);
    }
    if (!success)
      printf("Error in starting SDL: %s ", SDL_GetError());

    // SDL_image init
    if (success)
    {
      int img_flags = IMG_INIT_PNG;
      bool img_init_succ = (IMG_Init(img_flags)&img_flags) == img_flags;
      if (!img_init_succ)
          printf("Error in starting SDL_IMG: %s", IMG_GetError());
      success &= img_init_succ;
    }

    // TTF
    if (success)
    {
      bool init_ttf_succ = TTF_Init() != -1;
      if (!init_ttf_succ)
          printf("Error in starting SDL_IMG: %s", TTF_GetError());
          success &= init_ttf_succ;
    }
  }

  if (success) printf("Successful load of SDL and SDL_image.");
  return success;
}

void GameWinda::Quit() {
  // Font closing
  TTF_CloseFont(font_);
  font_ = NULL;

  // SDL main stuff closing
  SDL_DestroyWindow(main_window_);
  main_window_ = NULL;
  SDL_FreeSurface(main_surface_);

  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}

bool GameWinda::LoadFonts()
{
  //TODO add support for multiple sizes of the font
  font_[0] = TTF_OpenFont("../assets/freefonts/FreeMono.ttf");
  font_[1] = TTF_OpenFont("../assets/freefonts/FreeMonoBold.ttf);
  font_ = TTF_OpenFont(path, pt_size);
  return font_ != NULL;
}
