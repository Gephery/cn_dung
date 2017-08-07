//
// Created by Max Grucella on 7/1/17.
//
#include "main_info_manager.h"

#include <iostream>
#include "info_packet.h"
#include "../windowing/layer_manager.h"
#include "handy_handler.h"
#include "repeat_event.h"
#include "../windowing/winda.h"
#include "built_in_packets/keyboard_packet.h"
#include "built_in_packets/move_mob_packet.h"

std::map<int, HandyHandler*> MainInfoManager::code_to_handler_;
std::map<int, std::list<int>> MainInfoManager::event_code_to_handler_code_;
std::list<InfoPacket*> MainInfoManager::active_events_;
bool MainInfoManager::running = true;
std::list<RepeatEvent*> MainInfoManager::active_rp_events_;

void MainInfoManager::HookHandler(int event_code, handy::Priority priority, int handler_code)
{

  if (priority == handy::Priority::HIGH)
  {
    event_code_to_handler_code_[event_code].push_front(handler_code);

  }
  else
  {
    event_code_to_handler_code_[event_code].push_back(handler_code);
  }
}

void MainInfoManager::ThrowEvent(InfoPacket* info, handy::Priority priority)
{
  if (priority == handy::Priority::HIGH)
  {
    active_events_.push_front(info);
  }
  else
  {
    active_events_.push_back(info);
  }
}

void MainInfoManager::RunActiveEvents()
{
  // Go through the repeating events.
  std::list<RepeatEvent*> new_list_of_rp_event;
  for (auto event : active_rp_events_)
  {
    if (event->item_ != nullptr && !event->Run())
    {
      new_list_of_rp_event.push_back(event);
    } else
    {
      std::cout << "\n Deleted Event!";
      delete(event);
    }
  }
  active_rp_events_ = new_list_of_rp_event;

  // Go through static one off events that don't have to be used.
  for (auto event : active_events_)
  {
    bool is_canceled = false;
    auto handlers = event_code_to_handler_code_[event->GetEventCode()];
    auto handler = handlers.begin();
    while (handler != handlers.end() && !is_canceled)
    {
      auto real_h = code_to_handler_[*handler];
      if (!real_h->main(event))
      {
        is_canceled = true;
      }
      ++handler;
    }
    delete(event);
  }
  active_events_.clear();
}

int MainInfoManager::HandleEvent(SDL_Event *event)
{
  switch (event->type)
  {
    case SDL_QUIT:
    {
      running = false;
      Winda::Quit();
      break;
    }
    case SDL_MOUSEBUTTONDOWN:
    {
      SDL_MouseButtonEvent *mous_e = (SDL_MouseButtonEvent *) event;
      LayerManager::HuntClick(mous_e->x, mous_e->y);
      break;
    }
    case SDL_KEYDOWN:
    {
      MoveMobPacket *pack = new MoveMobPacket();
      pack->sym = event->key.keysym;
      pack->mob = Winda::GetPlayer();
      MainInfoManager::ThrowEvent(pack, handy::Priority::NORMAL);
      break;
    }
  }
  return 0;
}

void MainInfoManager::AddHandler(HandyHandler *handy)
{
  code_to_handler_[handy->GetHandlerCode()] = handy;
}

void MainInfoManager::DehookHandler(int event_code, int handler)
{
  auto list = event_code_to_handler_code_[event_code];
  list.remove(handler);
}

void MainInfoManager::ThrowRepeatEvent(RepeatEvent *event)
{
  active_rp_events_.push_back(event);
}

MainInfoManager::~MainInfoManager()
{
  for (auto trash : code_to_handler_)
  {
    delete(trash.second);
  }

  for (auto trash : active_events_)
  {
    delete(trash);
  }

  for (auto trash : active_rp_events_)
  {
    delete(trash);
  }
}
