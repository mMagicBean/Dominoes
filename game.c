#include "game.h"

const int BOARD_WIDTH = 1000;
const int BOARD_HEIGHT = 500;


Board create_board() {
  Board board;

  board.rect.x = 0;
  board.rect.y = 0;
  board.rect.w = BOARD_WIDTH;
  board.rect.h = BOARD_HEIGHT;
  
  board.move_count = 0;
  
  return board;
}

Outline create_and_draw_outline(SDL_Renderer* r, Board* b) {
  Outline o;
  
  if (b->move_count == 0) {
    o.box[0].x = BOARD_WIDTH / 2;
    o.box[0].y = 800 / 2;
    o.box[0].w = 70;
    o.box[0].h = 50;

    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderDrawRect(r, &o.box[0]);
  }

  return o;
}

void detect_move_made(Outline* o, Board* b, Domino* d, int index) {
  for (int i=0; i < 2; i++) {
    if (d[index].dstrect.x + d[index].dstrect.w >= o->box[i].x &&
	d[index].dstrect.x + d[index].dstrect.w <= o->box[i].x + o->box[i].w &&
	d[index].dstrect.y + d[index].dstrect.h >= o->box[i].y &&
	d[index].dstrect.y + d[index].dstrect.h <= o->box[i].y + o->box[i].w) {

      if (d[index].top == d[index].bottom) {
	d[index].dstrect.x = o->box[i].x;
	d[index].dstrect.y = o->box[i].y;
	d[index].dstrect.w = o->box[i].w;
	d[index].dstrect.h = o->box[i].h;
	
	d[index].can_grab = false;
      }
    }
  }
}
