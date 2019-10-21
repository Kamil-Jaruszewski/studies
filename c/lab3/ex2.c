#include <stdio.h>
#include <stdlib.h>

int getNumber() {
  int n;
  printf("Podaj liczbę: ");
  fflush( stdout );
  scanf("%d", &n);
  return n;
}

int findBinary(int num) {
  int toPrint = 0;

  for (int i = 31; i >= 0; i--) {
    if ((i + 1) % 8 == 0) printf(" ");
    if ((( num >> i ) % 2) < 0) {
      toPrint = -(( num >> i ) % 2);
    } else {
      toPrint = (( num >> i ) % 2);
    }
    printf("%1d", toPrint);
  }

  return 0;
}

int main(int argc, char *argv[]) {
  int result, result2 = 0;

  if (argv[3][0] != 'n') {
    printf(" ");
    findBinary(atoi(argv[1]));
  }
  else {
    printf("~");
    findBinary(atoi(argv[1]));
  }


  switch (argv[3][0]) {
  case 'o':
    printf("\n|");
    result = atoi(argv[1]) | atoi(argv[2]);
    break;

  case 'a':
    printf("\n&");
    result = atoi(argv[1]) & atoi(argv[2]);
    break;

  case 'x':
    printf("\n^");
    result = atoi(argv[1]) ^ atoi(argv[2]);
    break;

  case 'n':
    printf("\n~");
    result = ~atoi(argv[1]);
    result2 = ~atoi(argv[2]);
  default:
    break;
  }

  findBinary(atoi(argv[2]));


  printf("\n");
  if (!result2) {
    printf("=");
    findBinary(result);
  } else {
    printf("=");
    findBinary(result);
    printf("\n=");
    findBinary(result2);
  }

  printf("\n\n");
  return 0;
}