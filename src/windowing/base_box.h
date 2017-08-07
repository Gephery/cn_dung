#ifndef CODE_NAME_WINDA_BOX_H
#define CODE_NAME_WINDA_BOX_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_system.h>
#include "box_types.h"

/**
  * The abstract Winda box. Use one of the box types, not this one.
  *
  * Although the use of Winda box is bad, using it to catch all is fine, because by checking
  * its type you can then typecast it to the appropriate type.
  */
class BaseBox
{
  public:
    BaseBox(SDL_Point* upper_left);

    virtual ~BaseBox();
    void Destroy();

    virtual void Draw();

    /** Change the rectangle that the box tries to occupy. */
    void ChangeContainer(SDL_Rect* box);
    SDL_Rect* GetContainer();

    double GetAngle();
    void SetAngle(double angle);

    SDL_Point* GetCenter();
    void SetCenter(SDL_Point* center);

    SDL_RendererFlip GetFlip();
    void SetFlip(SDL_RendererFlip flip);

    /** Will always have a type and will show what it can be typecast to. */
    BoxTypes GetType();

    /** The img is what is displayed in the box other than color. */
    virtual SDL_Texture* GetImg();
    void SetTexture(SDL_Texture* img);

    void SetClip(SDL_Rect* clip);
    int GetY();
    void SetX(int new_x);
    int GetX();
    void UnsafelySetY(int new_y);
    bool IsPointInBox(int x, int y);
    bool draw_;
    int GetHeight();
    int GetWidth();
    void SetRecHeight(int height);
    void SetRecWidth(int width);
    void SetRecX(int x);
    void SetRecY(int y);
    void SetClipWidth(int width);
    void SetClipHeight(int height);
  protected:
    BoxTypes type_; /** Use to determine which Winda Box it is. */
    SDL_Rect* rect_; /** The area the box tries to occupy */
    SDL_Texture* img_;
    double angle_;
    SDL_Point* center_;
    SDL_RendererFlip flip_;
    SDL_Rect* clip_;
};

#endif // CODE_NAME_WINDA_BOX_H
