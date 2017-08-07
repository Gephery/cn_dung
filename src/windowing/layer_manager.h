//
// Created by Max Grucella on 7/2/17.
//

#ifndef CODE_NAME_BOXXER_H
#define CODE_NAME_BOXXER_H

#include <map>
#include <list>

class Layer;
class BaseBox;

/**
  * Use this to access all winda boxes.
  *
  * This should be used to create destroy and draw all boxes.
  */
class LayerManager
{
  public:
    ~LayerManager();
    static void RegisterBox(Layer* box);
    static void Draw();
    static void DrawFullNClean();
    static void ChangeOfY(Layer* container, BaseBox* box, int new_y);
    static void ChangeOfZ(Layer* layer, int new_z);
    static void HuntClick(int x, int y);
    static std::list<Layer*> GetLayer(int z);
  private:
    // NOTE: To access all windows you must look at inner_boxes_ of BoxofBox.
    static std::map<int, std::list<Layer*>> z_to_layers_;
};

#endif //CODE_NAME_BOXXER_H
