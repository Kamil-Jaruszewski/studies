#include <stdio.h>
#include <stdlib.h>

int main() {
  int random;

  while (random != 6) {
    random = rand()%6 + 1;
    if (random != 6) {
      printf("%i\n", random);
    } else {
      printf("\x1b[34m%i\n", random);
    }
  }

  return 0;
}
