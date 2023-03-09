#pragma once

#include <stdbool.h>
#include <SDL.h>

#define MAX_PIPS 12

typedef struct {
  int top, bottom;
  SDL_Rect dstrect;
  SDL_Rect pips[MAX_PIPS];
  SDL_Texture* tile_tex;
  bool can_grab;
  SDL_RendererFlip flip;
}Domino;


Domino* create_domino_set(int set);
void shuffle_domino_set(Domino* d, int n);
int rand_num(int lower, int upper);
void setup_player_hand(Domino* player_hand);
void get_domino_pips(SDL_Renderer* r, Domino* d);
void render_domino(SDL_Renderer* r, SDL_Texture* tex, SDL_Rect tile_rect[], SDL_RendererFlip flip);
void free_domino_set(Domino* d);
