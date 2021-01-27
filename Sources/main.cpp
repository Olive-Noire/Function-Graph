#include <SDL.h>

double f(double x);

int main(int argc,char* argv[]) {

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("Courbe",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,500,500,SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,0,-1);

    int widht,height;
    SDL_GetRendererOutputSize(renderer,&widht,&height);
    SDL_Rect LineH = {0,height/2,widht,1};
    SDL_Rect LineV = {widht/2,0,1,height};

    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderFillRect(renderer,&LineH);
    SDL_RenderFillRect(renderer,&LineV);
    SDL_RenderPresent(renderer);

    int last[2] = {-1,height-1};
    SDL_Event event;

    for (double x = 0;x < widht;x+=0.1) {

        int abscisse(x),ordonne(height/2-f(x-widht/2));

        if (ordonne > 0 && ordonne < height) {
        
            if (last[0] != abscisse || last[1] != ordonne) {

                SDL_Rect Point = {abscisse,ordonne,1,1};
                SDL_RenderFillRect(renderer,&Point);
                SDL_RenderPresent(renderer);
                last[0] = abscisse;
                last[1] = ordonne;

            }

        }

        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) x=widht;

    }

    SDL_SetRenderDrawColor(renderer,0,0,0,0);

    do SDL_WaitEvent(&event); while (event.type!=SDL_QUIT);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

double f(double x) {

    return x;

}

// Command : g++ -m32 ./Sources/*cpp -o bin/Courbe -s -std=c++17 -I include -L lib/ -lSDL2main -lSDL2 -mwindows
