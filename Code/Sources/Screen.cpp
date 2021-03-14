#include "../Headers/Screen.hpp"

#include <iostream>

#include "../Headers/Math.hpp"
#include "../Headers/Function.hpp"

SDL_Renderer* Screen::renderer;
SDL_Window* Screen::window;

short Screen::width(500);
short Screen::height(500);

double fonction_TEST(const double &x) { return x; }

void Screen::Quit() {

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

void Screen::Init() {

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Courbe",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,0,-1);
    
    /*constexpr*/ SDL_Rect LineH{0,height/2,width,1},LineV{width/2,0,1,height};

    SDL_SetRenderDrawColor(renderer,255,255,255,255);

    SDL_RenderFillRect(renderer,&LineH);
    SDL_RenderFillRect(renderer,&LineV);
    SDL_RenderPresent(renderer);

    Screen::Launch();

}

void Screen::Launch() {

    SDL_Event event;
    Function f({0,0},{0,0,0,0},&fonction_TEST);

    for (double x = 0;x < width;x+=0.01) {

        f.Draw(x);

        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) Screen::Quit();

    }

    //SDL_SetRenderDrawColor(renderer,0,0,0,0);

    do SDL_WaitEvent(&event); while (event.type != SDL_QUIT);
    Screen::Quit();

}