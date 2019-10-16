#include <stdio.h>

int main() {
  float a, b, c, d;

  printf("Podaj liczbę a: ");
  fflush(stdout);
  scanf("%F", &a);

  printf("Podaj liczbę b: ");
  fflush(stdout);
  scanf("%F", &b);

  printf("Podaj liczbę c: ");
  fflush(stdout);
  scanf("%F", &c);

  printf("Podaj liczbę d: ");
  fflush(stdout);
  scanf("%F", &d);

  int dodatnie = 0, ujemne = 0;

  if (a > 0) dodatnie++;
  else ujemne++;
  if (b > 0) dodatnie++;
  else ujemne++;
  if (c > 0) dodatnie++;
  else ujemne++;
  if (d > 0) dodatnie++;
  else ujemne++;

  if (dodatnie > ujemne) {
    printf("Więcej dodatnich");
  } else {
    if (dodatnie == ujemne) {
      printf("Tyle samo dodatnich jak i ujemnych");
    } else {
      printf("Więcej ujemnych");
    }
  }

  return 0;
}
