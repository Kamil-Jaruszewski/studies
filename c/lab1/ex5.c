#include <stdio.h>

int main() {
  char a;
  a = getchar();
  if (a < 91 && a > 64 ) {
    printf("To jest wielka litera");
  } else {
    printf("To NIE jest wielka litera");
  }

  return 0;
}
