#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "dominoes.h"
#include <stdlib.h>
#include <time.h>

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
  Domino player_hand[6];
  
  setup_player_hand(domino_set, player_hand, 6);
  
  int center_x = player_hand[0].dstrect.w / 2;
  int center_y = player_hand[0].dstrect.h / 2;

  bool is_holding_domino = false;
  
  int curr_dom_index = 0;

  bool flip_switch[2] = {true, false};

  get_domino_pips(renderer, player_hand);
  
  srand(time(NULL));

  bool is_running = true;
  while (is_running) {
    uint32_t time = SDL_GetTicks();
    uint32_t frame_time;
    float fps;
    
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
	for (int i=0; i < 6; i++) {
	  if (mx >= player_hand[i].dstrect.x && mx <= player_hand[i].dstrect.x + player_hand[i].dstrect.w &&
	      my >= player_hand[i].dstrect.y && my <= player_hand[i].dstrect.y + player_hand[i].dstrect.h &&
	      player_hand[i].can_grab == true) {

	    curr_dom_index = i;
	    
	    player_hand[i].dstrect.x = mx - center_x;
	    player_hand[i].dstrect.y = my - center_y;
	    
	    for (int j = 0; j < 6; j++) {
	      if (curr_dom_index == j) {
		printf("current_index = %d\n", curr_dom_index);
		continue;
	      }
	      
	      player_hand[j].can_grab = false;
	    }
	  } else {
	    player_hand[i].can_grab = true;
	  }
	}
      }

      if (SDL_BUTTON_RIGHT == event.button.button) {
	player_hand[curr_dom_index].flip = SDL_FLIP_HORIZONTAL;
      }
    }
    
    SDL_SetRenderDrawColor(renderer, 92, 64, 51, 255); // brown
    SDL_RenderClear(renderer);
    
    for (int i=0; i < 6; i++) {
      render_domino(renderer, player_hand[i].tile_tex, &player_hand[i].dstrect, player_hand[i].flip);
    }

    SDL_RenderPresent(renderer);

    if ((SDL_GetTicks() - time) < 10) {
      SDL_Delay(10);
    }

    frame_time = SDL_GetTicks()-time;
    fps = (frame_time > 0) ? 1000.0f / frame_time : 0.0f;

    printf("fps: %f\n", fps);
  }
  
  SDL_DestroyWindow(window);

  SDL_Quit();

  return 0;
}

