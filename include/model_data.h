//
// Created by Max Grucella on 6/15/17.
//

#ifndef CODE_NAME_MODEL_DATA_H
#define CODE_NAME_MODEL_DATA_H

enum Layer
{
    background, // The map and what not
    mid_ground, // For player, items, and other things their order will be det/ by y pos.
    foreground, // Things like pillars which are always on top.
    UI, // User interface
};

#endif //CODE_NAME_MODEL_DATA_H
