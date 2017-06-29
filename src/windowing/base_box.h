#ifndef CODE_NAME_WINDA_BOX_H
#define CODE_NAME_WINDA_BOX_H

#include <SDL2/SDL.h>
#include <list>
#include <string>
#include <vector>
#include <set>
#include "fonter.h"
#include "winda.h"

enum BoxTypes
{
  BOX_OF_BOX = 0,
  BOX_OF_READ_TEXT = 1,
  BOX_OF_SPRITE = 2,
};

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
    void SetY(int new_y);
  protected:
    BoxTypes type_; /** Use to determine which Winda Box it is. */
    SDL_Rect* rect_; /** The area the box tries to occupy */
    SDL_Texture* img_;
    double angle_;
    SDL_Point* center_;
    SDL_RendererFlip flip_;
    SDL_Rect* clip_;
};

/**
  * Box of Box is a container type for fitting and clipping.
  *
  * When used with Winda box of box will stay the right size by fitting to its outer box if any.
  */
class Layer : public BaseBox
{
  public:
    SDL_Color* GetFillColor();
    void SetFillColor(SDL_Color* fill_color);

    SDL_Color* GetOutlineColor();
    void SetOutlineColor(SDL_Color* outline_color);

    /** Z is the order at which it is drawn. */
    void SetZ(int new_z);
    int GetZ();
    Layer(SDL_Rect* rect, SDL_Point* center, int z);
    virtual void Draw();
    virtual ~Layer();
    std::map<int, std::list<BaseBox*>>  GetInnerBoxes();
    void AddWindaBox(BaseBox* box);
    void ChangeOfY(BaseBox* box, int new_y);
  private:
    std::map<int, std::list<BaseBox*>> inner_boxes_;
    SDL_Color* fill_color_;
    SDL_Color* outline_color_;
    int z_; /** Is the order at which it is drawn. */
};

/**
  * Text box.
  */
class BoxOfText : public BaseBox
{
  public:
    BoxOfText(SDL_Point* center, std::string* text,
              SDL_Color* text_color, FontSize size);
    virtual ~BoxOfText();

    void SetTextColor(SDL_Color* color);
    SDL_Color* GetTextColor();

    void SetText(std::string* text);
    std::string* GetText();

    void SetFontType(FontCode type);
    FontCode GetFontType();

    void SetFontSize(FontSize size);
    FontSize GetFontSize();

    void SetWriteable(bool write);
    bool IsWriteable();
  private:
    bool writeable_;
    SDL_Color* text_color_;
    std::string* text_;
    FontCode font_type_;
    FontSize font_size_;
};

/**
  * Box hooked to a spite/mob.
  */
class BoxOfSprite : public BaseBox
{
  public:
    BoxOfSprite(std::string path, SDL_Point* upper_left);
    ~BoxOfSprite();
  private:
};

/**
  * Use this to access all winda boxes.
  *
  * This should be used to create destroy and draw all boxes.
  */
class Boxxer
{
  public:
    static void RegisterBox(Layer* box);
    static void Draw();
    static void DrawFullNClean();
    static void ChangeOfY(Layer* container, BaseBox* box, int new_y);
    static void ChangeOfZ(Layer* layer, int new_z);
private:
    // NOTE: To access all windows you must look at inner_boxes_ of BoxofBox.
    static std::map<int, std::list<BaseBox*>> boxes_;
};

#endif // CODE_NAME_WINDA_BOX_H
