#ifndef CODE_NAME_GAME_WINDA_H
#define CODE_NAME_GAME_WINDA_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

enum FontTypes {
  MONO_NORMAL = 0,
  MONO_BOLD = 1
};

const char window_name_ = "Game Dung";
const int text_sizes[5] = {4, 10, 18, 28, 50};

class GameWinda
{
public:
  static bool Init();
  static bool LoadFonts();
  static void Quit();
  static SDL_Window*  GetWindow() { return main_window_; };
  static SDL_Surface*  GetSurface() { return main_surface_; };
private:
  static SDL_Window* main_window_;
  static SDL_Surface* main_surface_;
  static TTF_Font* font_[];
  static int* screen_width_;
  static int* screen_height_;
};

#endif //CODE_NAME_GAME_WINDA_H
