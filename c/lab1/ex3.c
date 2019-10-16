#include <stdio.h>

int main() {
  float a, b;
  char operator;

  printf("Podaj liczbę a: ");
  fflush(stdout);
  scanf("%F", &a);

  printf("Podaj liczbę b: ");
  fflush(stdout);
  scanf("%F", &b);

  printf("Podaj operator: ");
  fflush(stdout);
  scanf("%s", &operator);

  switch (operator)
  {
  case '+':
    printf("%F + %F = %f\n", a, b, a + b);
    break;

  case '-':
    printf("%F - %F = %f\n", a, b, a - b);
    break;

  case '*':
    printf("%F * %F = %f\n", a, b, a * b);
    break;

  case '/':
    printf("%F / %F = %f\n", a, b, a / b);
    break;

  default:
    printf("%c to zły operator\n", operator);
    break;
  }

  return 0;
}
