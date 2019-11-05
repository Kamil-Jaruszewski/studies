#include <stdio.h>
#include <string.h>

void sklej(char *wska, char *wskb) {
  strcat(wska, wskb);
  puts(wska);
}

int main() {
  char a[30] = "tekst1";
  char b[30] = "2tekst2";

  printf("%s\n", a);
  printf("%s\n", b);

  sklej(&a, &b);

  return 0;
}