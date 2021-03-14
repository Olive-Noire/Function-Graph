#ifndef DEF_CLASS_FUNCTION_HPP
#define DEF_CLASS_FUNCTION_HPP

#include <SDL.h>

class Function final {

    public:
    constexpr Function(const SDL_Point &l,const SDL_Color &c,double (*e)(const double &x)) : expression(e), last(l), color(c) {}

    void Draw(const double &x);
    double (*expression)(const double &x);

    protected:
    SDL_Point last;
    SDL_Color color;

};

#endif //DEF_CLASS_FUNCTION_HPP