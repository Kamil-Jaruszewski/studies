#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

class Student {
  public:

  char nazwisko[20];
  char data_ur[11];
  int nr_index;
  int ocena1;
  int ocena2;
  int ocena3;

  Student() {
    std::cout << "Podaj nazwisko: ";
    std::cin >> nazwisko;
    std::cout << "Podaj dat urodzenia: ";
    std::cin >> data_ur;
    std::cout << "Podaj numer indeksu: ";
    std::cin >> nr_index;
    std::cout << "Podaj ocene z podstaw programowania: ";
    std::cin >> ocena1;
    std::cout << "Podaj ocene z podstaw sys-operacyjnych: ";
    std::cin >> ocena2;
    std::cout << "Podaj ocene z algorytmow i struktur dancyh: ";
    std::cin >> ocena3;
    std::cout << "\n\n";
  }
};

std::vector<Student> studenci;

void showStudents() {
  for (int i = 0; i < studenci.size(); i++) {
    std::cout << "\n\n";
    std::cout << "Nazwisko: " << studenci[i].nazwisko << "\n";
    std::cout << "Data urodzenia: " << studenci[i].data_ur << "\n";
    std::cout << "Podstawy programowania: " << studenci[i].ocena1 << "\n";
    std::cout << "Podstawy sys-op: " << studenci[i].ocena2 << "\n";
    std::cout << "Alg. i str. danych: " << studenci[i].ocena3 << "\n";
  }
  std::cout << "\n\n";
}

int menu() {
  int option = 0;
  std::cout << "Podaj co chcesz zrobic?\n";
  std::cout << "   1. Usun studenta\n";
  std::cout << "   2. Wyszukaj studenta wg nazwiska\n";
  std::cout << "   3. Posortowanie studentow alfabetycznie\n";
  std::cout << "   4. Student ktory najwyzsza ocene z danego przedmiotu\n";
  std::cout << "   5. Student z najwyzsza srednia ocen\n";
  std::cout << "A więc?: ";
  std::cin >> option;
  std::cout << "\n";
  return option;
}

void findStudent() {
  char text[32];

  std::cout << "Podaj nazwisko studenta ktorego chcesz wyszukac: ";
  std::cin >> text;

  for (int i = 0; i < studenci.size(); i++) {
    if (strcmp(text, studenci[i].nazwisko) == 0) {
      std::cout << "O to dane znalezionego studenta:\n";

      std::cout << "Nazwisko: " << studenci[i].nazwisko << "\n";
      std::cout << "Data urodzenia: " << studenci[i].data_ur << "\n";
      std::cout << "Podstawy programowania: " << studenci[i].ocena1 << "\n";
      std::cout << "Podstawy sys-operacyjnych: " << studenci[i].ocena2 << "\n";
      std::cout << "Algorytmy i struktury danych: " << studenci[i].ocena3 << "\n";
      return;
    }
  }

  std::cout << "Nie znaleziono studenta o nazwisku: " << text << "!";

  return;
}

void removeStudent() {
  char text[32];
  std::cout << "Podaj naziwsko studenta, ktorego chcesz usunac: ";
  std::cin >> text;

  for (int i = 0; i < studenci.size(); i++) {
    if (strcmp(text, studenci[i].nazwisko) == 0) {
      studenci.erase(studenci.begin() + i, studenci.begin()+i+1);
      std::cout << "Student o nawisku: " << text << " zostal usuniety poprawnie";
      return;
    }
  }

  std::cout << "Nie znaleziono studenta!";

  return;
}

void findHighestMark() {
  int choose, max = 2, studentMax = 0, size = studenci.size();

  std::cout << "Studenta z najwyzsza ocena z jakiego przedmiotu znalezc?\n";
  std::cout << "Podstawy programowania (1), Podstawy sys-op (2), Alg. i str. danych (3): ";
  std::cin >> choose;

  switch (choose)
  {
  case 1:
    for (int i = 0; i < size; i++) {
      if (studenci[i].ocena1 > max) {
        max = studenci[i].ocena1;
        studentMax = i;
      }
    }
    std::cout << "Najwyzsza ocene z podstaw programowania ma student o nazwisku: " << studenci[studentMax].nazwisko << "\n";
    break;
  case 2:
    for (int i = 0; i < size; i++) {
      if (studenci[i].ocena2 > max) {
        max = studenci[i].ocena2;
        studentMax = i;
      }
    }
    std::cout << "Najwyzsza ocene z sys-op ma student o nazwisku: " << studenci[studentMax].nazwisko << "\n";
    break;
  case 3:
    for (int i = 0; i < size; i++) {
      if (studenci[i].ocena3 > max) {
        max = studenci[i].ocena3;
        studentMax = i;
      }
    }
    std::cout << "Najwyzsza ocene z alg. i str. danych ma student o nazwisku: " << studenci[studentMax].nazwisko << "\n";
    break;
  default:
    break;
  }
}

void findHighestAvarage() {
  float maxAvg = 0;
  int studentIndex, size = studenci.size();

  for (int i = 0; i < size; i++) {
    int tempAvg = (studenci[i].ocena1 + studenci[i].ocena2 + studenci[i].ocena3) / 3;

    if (tempAvg > maxAvg) {
      maxAvg = tempAvg;
      studentIndex = i;
    }
  }

  std::cout << "Najwyzsza srednia ocen ma student o nazwisku: " << studenci[studentIndex].nazwisko << " i wynosi ona: " << maxAvg << "\n";
}

int posort(const Student& a, const Student& b) {
  return strcmp(a.nazwisko, b.nazwisko);
}

void sortStudents() {
  std::sort(studenci.begin(), studenci.end(), posort);
  return;
}

int main() {
  int ile;

  std::cout << "Podaj liczbe studentow: ";
  std::cin >> ile;

  for (int c = 0; c < ile; c++ ) {
    Student new_student;
    studenci.push_back(new_student);
  }

  showStudents();

  switch (menu()) {
    case 1:
      removeStudent();
      showStudents();
      break;
    case 2:
      findStudent();
      break;
    case 3:
      sortStudents();
      showStudents();
      break;
    case 4:
      findHighestMark();
      break;
    case 5:
      findHighestAvarage();
      break;
    default:
      break;
  }

  return 0;
}