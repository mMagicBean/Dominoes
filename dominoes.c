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
      d[index].top = i;
      d[index].bottom = j;
      index++;
    }
  }

  for (int i=0; i < total_size; i++) {
    for (int j=0; j < MAX_PIPS; j++) {
      d[i].pips[j].x = 0;
      d[i].pips[j].y = 0;
      d[i].pips[j].w = 0;
      d[i].pips[j].h = 0;
    }
  }
  
  printf("index = %d\n", index);

  int offset = 0;
  
  // init rects
  for (int i = 0; i <= set; i++) {
    offset += 50;
    
    d[i].dstrect.x = offset;
    d[i].dstrect.y = 600;
    d[i].dstrect.w = 50;
    d[i].dstrect.h = 70;
  }
  
  
  for (int i=0; i <= set; i++) {
    d[i].can_grab = true;
  }
  
  return d;
}

void create_domino_pips(Domino* d) {
  // NOTE: apparently the iterator number needs to match the size of
  //       the initialized domino_set
  for (int i=0; i <= 6; i++) {
    // 6x6 tile
    if (d[i].top == 6 && d[i].bottom == 6) {
      //////////////////////////////
      //TOP PIPS
      //////////////////////////////
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
      
      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////
      //top left pip
      d[i].pips[6].x = d[i].dstrect.x + 4;
      d[i].pips[6].y = d[i].dstrect.y + 40;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // top right pip
      d[i].pips[7].x = d[i].dstrect.x + 40;
      d[i].pips[7].y = d[i].dstrect.y + 40;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;
      
      // mid left pip
      d[i].pips[8].x = d[i].dstrect.x + 4;
      d[i].pips[8].y = d[i].dstrect.y + 50;
      d[i].pips[8].w = 6;
      d[i].pips[8].h = 6;
      
      // mid right pip
      d[i].pips[9].x = d[i].dstrect.x + 40;
      d[i].pips[9].y = d[i].dstrect.y + 50;
      d[i].pips[9].w = 6;
      d[i].pips[9].h = 6;

      // bottom-left pip
      d[i].pips[10].x = d[i].dstrect.x + 4;
      d[i].pips[10].y = d[i].dstrect.y + 60;
      d[i].pips[10].w = 6;
      d[i].pips[10].h = 6;

      // bottom-right pip
      d[i].pips[11].x = d[i].dstrect.x + 40;
      d[i].pips[11].y = d[i].dstrect.y + 60;
      d[i].pips[11].w = 6;
      d[i].pips[11].h = 6;
    }

    // 6x5 tile
    if (d[i].top == 6 && d[i].bottom == 5) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
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
      
      ////////////////////////////////////
      // BOTTOM PIPS
      ////////////////////////////////////
      // top-left pip
      d[i].pips[6].x = d[i].dstrect.x + 4;
      d[i].pips[6].y = d[i].dstrect.y + 38;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // top-right pip
      d[i].pips[7].x = d[i].dstrect.x + 40;
      d[i].pips[7].y = d[i].dstrect.y + 38;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;

      // mid-center pip
      d[i].pips[8].x = d[i].dstrect.x + 21;
      d[i].pips[8].y = d[i].dstrect.y + 50;
      d[i].pips[8].w = 6;
      d[i].pips[8].h = 6;

      // bottom-left pip
      d[i].pips[9].x = d[i].dstrect.x + 4;
      d[i].pips[9].y = d[i].dstrect.y + 60;
      d[i].pips[9].w = 6;
      d[i].pips[9].h = 6;

      // bottom-right pip
      d[i].pips[10].x = d[i].dstrect.x + 40;
      d[i].pips[10].y = d[i].dstrect.y + 60;
      d[i].pips[10].w = 6;
      d[i].pips[10].h = 6;
    }

    // 6x4 tile
    if (d[i].top == 6 && d[i].bottom == 4) {
      
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
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
      
      ////////////////////////////////////
      // BOTTOM PIPS
      ////////////////////////////////////
      // top-left pip
      d[i].pips[6].x = d[i].dstrect.x + 4;
      d[i].pips[6].y = d[i].dstrect.y + 38;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // top-right pip
      d[i].pips[7].x = d[i].dstrect.x + 40;
      d[i].pips[7].y = d[i].dstrect.y + 38;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;

      // bottom-left pip
      d[i].pips[8].x = d[i].dstrect.x + 4;
      d[i].pips[8].y = d[i].dstrect.y + 60;
      d[i].pips[8].w = 6;
      d[i].pips[8].h = 6;

      // bottom - right pip
      d[i].pips[9].x = d[i].dstrect.x + 40;
      d[i].pips[9].y = d[i].dstrect.y + 60;
      d[i].pips[9].w = 6;
      d[i].pips[9].h = 6;
    }

    // 6x3 tile
    if (d[i].top == 6 && d[i].bottom == 3) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
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
      
      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////
      
      // top-left pip
      d[i].pips[6].x = d[i].dstrect.x + 4;
      d[i].pips[6].y = d[i].dstrect.y + 40;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // mid-center pip
      d[i].pips[7].x = d[i].dstrect.x + 22;
      d[i].pips[7].y = d[i].dstrect.y + 50;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;

      // bottom-right pip
      d[i].pips[8].x = d[i].dstrect.x + 40;
      d[i].pips[8].y = d[i].dstrect.y + 60;
      d[i].pips[8].w = 6;
      d[i].pips[8].h = 6;
    }

    // 6x2 tile
    if (d[i].top == 6 && d[i].bottom == 2) {
            ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
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

      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////
       
      // top-left pip
      d[i].pips[6].x = d[i].dstrect.x + 4;
      d[i].pips[6].y = d[i].dstrect.y + 40;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // bottom-right pip
      d[i].pips[7].x = d[i].dstrect.x + 40;
      d[i].pips[7].y = d[i].dstrect.y + 60;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;
    }

    // 6x1 tile
    if (d[i].top == 6 && d[i].bottom == 1) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
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
      
      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////      
      d[i].pips[6].x = d[i].dstrect.x + 22;
      d[i].pips[6].y = d[i].dstrect.y + 50;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;
    }

    // 6x0 tile
    if (d[i].top == 6 && d[i].bottom == 0) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
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
    }

    // 5x5 tile
    if (d[i].top == 5 && d[i].bottom == 5) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
      
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

      ////////////////////////////////////
      // BOTTOM PIPS
      ////////////////////////////////////
      
      d[i].pips[5].x = d[i].dstrect.x + 4;
      d[i].pips[5].y = d[i].dstrect.y + 38;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;

      // top-right pip
      d[i].pips[6].x = d[i].dstrect.x + 40;
      d[i].pips[6].y = d[i].dstrect.y + 38;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // mid-center pip
      d[i].pips[7].x = d[i].dstrect.x + 21;
      d[i].pips[7].y = d[i].dstrect.y + 50;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;

      // bottom-left pip
      d[i].pips[8].x = d[i].dstrect.x + 4;
      d[i].pips[8].y = d[i].dstrect.y + 60;
      d[i].pips[8].w = 6;
      d[i].pips[8].h = 6;

      // bottom-right pip
      d[i].pips[9].x = d[i].dstrect.x + 40;
      d[i].pips[9].y = d[i].dstrect.y + 60;
      d[i].pips[9].w = 6;
      d[i].pips[9].h = 6;
    }

    // 5x4 tile
    if (d[i].top == 5 && d[i].bottom == 4) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
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

      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////
      // top-left pip
      d[i].pips[5].x = d[i].dstrect.x + 4;
      d[i].pips[5].y = d[i].dstrect.y + 38;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;

      // top-right pip
      d[i].pips[6].x = d[i].dstrect.x + 40;
      d[i].pips[6].y = d[i].dstrect.y + 38;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // bottom-left pip
      d[i].pips[7].x = d[i].dstrect.x + 4;
      d[i].pips[7].y = d[i].dstrect.y + 60;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;

      // bottom - right pip
      d[i].pips[8].x = d[i].dstrect.x + 40;
      d[i].pips[8].y = d[i].dstrect.y + 60;
      d[i].pips[8].w = 6;
      d[i].pips[8].h = 6;
    }

    // 5x3 tile
    if (d[i].top == 5 && d[i].bottom == 3) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
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

      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////
      // top-left pip
      d[i].pips[5].x = d[i].dstrect.x + 4;
      d[i].pips[5].y = d[i].dstrect.y + 40;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;

      // mid-center pip
      d[i].pips[6].x = d[i].dstrect.x + 22;
      d[i].pips[6].y = d[i].dstrect.y + 50;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // bottom-right pip
      d[i].pips[7].x = d[i].dstrect.x + 40;
      d[i].pips[7].y = d[i].dstrect.y + 60;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;
    }

    // 5x2 tile
    if (d[i].top == 5 && d[i].bottom == 2) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
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

      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////
      
      // top-left pip
      d[i].pips[5].x = d[i].dstrect.x + 4;
      d[i].pips[5].y = d[i].dstrect.y + 40;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;

      // bottom-right pip
      d[i].pips[6].x = d[i].dstrect.x + 40;
      d[i].pips[6].y = d[i].dstrect.y + 60;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;
    }

    // 5x1 tile
    if (d[i].top == 5 && d[i].bottom == 1) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
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

      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////      
      d[i].pips[5].x = d[i].dstrect.x + 22;
      d[i].pips[5].y = d[i].dstrect.y + 50;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;
    }

    // 5x0 tile
    if (d[i].top == 5 && d[i].bottom == 0) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
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

    // 4x4 tile
    if (d[i].top == 4 && d[i].bottom == 4) {
      /////////////////////////////////////
      // TOP PIPS
      /////////////////////////////////////
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
      
      ////////////////////////////////////
      // BOTTOM PIPS
      ////////////////////////////////////
      d[i].pips[4].x = d[i].dstrect.x + 4;
      d[i].pips[4].y = d[i].dstrect.y + 38;
      d[i].pips[4].w = 6;
      d[i].pips[4].h = 6;

      // top-right pip
      d[i].pips[5].x = d[i].dstrect.x + 40;
      d[i].pips[5].y = d[i].dstrect.y + 38;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;

      // bottom-left pip
      d[i].pips[6].x = d[i].dstrect.x + 4;
      d[i].pips[6].y = d[i].dstrect.y + 60;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // bottom - right pip
      d[i].pips[7].x = d[i].dstrect.x + 40;
      d[i].pips[7].y = d[i].dstrect.y + 60;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;
    }

    // 4 x 3 tile
    if (d[i].top == 4 && d[i].bottom == 3) {
      /////////////////////////////////////
      // TOP PIPS
      /////////////////////////////////////
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

      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////
      // top-left pip
      d[i].pips[4].x = d[i].dstrect.x + 4;
      d[i].pips[4].y = d[i].dstrect.y + 40;
      d[i].pips[4].w = 6;
      d[i].pips[4].h = 6;

      // mid-center pip
      d[i].pips[5].x = d[i].dstrect.x + 22;
      d[i].pips[5].y = d[i].dstrect.y + 50;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;

      // bottom-right pip
      d[i].pips[6].x = d[i].dstrect.x + 40;
      d[i].pips[6].y = d[i].dstrect.y + 60;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;
    }

    // 4x2 tile
    if (d[i].top == 4 && d[i].bottom == 2) {
      /////////////////////////////////////
      // TOP PIPS
      /////////////////////////////////////
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

      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////
       
      // top-left pip
      d[i].pips[4].x = d[i].dstrect.x + 4;
      d[i].pips[4].y = d[i].dstrect.y + 40;
      d[i].pips[4].w = 6;
      d[i].pips[4].h = 6;

      // bottom-right pip
      d[i].pips[5].x = d[i].dstrect.x + 40;
      d[i].pips[5].y = d[i].dstrect.y + 60;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;
    }

    // 4x1 tile
    if (d[i].top == 4 && d[i].bottom == 1) {
      /////////////////////////////////////
      // TOP PIPS
      /////////////////////////////////////
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
      ///////////////////////////////////////////
      // BOTTOM PIPS
      ///////////////////////////////////////////
      // mid-center pip
      d[i].pips[6].x = d[i].dstrect.x + 20;
      d[i].pips[6].y = d[i].dstrect.y + 50;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;
    }

    // 4x0 tile
    if (d[i].top == 4 && d[i].bottom == 0) {
      /////////////////////////////////////
      // TOP PIPS
      /////////////////////////////////////
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

    // 3x3 tile
    if (d[i].top == 3 && d[i].bottom == 3) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
      
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

      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////
      // top-left pip
      d[i].pips[3].x = d[i].dstrect.x + 4;
      d[i].pips[3].y = d[i].dstrect.y + 40;
      d[i].pips[3].w = 6;
      d[i].pips[3].h = 6;

      // mid-center pip
      d[i].pips[4].x = d[i].dstrect.x + 22;
      d[i].pips[4].y = d[i].dstrect.y + 50;
      d[i].pips[4].w = 6;
      d[i].pips[4].h = 6;

      // bottom-right pip
      d[i].pips[5].x = d[i].dstrect.x + 40;
      d[i].pips[5].y = d[i].dstrect.y + 60;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;
    }

    // 3x2 tile
    if (d[i].top == 3 && d[i].bottom == 2) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
      
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

      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////
       
      // top-left pip
      d[i].pips[3].x = d[i].dstrect.x + 4;
      d[i].pips[3].y = d[i].dstrect.y + 40;
      d[i].pips[3].w = 6;
      d[i].pips[3].h = 6;

      // bottom-right pip
      d[i].pips[4].x = d[i].dstrect.x + 40;
      d[i].pips[4].y = d[i].dstrect.y + 60;
      d[i].pips[4].w = 6;
      d[i].pips[4].h = 6;
    }

    // 3x1 tile
    if (d[i].top == 3 && d[i].bottom == 1) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
      
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

      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////      
      d[i].pips[3].x = d[i].dstrect.x + 22;
      d[i].pips[3].y = d[i].dstrect.y + 50;
      d[i].pips[3].w = 6;
      d[i].pips[3].h = 6;
    }

    // 3x0 tile
    if (d[i].top == 3 && d[i].bottom == 0) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
      
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

    // 2x2 tile
    if (d[i].top == 2 && d[i].bottom == 2) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
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
      
      ///////////////////////////////////
      // BOTTOM PIPS
      ///////////////////////////////////

      // top-left pip
      d[i].pips[2].x = d[i].dstrect.x + 4;
      d[i].pips[2].y = d[i].dstrect.y + 40;
      d[i].pips[2].w = 6;
      d[i].pips[2].h = 6;

      // bottom-right pip
      d[i].pips[3].x = d[i].dstrect.x + 40;
      d[i].pips[3].y = d[i].dstrect.y + 60;
      d[i].pips[3].w = 6;
      d[i].pips[3].h = 6;
    }

    // 2x1 tile
    if (d[i].top == 2 && d[i].bottom == 1) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
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

      ////////////////////////////////////
      // BOTTOM PIPS
      ////////////////////////////////////
      // mid-center pip
      d[i].pips[2].x = d[i].dstrect.x + 22;
      d[i].pips[2].y = d[i].dstrect.y + 50;
      d[i].pips[2].w = 6;
      d[i].pips[2].h = 6;
    }

    // 2x0 tile
    if (d[i].top == 2 && d[i].bottom == 0) {
      ////////////////////////////////////
      // TOP PIPS
      ////////////////////////////////////
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

    // 1x1 tile
    if (d[i].top == 1 && d[i].bottom == 1) {
      //////////////////////////////////////
      // TOP PIPS
      //////////////////////////////////////
      d[i].pips[0].x = d[i].dstrect.x + 22;
      d[i].pips[0].y = d[i].dstrect.y + 15;
      d[i].pips[0].w = 6;
      d[i].pips[0].h = 6;

      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////
      d[i].pips[1].x = d[i].dstrect.x + 22;
      d[i].pips[1].y = d[i].dstrect.y + 50;
      d[i].pips[1].w = 6;
      d[i].pips[1].h = 6;
    }

    // 1x0 tile
    if (d[i].top == 1 && d[i].bottom == 0) {
      //////////////////////////////////////
      // TOP PIPS
      //////////////////////////////////////
      d[i].pips[0].x = d[i].dstrect.x + 20;
      d[i].pips[0].y = d[i].dstrect.y + 15;
      d[i].pips[0].w = 6;
      d[i].pips[0].h = 6;
    }

    // 0x0 tile
    if (d[i].top == 0 && d[i].bottom == 0) {
      return;
    }
  }
}

void render_domino(SDL_Renderer* r, SDL_Rect tile_rect[]) {
  SDL_RenderFillRect(r, tile_rect);
    
  //SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
}

void render_pips(SDL_Renderer* r, SDL_Rect pip_rects[]) {
  SDL_SetRenderDrawColor(r, 255, 0, 0, 255); // pip color
  
  for (int i=0; i <= 6 ; i++) {
    SDL_RenderFillRect(r, &pip_rects[i]);
  }

  SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
}
