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
void draw_top_domino_pips(Domino* d);
void draw_bottom_domino_pips(Domino* d);
void render_domino(SDL_Renderer* r, const SDL_Rect* tile_rect, SDL_Rect pip_rects[]); 


