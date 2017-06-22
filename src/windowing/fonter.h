#ifndef CODE_NAME_FONTER_H
#define CODE_NAME_FONTER_H

#include <string>
#include <SDL2_ttf/SDL_ttf.h>

enum FontSizes {
  FOUR = 0,
  TEN = 1,
  EIGHTEEN = 2,
  TWENTY = 3,
  FIFTY = 4
};

enum FontCode
{
  MONO = 0,
  MONO_BOLD = 1
};

class Fonter
{
public:
  static bool Init();
  static bool LoadFonts();
  static TTF_Font* GetFont(FontCode code, FontSizes size);
  static void Quit();
private:
  static TTF_Font* fonts_[];
};

#endif // CODE_NAME_FONTER_H
