//
// Created by Max Grucella on 7/12/17.
//

#include "repeat_event.h"

#include <SDL2/SDL_timer.h>
#include <iostream>

bool RepeatEvent::Run()
{
  int time_to_next = delay_ * (times_repeated_ + 1) + mili_time_stamp_;
  if (SDL_GetTicks() >= time_to_next)
  {
    std::cout << " time diff: " << SDL_GetTicks() - delay_ * (times_repeated_) - mili_time_stamp_;
    item_ = callback_(item_, this);
    if (item_ == nullptr)
    {
      std::cout << "\n Ended event!!";
      return true;
    }
    times_repeated_++;
  }

  return times_to_be_repeated_ == times_repeated_;
}

RepeatEvent::RepeatEvent(std::function<void*(void*, RepeatEvent*)> callback,
                         int times_to_be_repeated, int delay_mili, void* item)
{
  times_to_be_repeated_ = times_to_be_repeated;
  callback_ = callback;
  times_repeated_ = 0;
  delay_ = delay_mili;
  mili_time_stamp_ = SDL_GetTicks();
  item_ = item;
}

int RepeatEvent::GetTimesRepeated()
{
  return times_repeated_;
}

int RepeatEvent::GetTimesThatWillRepeat()
{
  return times_to_be_repeated_;
}

int RepeatEvent::GetDelay()
{
  return delay_;
}

RepeatEvent::~RepeatEvent()
{
  item_ = nullptr;
}

void RepeatEvent::SetCanceled()
{
  item_ = nullptr;
}

void RepeatEvent::Replay()
{
  mili_time_stamp_ = SDL_GetTicks();
  times_repeated_ = 0;
}
