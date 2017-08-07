//
// Created by Max Grucella on 6/17/17.
//

#ifndef CODE_NAME_MOB_H
#define CODE_NAME_MOB_H

#include <string>
#include <SDL2/SDL_rect.h>
#include <list>
#include <SDL2/SDL_system.h>
#include "../util/reallocation_list.h"

class RepeatEvent;
class BoxOfSprite;
class BoxOfText;
class Layer;
class POfContact;

class Mob
{
  public:
    Mob(std::string name, Layer* layer, SDL_Point* top_left, std::string asset_path);
    ~Mob();
    void Move(int current_frame);

    int GetDx();
    int GetDy();
    void SetDx(int dx);
    void SetDy(int dy);

    int IsAnimating();
    void SetAnimating(RepeatEvent* event);
    void SetOrientation(int animation_code);
    void StopAnimation();

    int GetX();
    int GetY();
    int GetHeight();
    int GetWidth();

    SDL_Keysym GetLastBPressed();
    void SetBPressed(SDL_Keysym butt);

    void UpdatePOCS();
    std::list<POfContact*> GetPOfContacts();

    void ChangeDrawRect(int current_frame);
  protected:

    ReallocationList<int> pocs_;
    Layer* owning_layer_;
    int dx_;
    int dy_;
    BoxOfText* name_;
    BoxOfSprite* draw_area_;

    RepeatEvent* current_motion_;
    int mob_dynamic_id;
    SDL_Keysym last_b_pressed_;
    int motion_;
    int orientation_;
    bool cancel_mo_event_;
};


#endif //CODE_NAME_MOB_H
