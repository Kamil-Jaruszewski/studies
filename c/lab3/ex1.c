#include <stdio.h>

int getNumber() {
  int n;
  printf("Podaj liczbę: ");
  fflush( stdout );
  scanf("%d", &n);
  return n;
}

int findBinary(int n) {
  printf("Postać binarna to: ");

  for (int i = 31; i >= 0; i--) {
    if ((i + 1) % 8 == 0) printf(" ");
    printf("%1d", (( n >> i ) % 2));
  }

  return 0;
}

int main() {
  int number;

  number = getNumber();
  findBinary(number);
  printf("\n");

  return 0;
}