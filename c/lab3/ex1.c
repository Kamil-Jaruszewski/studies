#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
  char *p, s[32];
  int n;

  printf("Podaj liczbę: ");
  fflush( stdout );

  while (fgets(s, sizeof(s), stdin)) {
    fflush(stdout);
    n = strtoq(s, &p, 10);
    fflush(stdout);

    if (p == s || *p != '\n' || *p != '-') {
      fflush(stdout);
      printf("To nie jest poprawne wejście dla tego ćwiczenia! Podaj liczbę: ");
      fflush(stdout);
    } else {
      fflush(stdout);
      break;
      fflush(stdout);

    };
  }
  fflush(stdout);

  printf("\n");

  fflush(stdout);

  findBinary(n);

  fflush(stdout);

  printf("\n");
  fflush(stdout);

  return 0;
}