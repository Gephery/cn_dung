//
// Created by Max Grucella on 7/14/17.
//

#include "world_manager.h"

#include "../mob/point_of_contact.h"
#include "../mob/mob.h"

ReallocationList<Mob*> WorldManager::mob_map_;
//ReallocationList<WorldObject*> WorldManager::object_map_;

std::map<int, std::map<int, ReallocationList<int>>> WorldManager::map_of_mobs_;
std::map<int, std::map<int, ReallocationList<int>>> WorldManager::map_of_objects_;

int WorldManager::tile_size_;
int WorldManager::tile_width_;
int WorldManager::tile_height_;

void WorldManager::Init(int tile_size, int tile_width, int tile_height)
{
  tile_size_ = tile_height;
  tile_width_ = tile_width;
  tile_height_ = tile_height;
}

unsigned long WorldManager::RegisterMob(Mob* mob)
{
  ReallocationList<POfContact> mobs_pocs;

  int lower_x = mob->GetX();
  int upper_x = lower_x + mob->GetWidth();

  int lower_y = mob->GetY();
  int upper_y = lower_y + mob->GetHeight();

  for (int x_index = lower_x; x_index <= upper_x ; x_index += tile_size_)
  {
    for (int y_index = lower_y; y_index <= upper_y; ++y_index += tile_size_)
    {
      POfContact local_poc = GetTileIn(x_index, y_index);


      //mobs_pocs.Add(local_poc);
    }
  }

  return (mob_map_).Add(mob);
}

POfContact WorldManager::GetTileIn(int x, int y)
{
  int x_tile = x / tile_size_;
  int y_tile = y / tile_size_;

  POfContact poc = {x_tile, y_tile, x, y, nullptr};
  poc.x_box_ = x_tile;
  poc.y_box_ = y_tile;
  poc.x_ = x;
  poc.y_ = y;
  return poc;
}

int WorldManager::GetTileSize()
{
  return tile_size_;
}
