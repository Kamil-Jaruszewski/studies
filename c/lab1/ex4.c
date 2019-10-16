#include <stdio.h>

int main() {
  float a, b, c;

  printf("Podaj liczbę a: ");
  fflush(stdout);
  scanf("%F", &a);

  printf("Podaj liczbę b: ");
  fflush(stdout);
  scanf("%F", &b);

  printf("Podaj liczbę c: ");
  fflush(stdout);
  scanf("%F", &c);

  if (a > b) {
    if (a > c) {
      printf("Największa liczba to a: %F\n", a);
    } else {
      printf("Największa liczba to c: %F\n", c);
    }
  } else {
    if (b > c) {
      printf("Największa liczba to b: %F\n", b);
    } else {
      printf("Największa liczba to c: %F\n", c);
    }
  }

  return 0;
}
