//
// Created by Max Grucella on 6/25/17.
//

#include "winda.h"

std::map<std::string, SDL_Texture*> TextureManager::assets_;

SDL_Texture* TextureManager::LoadAsset(std::string path, SDL_Rect* rect)
{
  SDL_Texture* possible = assets_[path];
  if (possible == nullptr) // Check if already added.
  {
    SDL_Texture *fin_texture;
    SDL_Surface *loading_img = IMG_Load(path.c_str()); // Load in img, not formatted.
    bool success = loading_img != NULL;

    if (success) // Formatting check.
    {
      // Turn into formatted texture.
      fin_texture = SDL_CreateTextureFromSurface(Winda::GetRenderer(), loading_img);
      success = fin_texture != NULL;

      rect->w = loading_img->w;
      rect->h = loading_img->h;

      // Free formatted
      SDL_FreeSurface(loading_img);

      if (success) // Success, now store and return place.
      {
        assets_[path] = fin_texture;
        return fin_texture;
      }
    }

    // Because of return if code arrives here, it is not successful.
    printf("Unable to load image: %s", IMG_GetError());
  }
  return possible;
}

void TextureManager::Quit()
{
  for (auto i = assets_.begin(); i != assets_.end(); ++i)
  {
    SDL_DestroyTexture(i->second);
  }
}
