#include <point.h>
#include <SDL2/SDL_types.h>

point new_point(int x, int y){
    point p;
    if(x)
        p.x = x;
    else
        p.x = 0;
    if(y)
        p.y = y;
    else
       p.y = 0;
    return p;
}

double dir(const point *p){
    return SDL_atan2(p->x, p->y);
}

double mag(const point *p){
    return SDL_sqrt((double)p->x*(double)p->y);
}

void rotate_around(const point *o, point *p, double theta){
    point temp = new_point(0,0);
    temp.x = p->x - o->x;
    temp.y = p->y - o->y;
    p->x = (int)(temp.x*SDL_cos(theta)) - (int)(temp.y*SDL_sin(theta));
    p->y = (int)(temp.x*SDL_sin(theta)) + (int)(temp.y*SDL_cos(theta));
    p->x += o->x;
    p->y += o->y;
}