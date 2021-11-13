#include <arm.h>

void update_arm(arm *a, const point *p){
    point lp = a->links[0].bottom;
    point tp = *p;
    for(int i=a->len-1;i>=0;i--){
        link_follow(&a->links[i], &tp);
        tp = a->links[i].bottom;
    }
    for(int i=0;i<a->len;i++){
        a->links[i].bottom = lp;
        a->links[i].top.x = a->links[i].bottom.x - a->links[i].len*SDL_cos(a->links[i].angle);
        a->links[i].top.y = a->links[i].bottom.y - a->links[i].len*SDL_sin(a->links[i].angle);
        lp = a->links[i].top;
    }
}

void draw_arm(SDL_Renderer *r, const arm *a){
    for(int i=0;i<a->len;i++){
        draw_link(r, &a->links[i]);
    }
}