#pragma once

#include <stdbool.h>
#include <SDL.h>

#define MAX_PIPS 12

typedef struct {
  int top, bottom;
  SDL_Rect dstrect;
  SDL_Rect pips[MAX_PIPS];
  SDL_Texture* tile_img;
  bool can_grab;
}Domino;


Domino* create_domino_set(int set);
void create_domino_pips(Domino* d);
void render_domino(SDL_Renderer* r, SDL_Rect tile_rect[]);
void render_pips(SDL_Renderer* r, SDL_Rect pip_rects[]);
int* grab_rand_domino();
