#include "dominoes.h"
#include <stdio.h>
#include <stddef.h>


Domino* create_domino_set() {
  int size = 28; // size of 6x6 domino tile set

  Domino* d_set = malloc(size * sizeof(Domino));
  
  int index = 0;

  for (int i=6; i >= 0; i--) {
    for (int j=i; j >= 0; j--) {
      d_set[index].top = i;
      d_set[index].bottom = j;

      index++;
    }
  }

  for (int i=0; i < size; i++) {
    for (int j=0; j < MAX_PIPS; j++) {
      d_set[i].pips[j].x = 0;
      d_set[i].pips[j].y = 0;
      d_set[i].pips[j].w = 0;
      d_set[i].pips[j].h = 0;
    }
  }
  
  printf("index = %d\n", index);
  return d_set;
}

void draw_top_domino_pips(Domino* d) {
  for (int i=0; i <= 12; i++) {
    if (d[i].top == 6) {
      // top left pip
      d[i].pips[0].x = d[i].dstrect.x + 4;
      d[i].pips[0].y = d[i].dstrect.y + 4;
      d[i].pips[0].w = 6;
      d[i].pips[0].h = 6;

      // top right pip
      d[i].pips[1].x = d[i].dstrect.x + 40;
      d[i].pips[1].y = d[i].dstrect.y + 4;
      d[i].pips[1].w = 6;
      d[i].pips[1].h = 6;
      
      // mid left pip
      d[i].pips[2].x = d[i].dstrect.x + 4;
      d[i].pips[2].y = d[i].dstrect.y + 15;
      d[i].pips[2].w = 6;
      d[i].pips[2].h = 6;
      
      // mid right pip
      d[i].pips[3].x = d[i].dstrect.x + 40;
      d[i].pips[3].y = d[i].dstrect.y + 15;
      d[i].pips[3].w = 6;
      d[i].pips[3].h = 6;

      // bottom-left pip
      d[i].pips[4].x = d[i].dstrect.x + 4;
      d[i].pips[4].y = d[i].dstrect.y + 25;
      d[i].pips[4].w = 6;
      d[i].pips[4].h = 6;

      // bottom-right pip
      d[i].pips[5].x = d[i].dstrect.x + 40;
      d[i].pips[5].y = d[i].dstrect.y + 25;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;

      return;
    }

    if (d[i].top == 5) {
      // top-left pip
      d[i].pips[0].x = d[i].dstrect.x + 4;
      d[i].pips[0].y = d[i].dstrect.y + 4;
      d[i].pips[0].w = 6;
      d[i].pips[0].h = 6;

      // top-right pip
      d[i].pips[1].x = d[i].dstrect.x + 40;
      d[i].pips[1].y = d[i].dstrect.y + 4;
      d[i].pips[1].w = 6;
      d[i].pips[1].h = 6;

      // mid-center pip
      d[i].pips[2].x = d[i].dstrect.x + 20;
      d[i].pips[2].y = d[i].dstrect.y + 15;
      d[i].pips[2].w = 6;
      d[i].pips[2].h = 6;

      // bottom-left pip
      d[i].pips[3].x = d[i].dstrect.x + 4;
      d[i].pips[3].y = d[i].dstrect.y + 25;
      d[i].pips[3].w = 6;
      d[i].pips[3].h = 6;

      // bottom-right pip
      d[i].pips[4].x = d[i].dstrect.x + 40;
      d[i].pips[4].y = d[i].dstrect.y + 25;
      d[i].pips[4].w = 6;
      d[i].pips[4].h = 6;
    }

    if (d[i].top == 4) {
      // top-left pip
      d[i].pips[0].x = d[i].dstrect.x + 4;
      d[i].pips[0].y = d[i].dstrect.x + 4;
      d[i].pips[0].w = 6;
      d[i].pips[0].h = 6;

      // top-right pip
      d[i].pips[1].x = d[i].dstrect.x + 40;
      d[i].pips[1].y = d[i].dstrect.y + 4;
      d[i].pips[1].w = 6;
      d[i].pips[1].h = 6;

      // bottom-left pip
      d[i].pips[2].x = d[i].dstrect.x + 4;
      d[i].pips[2].y = d[i].dstrect.y + 25;
      d[i].pips[2].w = 6;
      d[i].pips[2].h = 6;

      // bottom - right pip
      d[i].pips[3].x = d[i].dstrect.x + 40;
      d[i].pips[3].y = d[i].dstrect.y + 25;
      d[i].pips[3].w = 6;
      d[i].pips[3].h = 6;
    }

    if (d[i].top == 3) {
      // top-left pip
      d[i].pips[0].x = d[i].dstrect.x + 4;
      d[i].pips[0].y = d[i].dstrect.y + 4;
      d[i].pips[0].w = 6;
      d[i].pips[0].h = 6;

      // mid-center pip
      d[i].pips[1].x = d[i].dstrect.x + 20;
      d[i].pips[1].y = d[i].dstrect.y + 15;
      d[i].pips[1].w = 6;
      d[i].pips[1].h = 6;

      // bottom-right pip
      d[i].pips[2].x = d[i].dstrect.x + 40;
      d[i].pips[2].y = d[i].dstrect.y + 25;
      d[i].pips[2].w = 6;
      d[i].pips[2].h = 6;
    }

    if (d[i].top == 2) {
      // top-left pip
      d[i].pips[0].x = d[i].dstrect.x + 4;
      d[i].pips[0].y = d[i].dstrect.y + 4;
      d[i].pips[0].w = 6;
      d[i].pips[0].h = 6;

      // bottom-right pip
      d[i].pips[1].x = d[i].dstrect.x + 40;
      d[i].pips[1].y = d[i].dstrect.y + 25;
      d[i].pips[1].w = 6;
      d[i].pips[1].h = 6;
    }

    if (d[i].top == 1) {
      d[i].pips[0].x = d[i].dstrect.x + 20;
      d[i].pips[0].y = d[i].dstrect.y + 15;
      d[i].pips[0].w = 6;
      d[i].pips[0].h = 6;
    }
  }
}

void draw_bottom_domino_pips(Domino* d) {
  for (int i=0; i <= 12; i++) {
    if (d[i].bottom == 6) {
      // top left pip
      d[i].pips[0].x = d[i].dstrect.x + 4;
      d[i].pips[0].y = d[i].dstrect.y + 40;
      d[i].pips[0].w = 6;
      d[i].pips[0].h = 6;

      // top right pip
      d[i].pips[1].x = d[i].dstrect.x + 40;
      d[i].pips[1].y = d[i].dstrect.y + 40;
      d[i].pips[1].w = 6;
      d[i].pips[1].h = 6;
      
      // mid left pip
      d[i].pips[2].x = d[i].dstrect.x + 4;
      d[i].pips[2].y = d[i].dstrect.y + 50;
      d[i].pips[2].w = 6;
      d[i].pips[2].h = 6;
      
      // mid right pip
      d[i].pips[3].x = d[i].dstrect.x + 40;
      d[i].pips[3].y = d[i].dstrect.y + 50;
      d[i].pips[3].w = 6;
      d[i].pips[3].h = 6;

      // bottom-left pip
      d[i].pips[4].x = d[i].dstrect.x + 4;
      d[i].pips[4].y = d[i].dstrect.y + 60;
      d[i].pips[4].w = 6;
      d[i].pips[4].h = 6;

      // bottom-right pip
      d[i].pips[5].x = d[i].dstrect.x + 40;
      d[i].pips[5].y = d[i].dstrect.y + 60;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;
    }
  }
}

void render_domino(SDL_Renderer* r, const SDL_Rect* tile_rect, SDL_Rect pip_rects[]) {
  SDL_RenderFillRect(r, tile_rect);
  
  SDL_SetRenderDrawColor(r, 255, 0, 0, 255); // pip color
  for (int i=0; i <= 12; i++) {
    SDL_RenderFillRect(r, &pip_rects[i]);
  }
}
