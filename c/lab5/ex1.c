#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct student student;

void wczytajStudentow();
void posortujStudentow();
void znajdzNajlepszego();
void znajdzNajlepszaS();
student *znajdzStudenta(char *nazwisko);
void wyswietlStudenta(char* nazwisko);
void usunStudenta();
void zamienStudenta(int i);

//Pobierz 2 znaki i je porownaj ze soba
//0 -> te same, inny wynik -> inne
int posort(const char **a, const char **b)
{
    return strcmp(*a, *b);
}

//Struktura do przechowania danych
struct student {
    int ID;
    char nazwisko[20];
    char dataUr[9];
    int indeks;
    float oceny[3];
};

//Tablica wszystkich studentow
student** studenci;
int iloscStudentow;

int main() {
    wczytajStudentow();

    int wybor;

    do{
        printf("/n Wybierz opcje z menu: ");
        printf("\n 1. Znajdz najlepszego studenta.");
        printf("\n 2. Posortuj studentow");
        printf("\n 3. Znajdz najlepsza srednia");
        printf("\n 4. Usun studenta");
        printf("\n 5. Wyjdz z programu\n");
        scanf("%d", &wybor);

        switch(wybor){
            case 1: znajdzNajlepszego();
                break;
            case 2: posortujStudentow();
                break;
            case 3: znajdzNajlepszaS();
                break;
            case 4: usunStudenta();
                break;
            case 5: printf("\n KONIEC PROGRAMU \n");
                break;
            default: printf("\n Wybierz poprawna opcje \n");
                break;
        }

    }while(wybor != 5);

    return 0;
}

void wczytajStudentow() {
    int n = 0;
    //n - zmienna tymczasowa do przechowania ilosci studentow
    printf("Podaj ilosc studentow: ");
    scanf("%d", &n);
    //Jezeli jest mniej niz 1 student do wczytania to zakoncz program, bo nie mamy co robic
    if (n < 1) {
        return 0;
    }
    //przypisanie wartosci do zmiennej iloscStudentow, zeby miec zmienna globalna, z ktorej bedzie
    //mozna korzystac w calym pliku
    iloscStudentow = n;

    //zarezerwuj tyle pamieci ile zajmuje wskaznik do struktury [*student x ilosc]
    studenci = (student **)malloc(iloscStudentow * sizeof(struct student*));

    int i = 0;
    for (i = 0; i < iloscStudentow; i++) {
        //zarezerwuj tyle pamieci ile zajmuje jedna struktura do kazdego studenta [student x ilosc]
        studenci[i] = (student*)malloc(iloscStudentow * sizeof(struct student));
        //Zarezerwuj pamiec dla nazwiska i daty urodzenia
        //Data urodzenia: RRRRMMDD
        char* nazw = (char*)malloc(20 * sizeof(char));
        int ind = 0;
        char* dataUr = (char*)malloc(10 * sizeof(char));
        float matma = 0;
        float polski = 0;
        float informatyka = 0;
        printf("Podaj nazwisko studenta %d: ", i + 1);
        scanf("%s", nazw);
        //Skopiowanie wczytanego nazwiska do nazwiska z wskaznika
        strcpy(studenci[i]->nazwisko, nazw);

        printf("Podaj ID studenta %d: ", i + 1);
        scanf("%d", &ind);
        //ID
        studenci[i]->indeks = ind;

        printf("Podaj date urodzenia studenta format:RRRRMMDD %d: ", i + 1);
        scanf("%s", dataUr);
        //Data urodzenia
        strcpy(studenci[i]->dataUr, dataUr);

        printf("Podaj ocene z matematyki studenta %d: ", i + 1);
        scanf("%f", &matma);
        //Ocena z matematyki
        studenci[i]->oceny[0] = matma;

        printf("Podaj ocene z polskiego studenta %d: ", i + 1);
        scanf("%f", &polski);
        //Ocena z polskiego
        studenci[i]->oceny[1] = polski;

        printf("Podaj ocene z informatyki studenta %d: ", i + 1);
        scanf("%f", &informatyka);
        //Ocena z informatyki
        studenci[i]->oceny[2] = informatyka;

        //Zwolnienie z pamieci
        free(nazw);
        free(dataUr);
    }
}

void posortujStudentow() {
    int i = 0;
    //Tablica do przechowania nazwisk
    char *arr[15] = {""};
    //Przeszukanie kazdego studenta
    for (i = 0; i < iloscStudentow; i++) {
        //Dodaj jego nazwisko do tablicy
        arr[i] = studenci[i]->nazwisko;
    }
    //Uzycie funkcji sortowania
    //arr - wskaznik do tablicy
    //iloscStudentow - ilosc danych
    //jaka jest wielkosc pojedynczego ciagu znakow
    //jakiej funkcji porownania ma uzyc funkcja sort
    qsort(&arr, iloscStudentow, sizeof(char*), posort);
    for (i = 0; i < iloscStudentow; i++) {
        //Wyswietl studenta na podstawie imiona
        wyswietlStudenta(arr[i]);
    }
}

//Znajdz najlepszego ucznia z danego przedmiotu: 1 - matematyka, 2 - polski, 3 - informatyka
void znajdzNajlepszego() {
    int przedmiot = 0;
    //Sprawdz, ktory przedmiot bedzie do porownania
    printf("\nPrzedmioty: 1 - matematyka, 2 - polski, 3 - informatyka\n");
    printf("Wpisz jaki przedmiot chcesz sprawdzic: ");
    scanf("%d", &przedmiot);
    //Jezeli wpisalismy zly numer to trzeba to tez zalatwic i skonczyc funkcje
    if (przedmiot < 1 && przedmiot > 3) {
        printf("Nie ma takiego przedmiotu");
        return;
    }
    //do petli
    int i = 0;
    //indeks, ktory bedzie odpowiadac indeksowi najlepszemu studentowi
    int ktory = 0;
    //aktualny max
    int max = 0;

    for (i = 0; i < iloscStudentow; i++) {
        //Sprawdz czy nie jest to student do pominiecia
        if (strcmp("NULL", studenci[i]->nazwisko) != 0) {
            if (i == 0) {
                //Ustaw wartosc poczatkowa jako max i ktory jako 0
                ktory = i;
                max = studenci[i]->oceny[przedmiot - 1];
            }
            else {
                //Jezeli ocena tego studenta jest wieksza to ustaw jako max
                if (studenci[i]->oceny[przedmiot - 1] > max) {
                    max = studenci[i]->oceny[przedmiot - 1];
                    //Ustaw indeks studenta, ktory spelnia warunek bycia najlepszego
                    ktory = i;
                }
            }
        }
    }

    for (i = 0; i < iloscStudentow; i++) {
        //Jezeli indeks to ten, ktorego student byl najlepszy to wyswietl przedmiot i jego ocene
        if (i == ktory) {
            printf("\nStudent o nazwisku %s, ID: %d ma najwieksza ocene z %s [%d]\n", studenci[i]->nazwisko, studenci[i]->indeks, przedmiot == 1 ? "matematyki" : przedmiot == 2 ? "polskiego" : "informatyki", max);
        }
    }
}

//Znajdz najwieksza srednia
void znajdzNajlepszaS() {
    int i = 0;
    float max = 0;
    int ktory = 0;
    for (i = 0; i < iloscStudentow; i++) {
        //Sprawdz czy nie jest to student do pominiecia
        if (strcmp("NULL", studenci[i]->nazwisko) != 0) {
            if (i == 0) {
                //Ustaw wartosc poczatkowa jako max i ktory jako 0
                max = ((studenci[i]->oceny[0] + studenci[i]->oceny[1] + studenci[i]->oceny[2]) / 3);
                ktory = i;
            }
            else {
                //Jezeli srednia jego ocen jest wieksza to ustaw jako max
                if (((studenci[i]->oceny[0] + studenci[i]->oceny[1] + studenci[i]->oceny[2]) / 3) > max) {
                    max = ((studenci[i]->oceny[0] + studenci[i]->oceny[1] + studenci[i]->oceny[2]) / 3);
                    //Ustaw indeks studenta, ktory spelnia warunek bycia najlepszego
                    ktory = i;
                }
            }
        }
    }
    for (i = 0; i < iloscStudentow; i++) {
        //Jezeli indeks to ten, ktorego student byl najlepszy to wyswietl przedmiot i jego ocene
        if (i == ktory) {
            printf("\nStudent o nazwisku %s, ID: %d ma najwieksza srednia z wszystkich przedmiotow [%f]\n", studenci[i]->nazwisko, studenci[i]->indeks, max);
        }
    }
}

void wyswietlStudentow() {
    int i = 0;
    for (i = 0; i < iloscStudentow; i++) {
        //Jezeli wskaznik nie jest nullem i jego nazwisko nie oznacza nie brania pod uwage studenta to wyswietl go
        if (studenci[i] != NULL) {
            wyswietlStudenta(studenci[i]->nazwisko);
        }
    }
}

void wyswietlStudenta(char* nazwisko) {
    if (znajdzStudenta(nazwisko) != NULL) {
        student *ptr = znajdzStudenta(nazwisko);
        //Sprawdz czy nie jest to student, ktory ma nie byc brany pod uwage
        //jesli strcmp zwroci wartosc 0 tzn, ze oba ciagi sa takie same, jezeli cos innego tzn, ze nie sa
        if (strcmp("NULL", ptr->nazwisko) != 0) {
            //Wyswietl wszystkie dane zgodnie z formatem
            printf("\nNazwisko: %s\n\tIndeks: %d\n\tData urodzenia: %s\n\tOceny:\n\t\tMatematyka: %.2f\n\t\tPolski: %.2f\n\t\tInformatyka: %.2f",
                   ptr->nazwisko, ptr->indeks, ptr->dataUr, ptr->oceny[0], ptr->oceny[1], ptr->oceny[2]);
        }
        //Zwolnij miejsce
        ptr = NULL;
        free(ptr);
    }
    else {
        printf("Nie ma takiego studenta\n");
    }
}

student *znajdzStudenta(char *nazwisko) {
    int i = 0;
    for (i = 0; i < iloscStudentow; i++) {
        //Przelec przez petle studentow i jezeli nazwisko studenta sie zgadza to zwroc wskaznik do tego studenta
        //jesli strcmp zwroci wartosc 0 tzn, ze oba ciagi sa takie same, jezeli cos innego tzn, ze nie sa
        if (strcmp(nazwisko, studenci[i]->nazwisko) == 0) {
            return studenci[i];
        }
    }
    return NULL;
}

void wyszukajStudenta() {
    printf("Podaj nazwisko studenta, ktorego chcesz znalezc: ");
    //Zarezerwuj miejsce na 20 znakow
    char *nazwisko = (char*)malloc(20 * sizeof(char));
    scanf("%s", nazwisko);
    wyswietlStudenta(nazwisko);
    //Zwolnij miejsce
    free(nazwisko);
}

void nadpiszStudenta() {
    //Zarezerwuj miejsce na 20 znakow, pamietajac o koncowym
    char *nazwisko = (char*)malloc(20 * sizeof(char));
    printf("\nPodaj nazwisko studenta, ktorego chcesz nadpisac: ");
    scanf("%s", nazwisko);
    //Znajdz studenta po nazwisku i stworz wskaznik
    student *ptr = znajdzStudenta(nazwisko);
    if (ptr != NULL) {
        //Zarezerwuj miejsce na 20 znakow, pamietajac o koncowym
        char* nazw = (char*)malloc(20 * sizeof(char));
        int ind = 0;
        //Zarezerwuj miejsce na 10 znakow, pamietajac o koncowym
        char* dataUr = (char*)malloc(10 * sizeof(char));
        float matma = 0;
        float polski = 0;
        float informatyka = 0;
        printf("Podaj nazwisko studenta: ");
        scanf("%s", nazw);
        //Skopiowanie wczytanego nazwiska do nazwiska z wskaznika
        strcpy(studenci[ptr->ID]->nazwisko, nazw);

        printf("Podaj ID studenta: ");
        scanf("%d", &ind);
        //ID
        studenci[ptr->ID]->indeks = ind;

        printf("Podaj date urodzenia studenta format:RRRRMMDD: ");
        scanf("%s", dataUr);
        //Data urodzenia
        strcpy(studenci[ptr->ID]->dataUr, dataUr);

        printf("Podaj ocene z matematyki studenta: ");
        scanf("%f", &matma);
        //Ocena z matematyki
        studenci[ptr->ID]->oceny[0] = matma;

        printf("Podaj ocene z polskiego studenta: ");
        scanf("%f", &polski);
        //Ocena z polskiego
        studenci[ptr->ID]->oceny[1] = polski;

        printf("Podaj ocene z informatyki studenta: ");
        scanf("%f", &informatyka);
        //Ocena z informatyki
        studenci[ptr->ID]->oceny[2] = informatyka;

        //Zwolnienie z pamieci
        free(nazw);
        free(dataUr);
    }
    else {
        printf("Nie ma takiego studenta");
    }
    //Zwolnij miejsce
    ptr = NULL;
    free(ptr);
    free(nazwisko);
}

void usunStudentow() {
    int i = 0;
    //Najpierw trzeba usunac to co jest w srodku
    for (i = 0; i < iloscStudentow; i++) {
        free(studenci[i]);
    }
    //A potem to co na zewnatrz
    free(studenci);
}

void usunStudenta() {
    //Zarezerwuj miejsce dla zmiennej
    char *nazwisko = (char*)malloc(20 * sizeof(char));
    printf("\nPodaj nazwisko studenta, ktorego chcesz usunac: ");
    scanf("%s", nazwisko);
    int i = 0;
    for (i = 0; i < iloscStudentow; i++) {
        //Jezeli nazwisko sie zgadza to zmien nazwisko studenta na NULL, zeby program go dalej nie przetwarzal
        if (strcmp(nazwisko, studenci[i]->nazwisko) == 0) {
            //strcpy(studenci[i]->nazwisko, "NULL");
            zamienStudenta(i);
            //Ostatnim wskaznikiem bedzie ten co wskazuje na ten co mamy usunac
            free(studenci[iloscStudentow-1]);
            iloscStudentow = iloscStudentow - 1;
            return;
        }
    }
    //Zwolnij miejsce
    free(nazwisko);
}

//z i+1 do i
void zamienStudenta(int i) {
    for (i; i < iloscStudentow-1; i++) {
        if (i < 0 && i >= iloscStudentow - 1) {
            printf("Nie da rady tego zrobic [zamienStudenta dla i = %d z j = %d]", i, i + 1);
            return;
        }
        strcpy(studenci[i]->nazwisko, studenci[i + 1]->nazwisko);
        strcpy(studenci[i]->dataUr, studenci[i + 1]->dataUr);
        studenci[i]->oceny[0] = studenci[i + 1]->oceny[0];
        studenci[i]->oceny[1] = studenci[i + 1]->oceny[1];
        studenci[i]->oceny[2] = studenci[i + 1]->oceny[2];
    }
}
