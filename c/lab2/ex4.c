#include <stdio.h>

int main() {
  int x, y;

  char dash = 104;
  char wall = 124;

  printf("Podaj x: ");
  fflush( stdout );
  scanf("%d", &x);

  printf("Podaj y: ");
  fflush( stdout );
  scanf("%d", &y);

  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      if (i == 0 || i == y-1) {
        if (j == 0 || j == x-1) {
          printf("+");
        } else {
          printf("-");
        }
      } else {
        if (j == 0 || j == x-1) {
          printf("|");
        } else {
          printf(" ");
        }
      }
    }
    printf("\n");
  }
}