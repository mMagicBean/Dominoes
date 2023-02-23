#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "dominoes.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;


int main(int argc, char* args[]) {
  SDL_Window* window = NULL;

  window = SDL_CreateWindow
    ("",
     SDL_WINDOWPOS_CENTERED,
     SDL_WINDOWPOS_CENTERED,
     SCREEN_WIDTH,
     SCREEN_HEIGHT,
     0);
  
  SDL_Renderer* renderer = NULL;
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (renderer) {
    printf("renderer created!\n");
  } else {
    printf(SDL_GetError());
  }
			      
  Domino* dom_set = create_domino_set();

  dom_set[0].dstrect.x = 100;
  dom_set[0].dstrect.y = 100;
  dom_set[0].dstrect.w = 50;
  dom_set[0].dstrect.h = 70;

  draw_top_domino_pips(dom_set);
  draw_bottom_domino_pips(dom_set);
  
  bool is_running = true;

  while (is_running) {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
	is_running = false;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    render_domino(renderer, &dom_set[0].dstrect, &dom_set[0].pips);

    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    //render_domino(renderer, &dom_set[1].dstrect, &dom_set[1].pips);
    
    SDL_RenderPresent(renderer);    
  }
  
  //Destroy window
  SDL_DestroyWindow(window);

  //Quit SDL subsystems
  SDL_Quit();

  return 0;
}
