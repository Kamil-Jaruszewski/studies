#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    char nazwisko[20];
    char data_ur[11];
    int nr_indeksu;
    int ocena1;
    int ocena2;
    int ocena3;
};

void findStudent(struct student *studenci, int size) {
  char text[30];
  printf("Podaj nazwisko studenta ktorego chcesz wyszukac: "); // enter surname
  fflush(stdout);
  scanf(" %s", &text);

  for (int i = 0; i < size; i++) {
    if (strcmp(text, studenci[i].nazwisko) == 0) {
      printf("O to dane znalezionego studenta:\n\n"); // Data of finded student

      printf("Nazwisko: %s\n", studenci[i].nazwisko); // surname
      printf("Data Urodzenia: %s\n", studenci[i].data_ur); // birthdate
      printf("Podstawy programowania: %d\n", studenci[i].ocena1); // programming basics
      printf("Podstawy sys-operacyjnych: %d\n", studenci[i].ocena2); // OS basics
      printf("Algorytmy i truktury danych: %d\n", studenci[i].ocena3); // algorithms and data structures

      return;
    }

  }

  printf("Nie znaleziono studenta o nazwisku %s!", text); // "student not found "

  return;
}

int main() {
  int n;
  printf("Podaj liczbe studentow: "); // enter count of students
  fflush( stdout );
  scanf(" %d", &n);

  struct student studenci[n];

  int i = 0;

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

  printf("\n\nWyszukiwanie: \n");
  findStudent(studenci, n);

  return 0;
}