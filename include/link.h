#ifndef LINK_H
#define LINK_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <point.h>
#include <stdint.h>

#define M_PI 3.14159265358979323846 //PI
#define M_2PI 2*M_PI

typedef struct link link;

struct link{
    point bottom;
    point top;
    uint32_t len;
    double angle;
};

link new_link(uint32_t len);
void print_seg(link *s);
SDL_bool link_follow(link *s, const point *p);
SDL_bool draw_link(SDL_Renderer *r, const link *seg);

#endif