#ifndef DEF_CLASS_SCREEN_HPP
#define DEF_CLASS_SCREEN_HPP

#include <SDL.h>

class Screen {

    public:
    static void Quit();
    static void Init();
    static void Launch();

    static SDL_Renderer* renderer;
    static SDL_Window* window;

    static short width;
    static short height;


};

#endif //DEF_CLASS_SCREEN_HPP