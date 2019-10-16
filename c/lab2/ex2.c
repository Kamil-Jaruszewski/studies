#include <stdio.h>

int main() {
  unsigned char kod = 32;

  while (kod != 255) {
    for (int i = 0; i < 16; i++) {
      printf("\x1b[31m%i\x1b[0m:%c ", i + 1, kod);
      if (kod == 255) {
        printf("\n");
        return 0;
      };
      kod++;
    }

    printf("\n");
  }

  return 0;
}