#include <SDL.h>

#include "../Headers/Screen.hpp"

int main(int argc,char* argv[]) {

    Screen::Init();

    return 0;
}

// Command : g++ -m32 ./Sources/*cpp ./Sources/Externals/*cpp ./Sources/Headers/*hpp -o bin/Courbe -s -std=c++17 -I include -L lib/ -lSDL2main -lSDL2 -std=c++17 -mwindows