#include "../Headers/Function.hpp"

#include "../Headers/Math.hpp"
#include "../Headers/Screen.hpp"

void Function::Draw(const double &x) {

    const short &abscisse(x),&ordonne(Screen::height/2-expression(x-Screen::width/2));

    if (ordonne > 0 && ordonne < Screen::height) {
        
        if (last.x != abscisse || last.y != ordonne) {

            SDL_SetRenderDrawColor(Screen::renderer,color.r,color.g,color.b,255);
            SDL_RenderDrawPoint(Screen::renderer,abscisse,ordonne);
            SDL_RenderPresent(Screen::renderer);

            last.x = abscisse;
            last.y = ordonne;

        }

    }


}