//
// Created by Max Grucella on 7/17/17.
//

#include "point_of_contact.h"

POfContact::POfContact(int x_tile, int y_tile, int x, int y, Mob *mob)
{
  x_box_ = x_tile;
  y_box_ = x_tile;
  x_ = x;
  y_ = y;
  mob_ = mob;
  type_ = 0;
}

bool POfContact::operator==(const POfContact &other) const
{
  return x_box_ == other.x_box_ &&
          y_box_ == other.y_box_ &&
          x_ == other.x_ &&
          y_ == other.y_ &&
          type_ == other.type_;
}
