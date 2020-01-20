#include <iostream>
#include <list>
#include <cstring>

class Student {
  char nazwisko[20];
  char data_ur[11];
  int nr_index;
  int ocena1;
  int ocena2;
  int ocena3;

  public:
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

std::list<Student> studenci;

int menu() {
  int option = 0;
  std::cout << "Podaj co chcesz zrobic?\n";
  std::cout << "   1. Usun studenta\n";
  std::cout << "   2. Wyszukaj studenta wg nazwiska\n";
  std::cout << "   3. Posortowanie studentow alfabetycznie\n";
  std::cout << "   4. Student ktory najwyzsza ocene z danego przedmiotu\n";
  std::cout << "   5. Student z najwyzsza ocena\n";

  return option;
}

void findStudent() {
  char text[32];

  std::cout << "Podaj nazwisko studenta ktorego chcesz wyszukac: ";
  std::cin >> text;

  for (int i = 0; i < studenci.size(); i++) {
    // if (text == studenci)
  }

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

  switch (menu())
  {
  case 1:
    /* code */
    break;
  case 2:
    findStudent();
    break;
  default:
    break;
  }

  return 0;
}