#include <stdio.h>

int main() {
  int number;
  int bin[32];

  for (int i = 0; i < 32; i++) bin[i] = 0;

  printf("Podaj liczbę: ");
  fflush( stdout );
  scanf("%d", &number);

  int i = 0;
  int loop_number = number;

  while (loop_number > 0) {
    bin[i] = loop_number % 2;
    loop_number /= 2;
    i++;
  }

  if (bin[4] && bin[10]) {
    printf("\x1b[34mLiczba %d ma wartość 1 w zapisie binarnym na miejscu 5 oraz 11\x1b[0m\n", number);
  } else {
    printf("\x1b[31mLiczba %d nie ma wartości 1 w zapisie binarnym na miejscu 5 oraz 11\x1b[0m\n", number);
  }

  return 0;
}
