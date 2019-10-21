#include <stdio.h>

int getNumber() {
  int n;
  printf("Podaj liczbę: ");
  fflush( stdout );
  scanf("%d", &n);
  return n;
}

int findBinary(char *n) {
  printf("Postać binarna to: ");

  int num = (int)n;

  for (int i = 31; i >= 0; i--) {
    if ((i + 1) % 8 == 0) printf(" ");
    printf("%1d", (( num >> i ) % 2));
  }

  return 0;
}

int main(int argc, char *argv[]) {

  printf(" ");
  findBinary(argv[1]);
  printf("\n+");
  findBinary(argv[2]);
  printf("\n=");
  // findBinary(((int)argv[1] ^ (int)argv[2]));

  return 0;
}