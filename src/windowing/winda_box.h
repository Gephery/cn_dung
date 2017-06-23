#ifndef CODE_NAME_WINDA_BOX_H
#define CODE_NAME_WINDA_BOX_H

#include <SDL2/SDL.h>
#include <list>
#include <string>
#include "fonter.h"

enum BoxTypes
{
  BOX_OF_BOX = 0,
  BOX_OF_TEXT = 1,
  BOX_OF_SPRITE = 2
};

/**
  * The abstract Winda box. Use one of the box types, not this one.
  *
  * Although the use of Winda box is bad, using it to catch all is fine, because by checking
  * its type you can then typecast it to the appropriate type.
  */
class WindaBox
{
  public:
    WindaBox(SDL_Rect* box, SDL_Color* fill_color, SDL_Color* outline_color,
                     double* angle, SDL_Point* center, SDL_RendererFlip flip, BoxTypes type);

    ~WindaBox();

    virtual void Draw(SDL_Renderer* renderer, SDL_Rect* clip);

    /** Change the rectangle that the box tries to occupy. */
    void Change_Box(SDL_Rect* box);

    SDL_Color* GetFillColor();
    void SetFillColor(SDL_Color* fill_color);

    SDL_Color* GetOutlineColor();
    void SetOutlineColor(SDL_Color* outline_color);

    /**
      * This is the rectangle it tries to occupy.
      * NOTE: it may end up being smaller if contained in a small box.
      */
    SDL_Rect* GetBox();

    /** Z is the order at which it is drawn. */
    void SetZ(int* new_z);
    int* GetZ();

    double* GetAngle();
    void SetAngle(double* angle);

    SDL_Point* GetCenter();
    void SetCenter(SDL_Point* center);

    SDL_RendererFlip GetFlip();
    void SetFlip(SDL_RendererFlip flip);

    /** Will always have a type and will show what it can be typecast to. */
    BoxTypes GetType();

    /** The img is what is displayed in the box other than color. */
    virtual SDL_Texture* GetImg();
    void SetTexture(SDL_Texture* img);
  protected:
    BoxTypes type_; /** Use to determine which Winda Box it is. */
    SDL_Rect* rect_; /** The area the box tries to occupy */
    SDL_Color* fill_color_;
    SDL_Color* outline_color_;
    int* z_; /** Is the order at which it is drawn. */
    SDL_Texture* img_;
    double* angle_;
    SDL_Point* center_;
    SDL_RendererFlip flip_;
};

/**
  * Box of Box is a container type for fitting and clipping.
  *
  * When used with Winda box of box will stay the right size by fitting to its outer box if any.
  */
class WindaBoxOfBox : public WindaBox
{
  public:
    WindaBoxOfBox(SDL_Rect *box, SDL_Color *fill_color,
                  SDL_Color *outline_color, double *angle, SDL_Point *center,
                  SDL_RendererFlip flip, BoxTypes type);
    void Draw(SDL_Renderer* renderer, SDL_Rect* clip);
    std::list<WindaBox>* GetInnerBoxes();
    void AddWindaBox(WindaBox box);
  private:
    std::list<WindaBox>* inner_boxes_;
};

/**
  * Text box.
  */
class WindaBoxOfText : public WindaBox
{
  public:
    WindaBoxOfText(SDL_Rect* box, SDL_Color* fill_color, SDL_Color* outline_color,
                   double* angle, SDL_Point* center, SDL_RendererFlip flip, BoxTypes type);
    void Draw(SDL_Renderer* renderer, SDL_Rect* clip, std::string text);

    void SetTextColor(SDL_Color* color);
    SDL_Color* GetTextColor();

    void SetText(std::string text, SDL_Renderer* renderer);
    std::string GetText();

    void SetFontType(FontCode type);
    FontCode GetFontType();

    void SetFontSize(FontSize size);
    FontSize GetFontSize();
  private:
    SDL_Color* text_color_;
    std::string text_;
    FontCode font_type_;
    FontSize font_size_;
};

/**
  * Box hooked to a spite/mob.
  */
class WindaBoxOfSprite : public WindaBox
{
  public:
    WindaBoxOfSprite(SDL_Rect* box, SDL_Color* fill_color, SDL_Color* outline_color,
                     double* angle, SDL_Point* center, SDL_RendererFlip* flip, BoxTypes type);
  void Draw(SDL_Renderer* renderer, SDL_Rect* clip);
    void SetClip(SDL_Rect* clip);
  private:
    SDL_Rect* clip_;
};

/**
  * Use this to access all winda boxes.
  *
  * This should be used to create destroy and draw all boxes.
  */
class WindaBoxer
{
  public:
    static void DeleteBox(WindaBox* box);
    static WindaBox* CreateBox(BoxTypes type, SDL_Rect* box, SDL_Color* fill_color,
                                SDL_Color* outline_color, short* z);
    static void CloseAllBoxes();
    static void Draw();
  private:
    // NOTE: To access all windws you must look at inner_boxes_ of BoxofBox.
    static WindaBox* main_box_;
};

#endif // CODE_NAME_WINDA_BOX_H
