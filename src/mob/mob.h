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

    int GetCurrentHealth() { return *this->health_current_; }
    int GetMaxHealth() { return *this->health_max_; }
    void AddHealth(const int health);
    void SetMaxHealth(const int new_health) { *(this->health_max_) = new_health; }
    void TakeHealth(const int damage);

    // Magic related things
    int GetCurrentMagic() { return *this->magic_current_; }
    int GetMaxMagic() { return *this->magic_max_; }
    void AddMagic(const int new_magic);
    void SetMaxMagic(const int max) { *(this->magic_max_) = max; }
    void takeMagic(const int used_magic);

    int GetMovementSpeed() { return *this->movement_speed_; }
    void SetMovementSpeed(const int speed) { *(this->movement_speed_) = speed; }

    int GetLevel() { return *this->level_; }
    void SetLevel(const int level) { *(this->level_) = level; }

    int GetDamage(const int amount);
    int GetHealth(const int amount) { return *(health_current_); }
    bool IsDead() { return health_current_ == 0; }

    std::list<double>** GetMobTypeFriends() { return &friend_types_; }
    std::list<double>** GetMobTypeEnemies() { return &enemy_types_; }

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
