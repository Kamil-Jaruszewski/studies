#include <stdio.h>
#include <stdlib.h>

int checkNumber(char *input) {
  int i = 0;

  while (*input != '\0') {
    if (*input >= 48 && *input <= 57) {
      if (i == 0 && *input == 48) {
        printf("Błędne dane!\n");
        return 0;
      }
      input++;
    } else {
      printf("Błędne dane!\n");
      return 0;
    }

    i++;
  }

  input = input - i;
  int number = 0;

  while (*input != '\0') {
    number = number + (*input - '0');
    number = number * 10;
    input++;
  }

  number = number / 10;

  return number;
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
  char input[32];

  printf("Podaj liczbe: ");
  fflush(stdout);
  scanf("%s", &input);

  int number = checkNumber(input);
  if (number) findBinary(number);

  return 0;
}