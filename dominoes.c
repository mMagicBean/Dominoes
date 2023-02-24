#include "dominoes.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h> 


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

void create_domino_pips(Domino* d) {
  for (int i=0; i <= 12; i++) {
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
      d[i].pips[6].y = d[i].dstrect.y + 60;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // top-right pip
      d[i].pips[7].x = d[i].dstrect.x + 30;
      d[i].pips[7].y = d[i].dstrect.y + 60;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;

      // mid-center pip
      d[i].pips[8].x = d[i].dstrect.x + 25;
      d[i].pips[8].y = d[i].dstrect.y + 55;
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
      d[i].pips[6].y = d[i].dstrect.y + 40;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // top-right pip
      d[i].pips[7].x = d[i].dstrect.x + 40;
      d[i].pips[7].y = d[i].dstrect.y + 40;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;

      // bottom-left pip
      d[i].pips[8].x = d[i].dstrect.x + 4;
      d[i].pips[8].y = d[i].dstrect.y + 55;
      d[i].pips[8].w = 6;
      d[i].pips[8].h = 6;

      // bottom - right pip
      d[i].pips[9].x = d[i].dstrect.x + 40;
      d[i].pips[9].y = d[i].dstrect.y + 55;
      d[i].pips[9].w = 6;
      d[i].pips[9].h = 6;
    }

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
      d[i].pips[6].y = d[i].dstrect.y + 4;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // mid-center pip
      d[i].pips[7].x = d[i].dstrect.x + 20;
      d[i].pips[7].y = d[i].dstrect.y + 15;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;

      // bottom-right pip
      d[i].pips[8].x = d[i].dstrect.x + 40;
      d[i].pips[8].y = d[i].dstrect.y + 25;
      d[i].pips[8].w = 6;
      d[i].pips[8].h = 6;
    }

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
      d[i].pips[6].y = d[i].dstrect.y + 4;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // bottom-right pip
      d[i].pips[7].x = d[i].dstrect.x + 40;
      d[i].pips[7].y = d[i].dstrect.y + 25;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;
    }

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
      d[i].pips[6].x = d[i].dstrect.x + 20;
      d[i].pips[6].y = d[i].dstrect.y + 15;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;
    }

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
      d[i].pips[5].y = d[i].dstrect.y + 4;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;

      // top-right pip
      d[i].pips[6].x = d[i].dstrect.x + 40;
      d[i].pips[6].y = d[i].dstrect.y + 4;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // mid-center pip
      d[i].pips[7].x = d[i].dstrect.x + 20;
      d[i].pips[7].y = d[i].dstrect.y + 15;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;

      // bottom-left pip
      d[i].pips[8].x = d[i].dstrect.x + 4;
      d[i].pips[8].y = d[i].dstrect.y + 25;
      d[i].pips[8].w = 6;
      d[i].pips[8].h = 6;

      // bottom-right pip
      d[i].pips[9].x = d[i].dstrect.x + 40;
      d[i].pips[9].y = d[i].dstrect.y + 25;
      d[i].pips[9].w = 6;
      d[i].pips[9].h = 6;
    }

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
      d[i].pips[5].x = d[i].dstrect.x + 4;
      d[i].pips[5].y = d[i].dstrect.x + 4;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;

      // top-right pip
      d[i].pips[6].x = d[i].dstrect.x + 40;
      d[i].pips[6].y = d[i].dstrect.y + 4;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // bottom-left pip
      d[i].pips[7].x = d[i].dstrect.x + 4;
      d[i].pips[7].y = d[i].dstrect.y + 25;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;

      // bottom - right pip
      d[i].pips[8].x = d[i].dstrect.x + 40;
      d[i].pips[8].y = d[i].dstrect.y + 25;
      d[i].pips[8].w = 6;
      d[i].pips[8].h = 6;
    }

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
      d[i].pips[5].y = d[i].dstrect.y + 4;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;

      // mid-center pip
      d[i].pips[6].x = d[i].dstrect.x + 20;
      d[i].pips[6].y = d[i].dstrect.y + 15;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // bottom-right pip
      d[i].pips[7].x = d[i].dstrect.x + 40;
      d[i].pips[7].y = d[i].dstrect.y + 25;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;
    }

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
      d[i].pips[5].y = d[i].dstrect.y + 4;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;

      // bottom-right pip
      d[i].pips[6].x = d[i].dstrect.x + 40;
      d[i].pips[6].y = d[i].dstrect.y + 25;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;
    }

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
      d[i].pips[5].x = d[i].dstrect.x + 20;
      d[i].pips[5].y = d[i].dstrect.y + 15;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;
    }

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

    if (d[i].top == 4 && d[i].bottom == 4) {
      /////////////////////////////////////
      // TOP PIPS
      /////////////////////////////////////
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
      
      ////////////////////////////////////
      // BOTTOM PIPS
      ////////////////////////////////////
      d[i].pips[4].x = d[i].dstrect.x + 4;
      d[i].pips[4].y = d[i].dstrect.x + 4;
      d[i].pips[4].w = 6;
      d[i].pips[4].h = 6;

      // top-right pip
      d[i].pips[5].x = d[i].dstrect.x + 40;
      d[i].pips[5].y = d[i].dstrect.y + 4;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;

      // bottom-left pip
      d[i].pips[6].x = d[i].dstrect.x + 4;
      d[i].pips[6].y = d[i].dstrect.y + 25;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;

      // bottom - right pip
      d[i].pips[7].x = d[i].dstrect.x + 40;
      d[i].pips[7].y = d[i].dstrect.y + 25;
      d[i].pips[7].w = 6;
      d[i].pips[7].h = 6;
    }

    if (d[i].top == 4 && d[i].bottom == 3) {
      /////////////////////////////////////
      // TOP PIPS
      /////////////////////////////////////
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

      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////
      // top-left pip
      d[i].pips[4].x = d[i].dstrect.x + 4;
      d[i].pips[4].y = d[i].dstrect.y + 4;
      d[i].pips[4].w = 6;
      d[i].pips[4].h = 6;

      // mid-center pip
      d[i].pips[5].x = d[i].dstrect.x + 20;
      d[i].pips[5].y = d[i].dstrect.y + 15;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;

      // bottom-right pip
      d[i].pips[6].x = d[i].dstrect.x + 40;
      d[i].pips[6].y = d[i].dstrect.y + 25;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;
    }

    if (d[i].top == 4 && d[i].bottom == 2) {
      /////////////////////////////////////
      // TOP PIPS
      /////////////////////////////////////
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

      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////
       
      // top-left pip
      d[i].pips[4].x = d[i].dstrect.x + 4;
      d[i].pips[4].y = d[i].dstrect.y + 4;
      d[i].pips[4].w = 6;
      d[i].pips[4].h = 6;

      // bottom-right pip
      d[i].pips[5].x = d[i].dstrect.x + 40;
      d[i].pips[5].y = d[i].dstrect.y + 25;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;
    }

    if (d[i].top == 4 && d[i].bottom == 1) {
      /////////////////////////////////////
      // TOP PIPS
      /////////////////////////////////////
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
      ///////////////////////////////////////////
      // BOTTOM PIPS
      ///////////////////////////////////////////
      // mid-center pip
      d[i].pips[6].x = d[i].dstrect.x + 20;
      d[i].pips[6].y = d[i].dstrect.y + 15;
      d[i].pips[6].w = 6;
      d[i].pips[6].h = 6;
    }

    if (d[i].top == 4 && d[i].bottom == 0) {
      /////////////////////////////////////
      // TOP PIPS
      /////////////////////////////////////
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
      d[i].pips[3].y = d[i].dstrect.y + 4;
      d[i].pips[3].w = 6;
      d[i].pips[3].h = 6;

      // mid-center pip
      d[i].pips[4].x = d[i].dstrect.x + 20;
      d[i].pips[4].y = d[i].dstrect.y + 15;
      d[i].pips[4].w = 6;
      d[i].pips[4].h = 6;

      // bottom-right pip
      d[i].pips[5].x = d[i].dstrect.x + 40;
      d[i].pips[5].y = d[i].dstrect.y + 25;
      d[i].pips[5].w = 6;
      d[i].pips[5].h = 6;
    }

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
      d[i].pips[3].y = d[i].dstrect.y + 4;
      d[i].pips[3].w = 6;
      d[i].pips[3].h = 6;

      // bottom-right pip
      d[i].pips[4].x = d[i].dstrect.x + 40;
      d[i].pips[4].y = d[i].dstrect.y + 25;
      d[i].pips[4].w = 6;
      d[i].pips[4].h = 6;
    }

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
      d[i].pips[3].x = d[i].dstrect.x + 20;
      d[i].pips[3].y = d[i].dstrect.y + 15;
      d[i].pips[3].w = 6;
      d[i].pips[3].h = 6;
    }

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
      d[i].pips[2].y = d[i].dstrect.y + 4;
      d[i].pips[2].w = 6;
      d[i].pips[2].h = 6;

      // bottom-right pip
      d[i].pips[3].x = d[i].dstrect.x + 40;
      d[i].pips[3].y = d[i].dstrect.y + 25;
      d[i].pips[3].w = 6;
      d[i].pips[3].h = 6;
    }

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
      d[i].pips[2].x = d[i].dstrect.x + 20;
      d[i].pips[2].y = d[i].dstrect.y + 15;
      d[i].pips[2].w = 6;
      d[i].pips[2].h = 6;
    }

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

    if (d[i].top == 1 && d[i].bottom == 1) {
      //////////////////////////////////////
      // TOP PIPS
      //////////////////////////////////////
      d[i].pips[0].x = d[i].dstrect.x + 20;
      d[i].pips[0].y = d[i].dstrect.y + 15;
      d[i].pips[0].w = 6;
      d[i].pips[0].h = 6;

      /////////////////////////////////////
      // BOTTOM PIPS
      /////////////////////////////////////
      d[i].pips[1].x = d[i].dstrect.x + 20;
      d[i].pips[1].y = d[i].dstrect.y + 15;
      d[i].pips[1].w = 6;
      d[i].pips[1].h = 6;
    }

    if (d[i].top == 1 && d[i].bottom == 0) {
      //////////////////////////////////////
      // TOP PIPS
      //////////////////////////////////////
      d[i].pips[0].x = d[i].dstrect.x + 20;
      d[i].pips[0].y = d[i].dstrect.y + 15;
      d[i].pips[0].w = 6;
      d[i].pips[0].h = 6;
    }

    if (d[i].top == 0 && d[i].bottom == 0) {
      return;
    }
  }
}


void render_domino(SDL_Renderer* r, SDL_Rect tile_rect[]) {
  SDL_RenderFillRect(r, tile_rect);
  SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
  
  /*
    SDL_SetRenderDrawColor(r, 255, 0, 0, 255); // pip color
  
  for (int i=0; i <= 12; i++) {
    SDL_RenderFillRect(r, &pip_rects[i]);
  }
  */
}

void render_pips(SDL_Renderer* r, SDL_Rect pip_rects[]) {
  SDL_SetRenderDrawColor(r, 255, 0, 0, 255); // pip color

  for (int i=0; i < 12; i++) {
    SDL_RenderFillRect(r, &pip_rects[i]);
  }

  SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
}

int* grab_rand_domino(Domino* d) {
  int lower = 0, upper = 28;
  
  srand(time(0));
  
  int r_num1 = (rand() % (upper - lower + 1)) + lower;
  int r_num2 = (rand() % (upper - lower + 1)) + lower;
  int r_num3 = (rand() % (upper - lower + 1)) + lower;
  int r_num4 = (rand() % (upper - lower + 1)) + lower;
  int r_num5 = (rand() % (upper - lower + 1)) + lower;
  int r_num6 = (rand() % (upper - lower + 1)) + lower;

  int r_numarr[6] = {r_num1, r_num2, r_num3, r_num4, r_num5, r_num6};
  
  return r_numarr;
}

void handle_mouse(Domino* d, SDL_Event event) {
  int mousex = 0, mousey = 0;
  SDL_GetMouseState(&mousex, &mousey);
  
  if (SDL_MOUSEMOTION == event.type) {
    printf("x = %d, y = %d\n", mousex, mousey);
  }

  if (SDL_BUTTON_LEFT == event.button.button) {
    if (mousex == d[0].dstrect.x + d[0].dstrect.w &&
	mousey == d[0].dstrect.y + d[0].dstrect.h) {
      d[0].dstrect.x = mousex;
      d[0].dstrect.y = mousey;
    }
    printf("Left button clicked\n");
  }
}
