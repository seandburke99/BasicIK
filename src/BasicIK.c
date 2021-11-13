#include <arm.h>
#include <string.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 600
#define FPS 60
#define DELAY 1000/FPS

#define SEGMENTNUMSTRING "--links"
#define SEGMENTLENSTRING "--linkslen"

void clr_ren(SDL_Renderer *r);

int main(int argc, char *argv[]){
    int num = 6;
    int len = 50;

    for(int i=1;i<argc;i++){
        if(!SDL_strcmp(argv[i], SEGMENTNUMSTRING)){
            num = SDL_atoi(argv[i+1]);
            i++;
        }else if(!SDL_strcmp(argv[i], SEGMENTLENSTRING)){
            len = SDL_atoi(argv[i+1]);
            i++;
        }
    }
    SDL_Init(0);
    SDL_Window* win = NULL;
    SDL_Renderer* ren = NULL;

    win = SDL_CreateWindow( "Inverse Kinematics", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if(win==NULL){
        fprintf(stderr, "Unable to create window\n");
    }
    ren = SDL_CreateRenderer( win, -1, SDL_RENDERER_ACCELERATED);
    if(ren==NULL){
        fprintf(stderr, "Unable to create renderer");
    }
    SDL_bool quit = SDL_FALSE;
    point target = new_point(0,0);
    arm a;
    a.len = num;
    a.links = malloc(num*sizeof(link));
    for(int i=0;i<num;i++){
        a.links[i] = new_link(len);
    }
    a.links[0].bottom = new_point(SCREEN_WIDTH/2, SCREEN_HEIGHT);
    while(!quit){
        SDL_Event e;
        SDL_bool uparm = SDL_FALSE;
        while( SDL_PollEvent( &e ) != 0 ){
            switch(e.type){
                case SDL_QUIT:
                    quit = SDL_TRUE;
                    break;
                case SDL_KEYDOWN:
                    switch(e.key.keysym.sym){
                        case SDLK_q:
                            quit = SDL_TRUE;
                            break;
                    }
                    break;
                case SDL_MOUSEMOTION:
                    SDL_GetMouseState(&target.x, &target.y);
                    uparm = SDL_TRUE;
                    break;
                default:
                    break;
            }
        }
        clr_ren(ren);
        if(uparm)
            update_arm(&a, &target);
        draw_arm(ren, &a);
        //Blit
        SDL_RenderPresent(ren);
        SDL_Delay(DELAY);
    }
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    return 0;
}

void clr_ren(SDL_Renderer *r){
    SDL_SetRenderDrawColor(r, 0, 0, 0, 0xFF);
    SDL_RenderClear(r);
}