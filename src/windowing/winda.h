#ifndef CODE_NAME_GAME_WINDA_H
#define CODE_NAME_GAME_WINDA_H


#include <SDL2/SDL.h>
class BaseBox;
class Mouse;

/**
  * Acts as a single contact to access any windowing part.
  *
  * All functions can be accessed anywhere. Windows should be handled by it, so only retrive
  * a component if you want to change it, and if there is a function use it instead.
  */
class Winda
{
  public:
    /** Initializes the components necessary for using Game Winda. To be used before the main game loop. */
    static bool Init();

    /** Quits out all the necessary things to stop GameWina things. */
    static void Quit();

    /** Get the window but do not change the pointer. */
    static SDL_Window *GetWindow();

    /** Get the surface but do not change the pointer. */
    static SDL_Renderer *GetRenderer() { return renderer_; }

    static int GetWindaWidth();

    static int GetWindaHeight();

    static BaseBox *GetSelectedBox();

    static void SetSelectedBox(BaseBox *box);
    static Mouse* GetPlayer();
    static void SetPlayer(Mouse* player);

    static bool keyboard_focused_;
    static bool mouse_focused_;
    static bool minimized_;
  protected:
    static SDL_Window *main_window_; // Seen as the thing that holds everything.
    static SDL_Renderer *renderer_;
    static int *screen_width_;
    static int *screen_height_;
    static BaseBox *selected_;
    static Mouse* player_;
};

#endif //CODE_NAME_GAME_WINDA_H
