#include <stdio.h>

int getNumber() {
  int n = 0;
  printf("Podaj liczbę: ");
  fflush( stdout );
  int isNumber = scanf("%d", &n);

  if (isNumber) {
    return n;
  } else {
    printf("To nie liczba!\n");
  }
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
  int n = 0;
  printf("Podaj liczbę: ");
  fflush( stdout );
  int isNumber = scanf("%d", &n);

  if (!isNumber) {
    printf("To nie liczba!\n");
    return 0;
  }

  findBinary(n);
  printf("\n");

  return 0;
}