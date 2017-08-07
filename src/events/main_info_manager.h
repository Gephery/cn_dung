#ifndef CODE_NAME_INFO_MANAGER_H
#define CODE_NAME_INFO_MANAGER_H

#include <SDL2/SDL.h>
#include <map>
#include <list>

class HandyHandler;
class RepeatEvent;
class InfoPacket;

namespace handy
{
  enum Priority
  {
    HIGH, NORMAL
  };

  enum DefaultEvents
  {
    E_CLICK_ONCE = 1,
    E_KEYBOARD_PRESS = 2,
    E_MOVE_MOB = 3
  };

  enum DefaultHandlers
  {
    H_CLICK_ONCE_TEST = 1,
    H_KEYBOARD_MOVE_PLAYER = 2
  };
}

class MainInfoManager
{
  public:
    ~MainInfoManager();
    static void AddHandler(HandyHandler* handy);
    static int HandleEvent(SDL_Event* event);

    static void HookHandler(int event_code, handy::Priority priority, int handler_code);
    static void DehookHandler(int event_code, int handler_code);

    static void ThrowEvent(InfoPacket* info, handy::Priority priority);
    static void ThrowRepeatEvent(RepeatEvent* event);

    static void RunActiveEvents();

    static bool running;
  protected:
    static std::map<int, HandyHandler*> code_to_handler_;
    static std::map<int, std::list<int>> event_code_to_handler_code_;
    static std::list<InfoPacket*> active_events_;
    static std::list<RepeatEvent*> active_rp_events_;
};

#endif // CODE_NAME_INFO_MANAGER_H
