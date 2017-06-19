//
// Created by Max Grucella on 6/17/17.
//

#ifndef CODE_NAME_MOB_H
#define CODE_NAME_MOB_H


#include <list>
#include <SDL2/SDL_surface.h>
#include "../items/item.h"
#include "../util/m_uuid.h"

class Mob
{
public:
    // Will return the reference to that slot, but if out of
    // bounds will and if empty will return null.
    Item** GetItemCell(const int index) { return  }

    Inventory** GetInventory() { return &this->inventory_; }

    int GetCurrentHealth() { return *this->health_current_; }
    int GetMaxHealth() { return *this->health_max_; }
    void AddHealth(const int health);
    void SetMaxHealth(const int new_health) { *(this->health_max_) = new_health; }

    int GetCurrentMagic() { return *this->magic_current_; }
    int GetMaxMagic() { return *this->magic_max_; }
    void AddMagic(const int new_magic);
    void SetMaxMagic(const int max) { *(this->magic_max_) = max; }

    int GetMovementSpeed() { return *this->movement_speed_; }
    void SetMovementSpeed(const int speed) { *(this->movement_speed_) = speed; }

    int GetLevel() { return *this->level_; }
    void SetLevel(const int level) { *(this->level_) = level; }

    int GetDamage(const int amount) { inventory_.getDamge(); }
    int GetHealth(const int amount) { return *(health_current_); }
    bool IsDead() { return health_current_ == 0; };

    std::list<MUid>** GetMobTypeFriends() { return &friends_; }
    std::list<MUid>** GetMobTypeEnemies() { return &enemies_; }

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
    int* level_;
    std::list<MUid>* friends_;
    std::list<MUid>* enemies_;
    std::list<SDL_Surface>* model_;

    // Inventory is a set size and does not change but empty spaces are tracked.
    Inventory* inventory_;
    //TODO add ability pouch
};


#endif //CODE_NAME_MOB_H
