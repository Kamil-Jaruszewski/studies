#include <stdio.h>
#include <string.h>

void zlicz_wystapienia(char* tekst, int* litery, int* cyfry) {
  for (int i = 0; i < strlen(tekst); i++) {
    char currChar = tekst[i];
    if (currChar >= 97 && currChar <= 127) {
      litery[currChar - 97] = litery[currChar - 97] + 1;
    } else if (currChar >= 48 && currChar <=57) {
      cyfry[currChar - 48] = cyfry[currChar - 48] + 1;
    }
  }
}

int sumarr(int *arr, int arrsize) {
  int sum = 0;

  for (int i = 0; i < arrsize; i++) {
    sum += arr[i];
  }

  return sum;
}

void ile_danego_znaku(int* litery, int* cyfry,  char znak) {
  if (znak >= 97 && znak <= 127) {
    printf("Litera: %c występuje: %d razy", znak, litery[znak - 97]);
  } else if (znak >= 48 && znak <=57) {
    printf("Cyfra: %c występuje: %d razy", znak, cyfry[znak - 97]);
  }
} 

int main() {
  int l[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int c[10] = {0,0,0,0,0,0,0,0,0,0};
  char *tekst = "Its quiet Too quiet 0 Vievers 010255";
  int *litery = l, *cyfry = c;

  zlicz_wystapienia(tekst, litery, cyfry);

  printf("\nW napisie \"%s\":\n", tekst);
  printf("Małych liter jest: %d\n", sumarr(litery, 26));
  printf("Cyfr jest: %d\n\n", sumarr(cyfry, 10));

  ile_danego_znaku(litery, cyfry, 'e');

  printf("\n\n");

  return 0;
}