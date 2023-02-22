#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "dominoes.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;


int main(int argc, char* args[]) {
  SDL_Window* window = NULL;
	
  SDL_Surface* screenSurface = NULL;

  Domino* dom_set = create_domino_set();

  // for (int i=0; i < sizeof(dom_set); i++) {
  //  printf("top : %d\t | bottom : %d\n", dom_set[i].top, dom_set[i].bottom);
  //}
  
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  } else {
    window = SDL_CreateWindow( "Dominoes", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == NULL) {
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
    } else {
      screenSurface = SDL_GetWindowSurface( window );

      //Fill the surface white
      SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x00, 0x00, 0x00 ) );
			
      //Update the surface
      SDL_UpdateWindowSurface( window );
            
      //Hack to get window to stay up
      SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true;} }
    }
  }

  //Destroy window
  SDL_DestroyWindow( window );

  //Quit SDL subsystems
  SDL_Quit();

  return 0;
}
