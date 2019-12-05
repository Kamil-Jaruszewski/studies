#include <stdio.h>
#include <math.h>

// Cholera wie czemu do kompilatora muszę użyć parametrów w taki sposób:
//    gcc ex4.c -lm -Wall

double doSqrt(double liczba) {
  double wynik = sqrt(liczba);
  printf("sqrt(%f) = %f", liczba, wynik);
  return wynik;
}

double doSin(double liczba) {
  double wynik = sin(liczba);
  printf("sin(%f) = %f", liczba, wynik);
  return wynik;
}

double doExp(double liczba) {
  double wynik = exp(liczba);
  printf("exp(%f) = %f", liczba, wynik);
  return wynik;
}

void oblicz(double (*wskNaFun)(double liczba), double liczba) {
  wskNaFun(liczba);
}

double (*wskdoSqrt)(double liczba);
double (*wskdoSin)(double liczba);
double (*wskdoExp)(double liczba);

int main() {
  wskdoSqrt = doSqrt;
  wskdoSin = doSin;
  wskdoExp= doExp;

  oblicz(wskdoSqrt, 123.0);
  printf("\n");
  oblicz(wskdoSin, 123.0);
  printf("\n");
  oblicz(wskdoExp, 123.0);
  printf("\n");
  return 0;
}