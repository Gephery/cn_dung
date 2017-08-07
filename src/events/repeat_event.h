//
// Created by Max Grucella on 7/12/17.
//

#ifndef CODE_NAME_REPEAT_EVENT_H
#define CODE_NAME_REPEAT_EVENT_H


#include <functional>
#include <SDL2/SDL_quit.h>

class MainInfoManager;

class RepeatEvent
{
  public:
    RepeatEvent(std::function<void*(void*, RepeatEvent*)> callback,
                int times_to_be_repeated, int delay_mili, void* item);
    ~RepeatEvent();
    bool Run();
    int GetTimesRepeated();
    int GetTimesThatWillRepeat();
    int GetDelay();
    void SetCanceled();
    void Replay();

    friend class MainInfoManager;
  private:
    std::function<void*(void*, RepeatEvent*)> callback_;
    void* item_;
    int times_to_be_repeated_;
    int times_repeated_;
    int delay_;
    int mili_time_stamp_;
};


#endif //CODE_NAME_REPEAT_EVENT_H
