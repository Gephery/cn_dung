#ifndef CODE_NAME_FONTER_H
#define CODE_NAME_FONTER_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "enums_fonter.h"

/**
  * Used by Winda to display and keep track of font types.
  *
  * Look at Winda for implementation details. It keeps track of fonts and loading of them.
  */
class Fonter
{
public:
  /** Initializes font related things needed by Fonter. */
  static bool Init();

  /** Loads in fonts. */
  static bool LoadFonts();

  static TTF_Font* GetFont(FontCode code, FontSize size);

  /** Quits all the Fonter things out. NOTE: it is not garbage disposing. */
  static void Quit();
  static SDL_Texture* TexturizeText(FontCode code, FontSize size, SDL_Color* color,
                                   std::string text, SDL_Renderer* renderer, SDL_Rect* box);
private:
  static TTF_Font* fonts_[];
};

#endif // CODE_NAME_FONTER_H
