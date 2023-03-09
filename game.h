#pragma once

#include <SDL.h>
#include <stdlib.h>
#include "dominoes.h"

typedef struct {
  SDL_Rect rect;
  int move_count;
}Board;


typedef struct {
  SDL_Rect box[2];
}Outline;


Board create_board();
Outline create_and_draw_outline(SDL_Renderer* r, Board* b);
void detect_move_made(Outline* o, Board* b, Domino* d, int index);
