//
// Created by Max Grucella on 6/30/17.
//

#include "../info_packet.h"

bool SayHelloHandler(InfoPacket *info)
{
  printf("Hello %s", "frank");
  return true;
}

int main()
{
  auto handler = SayHelloHandler;
  auto event = new InfoPacket();

  InfoManager::AddHandler(0, handler);
  InfoManager::AddEvent(0, event);

  InfoManager::HookHandler(0 , 0);

  InfoManager::ThrowEvent(0, handy::Priority::NORMAL);

  InfoManager::RunActiveEvents();

  return 0;
}
