#include <stdio.h>

int main() {
  int a = 32123;
  char b[32];

  printf("float: %f\n", (float)a);
  sprintf(b, "%d", a);
  printf("string: %s\n", b);
}
