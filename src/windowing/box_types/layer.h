//
// Created by Max Grucella on 7/2/17.
//

#ifndef CODE_NAME_LAYER_H
#define CODE_NAME_LAYER_H

#include <list>
#include <map>
#include "../base_box.h"
#include "../../events/built_in_packets/click_packet.h"


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
    void UnsafelySetZ(int new_z);
    int GetZ();
    Layer(SDL_Rect* rect, SDL_Point* center, int z);
    virtual void Draw();
    virtual ~Layer();
    std::map<int, std::list<BaseBox*>>  GetInnerBoxes();
    void AddWindaBox(BaseBox* box);
    void ChangeOfY(BaseBox* box, int new_y);
    void SetHeight(int height);
    void SetWidth(int width);
    ClickEvent* HuntInnerBox(ClickEvent *click);
    bool scalable_;
  private:
    std::map<int, std::list<BaseBox*>> inner_boxes_;
    SDL_Color* fill_color_;
    SDL_Color* outline_color_;
    int z_; /** Is the order at which it is drawn. */
};

#endif //CODE_NAME_LAYER_H
