//
// Created by Max Grucella on 6/14/17.
//
#include <SDL2_image/SDL_image.h>
#include <map>

#ifndef CODE_NAME_SPRITE_PIECE_H
#define CODE_NAME_SPRITE_PIECE_H
__deprecated
class SpritePiece
{
    public:
        SpritePiece(char path[], SDL_PixelFormat* format);
        bool IsLoaded();
        SDL_Surface* GetImg();
        ~TrashPiece();
    private:
        SDL_Surface* img_ = NULL;
};

// Packs all the needed sprites into one
class SpritePack
{
    /*
     * Holds things like path to main sprite and sprite format of which it uses to
     * make the sprites
     */
    public:

    private:

};




#endif //CODE_NAME_SPRITE_PIECE_H
