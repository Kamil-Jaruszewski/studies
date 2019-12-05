#include <stdio.h>

int main() {
  struct student {
    char nazwisko[20];
    char data_ur[11];
    int nr_indeksu;
    int ocena1;
    int ocena2;
    int ocena3;
  } studenci[3];

  int n = 3, i = 0;

  do {
    printf("Podaj dane studenta:\n");

    printf("Nazwisko: ");
    fflush( stdout );
    scanf(" %s", &studenci[i].nazwisko);

    printf("Data urodzenia (dd-mm-yyyy): ", studenci[i].data_ur);
    fflush( stdout );
    scanf(" %s", studenci[i].data_ur);

    printf("Numer indeksu: ", studenci[i].nr_indeksu);
    fflush( stdout );
    scanf(" %d", &studenci[i].nr_indeksu);

    printf("Podstawy programowania (ocena 2-5): ", studenci[i].ocena1);
    fflush( stdout );
    scanf(" %d", &studenci[i].ocena1);

    printf("Podstawy sys-operacyjnych (ocena 2-5): ", studenci[i].ocena2);
    fflush( stdout );
    scanf(" %d", &studenci[i].ocena2);

    printf("Algorytmy i truktury danych (ocena 2-5): ", studenci[i].ocena3);
    fflush( stdout );
    scanf(" %d", &studenci[i].ocena3);

    i++;
  } while (i < n);

  for (i = 0; i < n; i++) {
    printf("Student %d: %s\n", i, studenci[i].nazwisko);
  }

  return 0;
}