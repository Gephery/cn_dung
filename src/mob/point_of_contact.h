//
// Created by Max Grucella on 7/17/17.
//

#ifndef CODE_NAME_POINT_OF_CONTACT_H
#define CODE_NAME_POINT_OF_CONTACT_H

class Mob;

class POfContact
{
  public:
    POfContact(int x_tile, int y_tile, int x, int y, Mob* mob);
    int x_box_;
    int y_box_;
    int x_;
    int y_;
    Mob* mob_;
    int type_;

    bool operator==(const POfContact &other) const;
  private:
};


#endif //CODE_NAME_POINT_OF_CONTACT_H
