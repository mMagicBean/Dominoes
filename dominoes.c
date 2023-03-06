#include "dominoes.h"
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h> 


Domino* create_domino_set(int set) {
  
  int total_size = 28; // size of 6x6 domino tile set
 
  Domino* d = malloc(total_size * sizeof(Domino));

  int index = 0;

  for (int i=6; i >= 0; i--) {
    for (int j=i; j >= 0; j--) {
      d[index].top    = i;
      d[index].bottom = j;

      d[index].flip = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL;
      index++;
    }
  }
  
  int offset = 0;
  
  for (int i = 0; i <= set; i++) {
    offset += 50;

    d[i].dstrect.x = 0;
    d[i].dstrect.y = 0;
    d[i].dstrect.w = 50;
    d[i].dstrect.h = 70;
  }
  
  for (int i=0; i < total_size; i++) {
    d[i].can_grab = true;
  }

  return d;
}

int rand_num() {
  int lower = 0, upper = 27;
  
  int rnum = (rand() % (upper - lower + 1)) + lower;

  return rnum;
}

void setup_player_hand(Domino* dom_set, Domino* player_hand, int size) {
  int rnum = 0;
  
  for (int i=0; i < size; i++) {
    rnum = rand_num();
    player_hand[i] = dom_set[rnum];
    printf("rnum = %d\n", rnum);
  } 
}

void get_domino_pips(SDL_Renderer* r, Domino* d) {
  for (int i=0; i <= 12; i++) {
    // 6x6 tile
    if (d[i].top == 6 && d[i].bottom == 6) {
      SDL_Surface* image = SDL_LoadBMP("Assets/6x6.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 6x5 tile
    if (d[i].top == 6 && d[i].bottom == 5) {
      SDL_Surface* image = SDL_LoadBMP("Assets/6x5.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }
    
    // 6x4 tile
    if (d[i].top == 6 && d[i].bottom == 4) {
      SDL_Surface* image = SDL_LoadBMP("Assets/6x4.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 6x3 tile
    if (d[i].top == 6 && d[i].bottom == 3) {
      SDL_Surface* image = SDL_LoadBMP("Assets/6x3.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 6x2 tile
    if (d[i].top == 6 && d[i].bottom == 2) {
      SDL_Surface* image = SDL_LoadBMP("Assets/6x2.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 6x1 tile
    if (d[i].top == 6 && d[i].bottom == 1) {
      SDL_Surface* image = SDL_LoadBMP("Assets/6x1.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 6x0 tile
    if (d[i].top == 6 && d[i].bottom == 0) {
      SDL_Surface* image = SDL_LoadBMP("Assets/6x0.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 5x5 tile
    if (d[i].top == 5 && d[i].bottom == 5) {
      SDL_Surface* image = SDL_LoadBMP("Assets/5x5.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 5x4 tile
    if (d[i].top == 5 && d[i].bottom == 4) {
      SDL_Surface* image = SDL_LoadBMP("Assets/5x4.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 5x3 tile
    if (d[i].top == 5 && d[i].bottom == 3) {
      SDL_Surface* image = SDL_LoadBMP("Assets/5x3.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 5x2 tile
    if (d[i].top == 5 && d[i].bottom == 2) {
      SDL_Surface* image = SDL_LoadBMP("Assets/5x2.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 5x1 tile
    if (d[i].top == 5 && d[i].bottom == 1) {
      SDL_Surface* image = SDL_LoadBMP("Assets/5x1.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 5x0 tile
    if (d[i].top == 5 && d[i].bottom == 0) {
      SDL_Surface* image = SDL_LoadBMP("Assets/5x0.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 4x4 tile
    if (d[i].top == 4 && d[i].bottom == 4) {
      SDL_Surface* image = SDL_LoadBMP("Assets/4x4.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 4 x 3 tile
    if (d[i].top == 4 && d[i].bottom == 3) {
      SDL_Surface* image = SDL_LoadBMP("Assets/4x3.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 4x2 tile
    if (d[i].top == 4 && d[i].bottom == 2) {
      SDL_Surface* image = SDL_LoadBMP("Assets/4x2.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 4x1 tile
    if (d[i].top == 4 && d[i].bottom == 1) {
      SDL_Surface* image = SDL_LoadBMP("Assets/4x1.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 4x0 tile
    if (d[i].top == 4 && d[i].bottom == 0) {
      SDL_Surface* image = SDL_LoadBMP("Assets/4x0.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 3x3 tile
    if (d[i].top == 3 && d[i].bottom == 3) {
      SDL_Surface* image = SDL_LoadBMP("Assets/3x3.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 3x2 tile
    if (d[i].top == 3 && d[i].bottom == 2) {
      SDL_Surface* image = SDL_LoadBMP("Assets/3x2.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 3x1 tile
    if (d[i].top == 3 && d[i].bottom == 1) {
      SDL_Surface* image = SDL_LoadBMP("Assets/3x1.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 3x0 tile
    if (d[i].top == 3 && d[i].bottom == 0) {
      SDL_Surface* image = SDL_LoadBMP("Assets/3x0.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 2x2 tile
    if (d[i].top == 2 && d[i].bottom == 2) {
      SDL_Surface* image = SDL_LoadBMP("Assets/2x2.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);      
      continue;
    }

    // 2x1 tile
    if (d[i].top == 2 && d[i].bottom == 1) {
      SDL_Surface* image = SDL_LoadBMP("Assets/2x1.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 2x0 tile
    if (d[i].top == 2 && d[i].bottom == 0) {
      SDL_Surface* image = SDL_LoadBMP("Assets/2x0.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 1x1 tile
    if (d[i].top == 1 && d[i].bottom == 1) {
      SDL_Surface* image = SDL_LoadBMP("Assets/1x1.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 1x0 tile
    if (d[i].top == 1 && d[i].bottom == 0) {
      SDL_Surface* image = SDL_LoadBMP("Assets/1x0.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }

    // 0x0 tile
    if (d[i].top == 0 && d[i].bottom == 0) {
      SDL_Surface* image = SDL_LoadBMP("Assets/0x0.bmp");
      d[i].tile_tex = SDL_CreateTextureFromSurface(r, image);
      continue;
    }
  }
}

void render_domino(SDL_Renderer* r, SDL_Texture* tex, SDL_Rect tile_rect[], SDL_RendererFlip flip) {
  SDL_RenderCopyEx(r, tex, NULL, tile_rect, 0.0f, NULL, flip);
}


void free_domino_set(Domino* d) {


}
