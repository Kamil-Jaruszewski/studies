#include <stdio.h>

#include "silnia.c"
#include "silniaReku.c"

int main() {
  int number = 0;
  unsigned long long strong;

  printf("Podaj liczbę: ");
  fflush( stdout );
  scanf(" %d", &number);

  strong = silniaInt(number);
  printf("Silnia z liczby %d używając \x1b[33mint\x1b[0m to %lld\n\n", number, strong);

  strong = silniaLong(number);
  printf("Silnia z liczby %d używając \x1b[33mLong\x1b[0m to %lld\n\n", number, strong);

  strong = silniaLongLong(number);
  printf("Silnia z liczby %d używając \x1b[33mLongLong\x1b[0m to %lld\n\n", number, strong);

  strong = silniaUnsignedLongLong(number);
  printf("Silnia z liczby %d używając \x1b[33mUnsignedLongLong\x1b[0m to %lld\n\n", number, strong);

  strong = silniaReku(number);
  printf("Silnia z liczby %d używając funkcji rekurencyjnej to %lld\n\n", number, strong);
  return 0;
}