#include <stdio.h>

int main() {
  char s1, s2, s3;
  int isPassed = 0, i;

  printf("\nSędzia 1(y/n): ");
  fflush(stdout);
  scanf(" %c", &s1);

  printf("\nSędzia 2(y/n): ");
  fflush(stdout);
  scanf(" %c", &s2);

  printf("\nSędzia 3(y/n): ");
  fflush(stdout);
  scanf(" %c", &s3);
  
  if (s1 == 'y') isPassed++;
  if (s2 == 'y') isPassed++;
  if (s3 == 'y') isPassed++;

  if (isPassed >= 2) {
    printf("\n\x1b[32mZDAŁEŚ!!!\x1b[0m\n");
  } else {
    printf("\n\x1b[31mNIE ZDANE\x1b[0m\n");
  }

  return 0;
}