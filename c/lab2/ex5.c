#include <stdio.h>

int main() {
  printf("   ");
  for(int i=1; i<=10; i++){
    printf("\x1b[31m%d\x1b[0m   ",i);
  }

  printf("\n");

  for(int j=1; j<=10; j++){
    j < 10 ? printf("\x1b[31m %d\x1b[0m ",j) : printf("\x1b[31m%d\x1b[0m ",j);

    for(int i=1; i<=10; i++){
      i*j < 10 ? printf("0%d  ",i*j) : printf("%d  ",i*j);
    }

    printf("\n");
  }

}