//
// Created by Max Grucella on 6/26/17.
//
#include "layer_manager.h"

#include <iostream>
#include "winda.h"
#include "../events/main_info_manager.h"
#include "box_types/layer.h"
#include "../events/built_in_packets/click_packet.h"

std::map<int, std::list<Layer*>> LayerManager::z_to_layers_;

void LayerManager::RegisterBox(Layer* box)
{
  z_to_layers_[box->GetZ()].push_back(box);
}

void LayerManager::Draw()
{
  for (auto it = z_to_layers_.begin(); it != z_to_layers_.end(); ++it)
  {
    for (auto item : it->second)
    {
      item->Draw();
    }
  }
}

void LayerManager::DrawFullNClean()
{
  SDL_SetRenderDrawColor(Winda::GetRenderer(), 255, 255, 255, 255);
  SDL_RenderClear(Winda::GetRenderer());
  LayerManager::Draw();
  SDL_RenderPresent(Winda::GetRenderer());
}

void LayerManager::ChangeOfY(Layer* container, BaseBox *box, int new_y)
{
  container->ChangeOfY(box, new_y);
}

void LayerManager::ChangeOfZ(Layer* layer, int new_z)
{
  auto yer = z_to_layers_[layer->GetZ()];
  std::remove(yer.begin(), yer.end(), layer);

  layer->UnsafelySetZ(new_z);
  RegisterBox(layer);
}

void LayerManager::HuntClick(int x, int y) {
  ClickEvent* click = new ClickEvent();
  click->x = x;
  click->y = y;
  for (auto it = z_to_layers_.rbegin(); it != z_to_layers_.rend(); it++)
  {
    for (auto layer : it->second)
    {
      click = layer->HuntInnerBox(click);
      if (click->fully_set)
        MainInfoManager::ThrowEvent(click, handy::Priority::NORMAL);
    }
  }
}

std::list<Layer *> LayerManager::GetLayer(int z)
{
  return z_to_layers_[z];
}

LayerManager::~LayerManager()
{
  for (auto collec : z_to_layers_)
  {
    for (auto trash : collec.second)
    {
      delete(trash);
    }
  }
}


