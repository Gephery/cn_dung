#include "winda.h"

const char WINDA_NAME[10] = "Game Dung";

SDL_Window* Winda::main_window_;
SDL_Renderer* Winda::renderer_;
int* Winda::screen_width_;
int* Winda::screen_height_;

SDL_Window*  Winda::GetWindow() { return main_window_; }

bool Winda::Init()
{
  bool success = SDL_Init(SDL_INIT_EVERYTHING) == 0;

  if (success) {
    Uint32 sld_flags = SDL_WINDOW_OPENGL | // Telling it there will be openGL.
                       SDL_WINDOW_RESIZABLE |
                       SDL_WINDOW_SHOWN |
                       SDL_WINDOW_MAXIMIZED; // Window starts maximized

    main_window_ = SDL_CreateWindow(WINDA_NAME, 0, 0, 0, 0, sld_flags);

    success = Winda::main_window_ != NULL; // Check if window creation a success

    // SDL libs inits
    if (success)
    {
      SDL_GetWindowSize(main_window_, screen_width_, screen_height_); // Sets up easy access w and h.

      renderer_ = SDL_CreateRenderer(main_window_, -1, SDL_RENDERER_ACCELERATED);
      success = renderer_ != NULL;
      //Initialize renderer color
      SDL_SetWindowResizable(Winda::main_window_, SDL_FALSE);
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
    success &= Fonter::Init();
  }

  if (success) printf("Successful load of SDL and SDL_image.");
  return success;
}

void Winda::Quit()
{

  TextureManager::Quit();

  // SDL main stuff closing
  SDL_DestroyWindow(main_window_);
  main_window_ = NULL;
  SDL_DestroyRenderer(renderer_);

  IMG_Quit();
  SDL_Quit();
}

int Winda::GetWindaWidth()
{
  return *screen_width_;
}

int Winda::GetWindaHeight()
{
  return *screen_height_;
}
