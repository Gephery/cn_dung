//
// Created by Max Grucella on 6/17/17.
//

#ifndef CODE_NAME_MOB_H
#define CODE_NAME_MOB_H


#include <list>
#include <SDL2/SDL_surface.h>
#include "../items/item.h"

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
    void SetLevel(const int level);

    int GetDamage(const int amount);
    int GetHealth(const int amount);
    bool IsDead();

    std::list<double>** GetMobTypeFriends();
    std::list<double>** GetMobTypeEnemies();

    class Inventory
    {
    public:

    private:
        std::list<SDL_Surface>* model_;

    };


private:
    int* health_max_;
    int* health_current_;
    int* magic_max_;
    int* magic_current_;
    int* movement_speed_;
    int* sprint_speed_;
    int* jump_height_;
    int* level_;
    std::list<double>* friend_types_;
    std::list<double>* enemy_types_;
    std::list<double>* abilities;
    std::list<SDL_Surface>* model_;

    //Attack damage determined by inventory and selected weapon

    // Inventory is a set size and does not change but empty spaces are tracked.
    Inventory* inventory_;
    //TODO add ability pouch
};


#endif //CODE_NAME_MOB_H
