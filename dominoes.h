#pragma once
#include <SDL.h>


typedef struct {
  int top, bottom;
  SDL_Rect* rect;
}Domino;


Domino* create_domino_set();



