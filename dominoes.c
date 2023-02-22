#include "dominoes.h"
#include <stddef.h>


Domino* create_domino_set() {
  int size = 28;

  Domino* domino_set = (Domino*) calloc(0, sizeof(Domino*) * size);
  
  printf("sizeof domino_set = %d\n", sizeof(domino_set));
  
  int count = 0;

  for (int i=6; i >= 0; i--) {
    for (int j=i; j >= 0; j--) {
      domino_set[count].top = i;
      domino_set[count].bottom = j;
      count++;
    }
  }
 
  /*
  for (int i=0; i < sizeof(domino_set); i++) {
    printf("domino[%d].top = %d\t", i, domino_set[i].top);
    printf("domino[%d].bottom = %d\n", i, domino_set[i].bottom);
  }
  */
  
  printf("count = %d\n", count);
  return domino_set;
}


