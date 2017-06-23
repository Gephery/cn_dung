 #include "fonter.h"

// NOTE: Font info for implementation only.
// NOTE: FontSize -> FONT_SIZES & FontCode -> FONT_LOCATIONS
const std::string FONT_LOCATIONS[2] = {"../assets/freefonts/FreeMono.ttf",
                                         "../assets/freefonts/FreeMonoBold.ttf"};
const int FONT_SIZES[5] = {4, 10, 18, 20, 50};
// End font info

TTF_Font* Fonter::fonts_[sizeof(FontSize) * sizeof(FontCode)];

// Initlilizes font related stuff. To be used by Winda.
bool Fonter::Init()
{
  bool success = TTF_Init() != -1;
  if (!success)
      printf("Error in starting SDL_IMG: %s", TTF_GetError());
  return success;
}

// The constats of the fonter.h determine what fonts are loaded in.
bool Fonter::LoadFonts()
{
  bool success = true;
  for (int type_i = 0; type_i < sizeof(FONT_LOCATIONS); type_i++)
  {
    for (int size_i = 0; size_i < sizeof(FontSize); size_i++)
    {
      fonts_[type_i + size_i] = TTF_OpenFont(FONT_LOCATIONS[type_i].c_str(), FONT_SIZES[size_i]);
      success &= fonts_[type_i + size_i] != NULL;
    }
  }
  return success;
}

TTF_Font* Fonter::GetFont(FontCode code, FontSize size)
{
  return fonts_[code * sizeof(FontCode) + size];
}

// Closes everything related to SDL_ttf fonts.
void Fonter::Quit()
{
  // Font closing
  for (int i = 0; i < sizeof(*fonts_); i++)
  {
    TTF_CloseFont(fonts_[i]);
  }
  *fonts_ = NULL;

  TTF_Quit();
}

 SDL_Texture* Fonter::TexturizeText(FontCode code, FontSize size, SDL_Color* color,
                                   std::string text, SDL_Renderer* renderer)
 {
   SDL_Surface* temp_surf = TTF_RenderText_Solid(GetFont(code, size),
                                                 text.c_str(), *color);
   bool success = temp_surf != NULL;
   if (success)
   {
     SDL_Texture* new_text = SDL_CreateTextureFromSurface(renderer, temp_surf);
     success &= new_text != NULL;
     SDL_FreeSurface(temp_surf);
   }

   if (!success)
     printf( "Error in text to Texture, Error: %s\n", SDL_GetError() );
 }
