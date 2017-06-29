//
// Created by Max Grucella on 6/26/17.
//

#include "base_box.h"

std::map<int, std::list<BaseBox*>> Boxxer::boxes_;

void Boxxer::RegisterBox(Layer* box)
{
  boxes_[box->GetZ()].push_back(box);
}

void Boxxer::Draw()
{
  for (auto it = boxes_.begin(); it != boxes_.end(); ++it) 
  {
    for (auto item : it->second)
    {
      item->Draw();
    }
  }
}

void Boxxer::DrawFullNClean()
{
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
  auto yer = boxes_[layer->GetZ()];
  std::remove(yer.begin(), yer.end(), layer);

  layer->SetZ(new_z);
  RegisterBox(layer);
}


