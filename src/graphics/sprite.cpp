//
// Created by Max Grucella on 6/14/17.
//

#include <string>
#include "../../include/sprite.h"

SpritePiece::SpritePiece(char path[], SDL_PixelFormat* format)
{
    SDL_Surface* loading_img = IMG_Load(path);
    bool success = loading_img != NULL;
    if (success)
    {
        img_ = SDL_ConvertSurface(loading_img, format, 0);
        success = img_ != NULL;
    }
    if (!success)
    {
        printf("Unable to load image: %s", IMG_GetError());
    }
    SDL_FreeSurface(loading_img);
}

// Loading will be done by the construction of it, but check that it loads properly here.
bool SpritePiece::IsLoaded()
{
    return img_ != NULL;
}

SDL_Surface *SpritePiece::GetImg()
{
    return img_;
}
