//
// Created by Max Grucella on 6/17/17.
//

#ifndef CODE_NAME_MOB_H
#define CODE_NAME_MOB_H


#include <list>
#include <SDL2/SDL_surface.h>
#include <SDL2_image/SDL_image.h>
#include <map>
#include "../items/item.h"
#include "../flat_buffers/sprite_generated.h"
#include "../windowing/base_box.h"
#include "../windowing/box_types/sprite_area.h"

class Action
{
public:
  Action(dung::sprite::ActionPacket action_unpacked);
  Action(SDL_Rect frames, short action_code, short action_lock, short action_speed);
private:
  std::list<SDL_Rect> frames_;
  short action_code_;
  short action_lock_;
  short action_speed_;
};

class MobberPart
{
public:
  MobberPart(dung::sprite::SpriPart);
  MobberPart(unsigned int part_code, SDL_Texture* img_, std::map<short, Action*> actions,
             int health_contra, int armour_contra_, int damage_contra, int magic_contra,
             int movement_contra_, int sprint_contra, int jump_contra, int evil_contra,
             int relative_x, int relative_y, unsigned int abilities[]);
private:
  unsigned int part_code_;
  SDL_Texture* img_;
  std::map<short, Action*> actions_;

  int health_contra_;
  int armour_contra_;
  int damage_contra_;
  int magic_contra_;
  int movement_contra_;
  int sprint_contra_;
  int jump_contra_;
  int evil_contra_;

  int relative_x_;
  int relative_y_;

  std::list<unsigned int> abilities_;

};

class Mob
{
  public:
    // Will return the reference to that slot, but if out of
    // bounds will and if empty will return null.

    int GetCurrentHealth();
    int GetMaxHealth();
    void AddHealth(const int health);
    void SetMaxHealth(const int new_health);
    void TakeHealth(const int damage);

    // Magic related things
    int GetCurrentMagic();
    int GetMaxMagic();
    void AddMagic(const int new_magic);
    void SetMaxMagic(const int max);
    void takeMagic(const int used_magic);

    int GetMovementSpeed();
    void SetMovementSpeed(const int speed);

    int GetLevel();
    void IncrementLevel();
    void SetLevel(const int level);

    int GetDamage(const int amount);
    int GetHealth(const int amount);
    bool IsDead();

    std::list<unsigned short>* GetMobTypeFriends();
    std::list<unsigned short>* GetMobTypeEnemies();
  private:
    std::string name;
    unsigned int mob_code;
    int health_max_;
    int health_current_;
    int damage_;
    int armour_;
    int magic_max_;
    int magic_current_;
    int movement_speed_;
    int sprint_speed_;
    int jump_height_;
    int evil_;
    int level_;

    std::set<unsigned int>* abilities_;
    std::list<MobberPart*> parts_;

    BoxOfSprite* draw_place_;

    // TODO add inventory
};


class MobManager
{
  public:
    static bool Load();
    static Mob* CreateMob(unsigned int mob_code);

    static bool SaveMob(Mob* mob);
  private:
    static bool LoadMobParts();
    static bool LoadMobs();
};


#endif //CODE_NAME_MOB_H
