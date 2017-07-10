//
// Created by Max Grucella on 7/1/17.
//

#include <functional>
#include <string>
#include <list>
#include <map>
#include <iostream>
#include "handy.h"
#include "info_packet.h"
#include "main_info_manager.h"
#include "../windowing/winda.h"
#include "../windowing/boxxer.h"
#include "handy_handler.h"

std::map<int, HandyHandler*> MainInfoManager::code_to_handler_;
std::map<int, std::list<int>> MainInfoManager::event_code_to_handler_code_;
std::list<InfoPacket*> MainInfoManager::active_events_;
bool MainInfoManager::running = true;

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
  }
  active_events_.clear();
}

int MainInfoManager::HandleEvent(SDL_Event *event)
{
  switch (event->type)
  {
    case SDL_QUIT:
      running = false;
      Winda::Quit();
      break;
    case SDL_MOUSEBUTTONDOWN:
      SDL_MouseButtonEvent* mous_e = (SDL_MouseButtonEvent*) event;
      Boxxer::HuntClick(mous_e->x, mous_e->y);
      break;
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
