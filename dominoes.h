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
Domino* setup_player_hand(Domino* d, int set);
void render_domino(SDL_Renderer* r, SDL_Rect tile_rect[]);
void render_pips(SDL_Renderer* r, SDL_Rect pip_rects[]);
void handle_mouse(Domino* d, SDL_Event event);
