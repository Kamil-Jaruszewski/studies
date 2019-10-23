#include <stdio.h>
#include <string.h>

int main() {
  char *a = "tekst1";
  char *b = "2tekst2";

  printf("%s\n", a);
  printf("%s\n", b);

  a = strcat(*a, *b);

  printf("%s\n", a);

  printf("\n\n");
  return 0;
}