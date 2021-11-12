#include <arm.h>

void update_arm(arm *a, const point *p){
    link_follow(&a->links[a->len-1], p);
    for(int i=a->len-2;i>=0;i--){
        link_follow(&a->links[i], &a->links[i+1].bottom);
    }
}

void draw_arm(SDL_Renderer *r, const arm *a){
    for(int i=0;i<a->len;i++){
        draw_link(r, &a->links[i]);
    }
}