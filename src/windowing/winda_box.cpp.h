#ifndef CODE_NAME_WINDA_BOX_H
#define CODE_NAME_WINDA_BOX_H

#include <SDL2/SDL.h>
#include <list>
#include <string>

enum BoxTypes
{
  BOX_OF_BOX = 0,
  BOX_OF_TEXT = 1,
  BOX_OF_SPRITE = 2
};

class WindaBox
{
  public:
    WindaBox(SDL_Rect* box, SDL_Color* fill_color, SDL_Color* outline_color, BoxTypes type);
    ~WindaBox();
    void Draw(SDL_Renderer* renderer, SDL_Rect* clip);
    void SetFillColor(SDL_Color* fill_color);
    void SetOutlineColor(SDL_Color* outline_color);
    void Change_Box(SDL_Rect* box);
    SDL_Color* GetFillColor();
    SDL_Color* GetOutlineColor();
    SDL_Rect* GetBox();
    void SetZ();
    int* GetZ();
    BoxTypes GetType();
  protected:
    BoxTypes type;
    SDL_Rect* rect_;
    SDL_Color* fill_color_;
    SDL_Color* outline_color_;
    int* z;
};

class WindaBoxOfBox : public WindaBox
{
  public:
    void Draw(SDL_Renderer* renderer, SDL_Rect* clip);
    std::list<WindaBox>* GetInnerBoxes();
    void AddWindaBox(WindaBox);
  private:
    std::list<WindaBox>* inner_boxes_;
};

class WindaBoxOfText : public WindaBox
{
  public:
    void Draw(SDL_Renderer* renderer, SDL_Rect* clip);
    void SetTextColor(SDL_Color* color);
    std::string GetText();
  private:
    SDL_Color* text_color_;
    std::string text;
};

class WindaBoxOfSprite : public WindaBox
{
  public:
    void Draw(SDL_Renderer* renderer, SDL_Rect* clip);
    void SetClip(SDL_Rect* clip);
  private:
    SDL_Rect* clip;
};

class WindaBoxer
{
  public:
    static void AddBox(WindaBox* box);
    static void DeleteBox(WindaBox* box);
    static WindaBox* CreateBox(BoxTypes type, SDL_Rect* box, SDL_Color* fill_color,
                                SDL_Color* outline_color, short* z);
    static void CloseAllBoxes();
    static void Draw();
  private:
    // NOTE: To access all windws you must look at inner_boxes_ of BoxofBox.
    static std::list<WindaBox> boxes;
};

#endif // CODE_NAME_WINDA_BOX_H
