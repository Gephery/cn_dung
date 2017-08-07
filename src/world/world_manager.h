//
// Created by Max Grucella on 7/14/17.
//

#ifndef CODE_NAME_WORLD_MANAGER_H
#define CODE_NAME_WORLD_MANAGER_H

#include <list>
#include <map>
#include "../util/reallocation_list.h"

class Layer;
class Mob;
class POfContact;

enum DefaultPOCTypes
{
  FOOT = 0,
  MIDDLE = 1,
  HEAD = 2
};

class WorldManager
{
  public:
    static void Init(int tile_size, int tile_width, int tile_height);

    static unsigned long RegisterMob(Mob* mob);

    //static void RegisterWorldObject(WorldObject* object, bool front);

    static int GetTileSize();
    static int GetTilesWide();
    static int GetTilesHeight();

    static int MoveMob(Mob* mob);
    //static int MoveObject(WorldObject* object);
    static POfContact GetTileIn(int x, int y);
    static void DisposeOfPOfContacts(std::list<POfContact*> pocs);

    friend class Mob;
  private:
    static void ClearTilesOf(Mob* mob);

    static ReallocationList<Mob*> mob_map_;
    //static ReallocationList<WorldObject*> object_map_;

    static std::map<int, std::map<int, ReallocationList<int>>> map_of_mobs_;
    static std::map<int, std::map<int, ReallocationList<int>>> map_of_objects_;

    static int tile_size_;
    static int tile_width_;
    static int tile_height_;
};


#endif //CODE_NAME_WORLD_MANAGER_H
