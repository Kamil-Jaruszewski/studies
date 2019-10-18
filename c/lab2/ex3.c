#include <stdio.h>

int main() {
  int n;
  int l;

  printf("Podaj ile liczb chcesz podać: ");
  fflush( stdout );
  scanf("%d", &n);

  int sum = 0;

  while (n > 0) {
    printf("Podaj następną liczbę: ");
    fflush( stdout );
    scanf("%d", &l );
    sum += l;
    n--;
  }

  printf("Twoja suma to: %d\n", sum);

  return 0;
}