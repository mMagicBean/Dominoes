#pragma once

#include <SDL.h>

#define MAX_PIPS 12

typedef struct {
  int top, bottom;

  SDL_Rect dstrect;
  
  SDL_Rect pips[MAX_PIPS];

  SDL_Texture* tile_img;
}Domino;


Domino* create_domino_set();
void create_domino_pips(Domino* d);
void render_domino(SDL_Renderer* r, SDL_Rect tile_rect[]);
void render_pips(SDL_Renderer* r, SDL_Rect pip_rects[]);
int* grab_rand_domino(Domino* d);
void handle_mouse(Domino* d, SDL_Event event);
