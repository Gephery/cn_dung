#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "headers/sprite.h"

bool init(SDL_Window** g_window, SDL_Surface** g_surface, char game_nickname[], int** screen_width, int** screen_height);
void quit(SDL_Window* g_window, SDL_Surface* g_surface);

int main(void)
{
    int* screen_width = nullptr;
    int* screen_height = nullptr;
    char game_nickname[] = "CN Dung";

    SDL_Window* g_window = nullptr;
    SDL_Surface* g_surface = nullptr;
    SDL_GLContext context;

    // Testing zone
    bool yea = init(&g_window, &g_surface, game_nickname, &screen_width, &screen_height);
    //Testing ZONE---------------------------------------


    //End testing Zone------------------------------------
    if (yea) {

        // Way the game can stop
        // NOTE: Game may not close as fast as window, may do background stuff first.
        bool running = true;
        SDL_Event event;

        while (running) {
            // Only run if there is an event waiting to be checked.
            // TODO add more event handling for user input
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    running = false;
                    quit(g_window, g_surface);
                    break;
                }
            }
        }
    }
    return 0;
}

// Starts up libraries and hooks into major things such as window.
bool init(SDL_Window** g_window, SDL_Surface** g_surface,
           char game_nickname[], int** screen_width, int** screen_height)
{
    bool success = SDL_Init(SDL_INIT_EVERYTHING) == 0;

    if (success) {
        Uint32 sld_flags = SDL_WINDOW_OPENGL | // Telling it there will be openGL.
                       SDL_WINDOW_RESIZABLE |
                       SDL_WINDOW_SHOWN |
                       SDL_WINDOW_MAXIMIZED; // Window starts maximized

        *g_window = SDL_CreateWindow(game_nickname, 0, 0, 0, 0, sld_flags);

        success = g_window != NULL; // Check if window creation a success

        // SDL libs inits
        if (success)
        {
            SDL_GetWindowSize(*g_window, *screen_width, *screen_height); // Sets up easy access w and h.

            *g_surface = SDL_GetWindowSurface(*g_window);
            success = g_surface != NULL;
            SDL_SetWindowResizable(*g_window, SDL_FALSE);
        }
        if (!success)
            printf("Error in starting SDL: %s ", SDL_GetError());

        // SDL_image init
        if (success)
        {
            int img_flags = IMG_INIT_PNG;
            bool img_init_succ = (IMG_Init(img_flags)&img_flags) == img_flags;
            if (!img_init_succ)
                printf("Error in starting SDL_IMG: %s", IMG_GetError());
            success &= img_init_succ;
        }
    }

    if (success) printf("Successful load of SDL and SDL_image.");
    return success;
}

// Quits out all the libraries and does major garbage collection.
void quit(SDL_Window* g_window, SDL_Surface* g_surface) {
    SDL_DestroyWindow(g_window);
    g_window = NULL;
    SDL_FreeSurface(g_surface);

    IMG_Quit();
    SDL_Quit();
}
