#ifndef ARM_H
#define ARM_H
#include <link.h>
#include <SDL2/SDL_render.h>
#include <stdint.h>

typedef struct arm arm;

struct arm{
    size_t len;
    link *links;
};

void update_arm(arm *a, const point *p);
void draw_arm(SDL_Renderer *r, const arm *a);

#endif