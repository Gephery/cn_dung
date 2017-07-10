#ifndef CODE_NAME_INFO_MANAGER_H
#define CODE_NAME_INFO_MANAGER_H

#include <SDL2/SDL.h>
#include "handy.h"

class HandyHandler;

class MainInfoManager
{
  public:
    static void AddHandler(HandyHandler* handy);
    static int HandleEvent(SDL_Event* event);

    static void HookHandler(int event_code, handy::Priority priority, int handler_code);
    static void DehookHandler(int event_code, int handler_code);

    static void ThrowEvent(InfoPacket* info, handy::Priority priority);

    static void RunActiveEvents();

    static bool running;
  protected:
    static std::map<int, HandyHandler*> code_to_handler_;
    static std::map<int, std::list<int>> event_code_to_handler_code_;
    static std::list<InfoPacket*> active_events_;
};

#endif // CODE_NAME_INFO_MANAGER_H
