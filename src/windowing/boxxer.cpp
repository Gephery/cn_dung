//
// Created by Max Grucella on 6/26/17.
//
#include <list>
#include <iostream>
#include "base_box.h"
#include "boxxer.h"
#include "winda.h"
#include "../events/main_info_manager.h"
#include "../events/handy.h"

std::map<int, std::list<Layer*>> Boxxer::z_to_layers_;

void Boxxer::RegisterBox(Layer* box)
{
  z_to_layers_[box->GetZ()].push_back(box);
}

void Boxxer::Draw()
{
  for (auto it = z_to_layers_.begin(); it != z_to_layers_.end(); ++it)
  {
    for (auto item : it->second)
    {
      item->Draw();
    }
  }
}

void Boxxer::DrawFullNClean()
{
  SDL_SetRenderDrawColor(Winda::GetRenderer(), 255, 255, 255, 255);
  SDL_RenderClear(Winda::GetRenderer());
  Boxxer::Draw();
  SDL_RenderPresent(Winda::GetRenderer());
}

void Boxxer::ChangeOfY(Layer* container, BaseBox *box, int new_y)
{
  container->ChangeOfY(box, new_y);
}

void Boxxer::ChangeOfZ(Layer* layer, int new_z)
{
  auto yer = z_to_layers_[layer->GetZ()];
  std::remove(yer.begin(), yer.end(), layer);

  layer->UnsafelySetZ(new_z);
  RegisterBox(layer);
}

void Boxxer::HuntClick(int x, int y) {
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


