#include <stdio.h>

 
int main() {
  //int i = 6;
  //int j = i;
  int count = 0;
  for (int i = 6; i >= 0; i--) {
    for (int j = i; j >= 0; j--) {
      printf("i = %d\t", i);
      printf("j = %d\n", j);
      count++;
    }
  }

  printf("total dominoes = %d\n", count);
}
