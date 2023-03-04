#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
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

  Domino* domino_set = create_domino_set(27);
  Domino player_hand[6] = {domino_set[5], domino_set[7], domino_set[4], domino_set[9], domino_set[11], domino_set[18]};
    
  bool is_running = true;
  
  int center_x = domino_set[0].dstrect.w / 2;
  int center_y = domino_set[0].dstrect.h / 2;

  bool is_holding_domino = false;

  int curr_dom_index = 0;
  
  while (is_running) {
    SDL_Event event;
    
    while(SDL_PollEvent(&event)) {
      int mx = 0, my = 0;
      
      if (event.type == SDL_QUIT) {
	is_running = false;	
      }

      if (SDL_MOUSEMOTION == event.type) {
	SDL_GetMouseState(&mx, &my);
      }
      
      if (SDL_BUTTON_LEFT == event.button.button) {
	for (int i=0; i <= 27; i++) {
	  if (mx >= domino_set[i].dstrect.x && mx <= domino_set[i].dstrect.x + domino_set[i].dstrect.w &&
	      my >= domino_set[i].dstrect.y && my <= domino_set[i].dstrect.y + domino_set[i].dstrect.h &&
	      domino_set[i].can_grab == true) {

	    int curr_index = i;

	    curr_dom_index = curr_index;
	    
	    domino_set[i].dstrect.x = mx - center_x;
	    domino_set[i].dstrect.y = my - center_y;
	    
	    for (int j = 0; j <= 27; j++) {
	      if (curr_index == j) {
		printf("current_index = %d\n", curr_index);
		continue;
	      }
	      
	      domino_set[j].can_grab = false;
	    }
	  } else {
	    domino_set[i].can_grab = true;
	  }
	}
      }

      if (SDL_BUTTON_RIGHT == event.button.button) {
	
	if (domino_set[curr_dom_index].can_grab) {
	  printf("top pips    = %d\n", domino_set[curr_dom_index].top);
	  printf("bottom pips = %d\n", domino_set[curr_dom_index].bottom);
	  
	  int tmp = domino_set[curr_dom_index].top;
	  domino_set[curr_dom_index].top = domino_set[curr_dom_index].bottom;
	  domino_set[curr_dom_index].bottom = tmp; 
	}
      }
    }
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    create_domino_pips(player_hand);
    
    // white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (int i=0; i <= 6; i++) {
      //render_domino(renderer, &domino_set[i].dstrect);
      //render_pips(renderer, domino_set[i].pips);
      render_domino(renderer, &player_hand[i].dstrect);
      render_pips(renderer, player_hand[i].pips);
    }

    SDL_RenderPresent(renderer);    
  }
  
  //Destroy window
  SDL_DestroyWindow(window);

  //Quit SDL subsystems
  SDL_Quit();

  return 0;
}

