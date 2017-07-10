//
// Created by Max Grucella on 7/2/17.
//

#ifndef CODE_NAME_TEXTURE_MANAGER_H
#define CODE_NAME_TEXTURE_MANAGER_H


#include <string>
#include <map>
#include <SDL2/SDL_system.h>

class TextureManager
{
public:
  static SDL_Texture* LoadAsset(std::string path, SDL_Rect* rect);
  static void Quit();
private:
  static std::map<std::string, SDL_Texture*> assets_; // For closing of all easily.
};

#endif //CODE_NAME_TEXTURE_MANAGER_H
