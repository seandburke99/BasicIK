#include <link.h>

link new_link(uint32_t len){
    link s;
    s.bottom = new_point(0,0);
    s.top = new_point(0,0);
    s.len = len;
    s.angle = 0;
    return s;
}

void print_link(link *s){
    printf("Top: (%d,%d), Bottom: (%d,%d)\n", s->top.x, s->top.y, s->bottom.x, s->bottom.y);
}

SDL_bool link_follow(link *s, const point *p){
    point temp2 = new_point(
        s->top.x - s->bottom.x,
        s->top.y - s->bottom.y
    );
    point temp1 = new_point(
        p->x - s->bottom.x,
        p->y - s->bottom.y
    );
    s->angle += dir(&temp2) - dir(&temp1);
    if(s->angle > M_2PI){
        s->angle -= M_2PI;
    }else if(s->angle < -M_2PI){
        s->angle += M_PI*2;
    }

    s->top = *p;
    s->bottom.x = s->top.x + s->len*SDL_cos(s->angle);
    s->bottom.y = s->top.y + s->len*SDL_sin(s->angle);

    return SDL_TRUE;
}

SDL_bool draw_link(SDL_Renderer *r, const link *seg){
    int8_t ret;
    ret = SDL_SetRenderDrawColor(r, 0xFF, 0xFF, 0xFF, 0xFF);
    if(ret) return SDL_FALSE;
    ret = SDL_RenderDrawLine(
        r, 
        seg->bottom.x, 
        seg->bottom.y, 
        seg->top.x, 
        seg->top.y
    );
    if(ret) return SDL_FALSE;
    return SDL_TRUE;
}