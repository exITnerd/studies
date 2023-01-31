#include "stdlib.h"
#include "stdio.h"
#include "string.h"
/*
int malloc_free_counter = 0;

static inline void* my_malloc(int size) {
    malloc_free_counter++;
    return malloc(size);
}

static inline void my_free(void *memory_address) {
    malloc_free_counter--;
    free(memory_address);
}
*/

struct DaneOsobowe {
    char Nazwisko[40];
    char Imie[20];
    int Wiek;
    char Pesel[12];
    char Plec; //k - (kobieta) m - (mezczyzna)
};

struct ListaOsob {
    struct ListaOsob *wsk_gora; //wskaznik na gorny element listy
    struct DaneOsobowe dane;
    struct ListaOsob *wsk_dol; //wskaznik na dolny element listy
};

void WprowadzanieDanychPrzezUsera(struct ListaOsob *lo) {
    printf("Podaj nazwisko dodawanej osoby:\n");
    scanf_s("%s", lo->dane.Nazwisko, _countof(lo->dane.Nazwisko));

    printf("Podaj imie dodawanej osoby:\n");
    scanf_s("%s", lo->dane.Imie, _countof(lo->dane.Imie));

    printf("Podaj wiek dodawanej osoby:\n");
    scanf_s("%d", &lo->dane.Wiek);
    while (lo->dane.Wiek <= 0 || (*lo).dane.Wiek > 125) {
        printf("Wiek musi byc wiekszy od 0 i mniejszy lub rowny 125. Podaj wiek ponownie: \n");
        scanf_s("%d", &lo->dane.Wiek);
    }

    printf("Podaj pesel dodawanej osoby:\n");
    char pesel_input[12];
    scanf_s("%s", pesel_input, _countof(pesel_input));
    while (pesel_input[11] != '\0' || strlen(pesel_input) != 11) {
        printf("PESEL musi byc 11 znakowy. Podaj PESEL ponownie:\n");
        scanf_s("%s", pesel_input, _countof(pesel_input));
    }

    strcpy_s(lo->dane.Pesel, _countof(lo->dane.Pesel), pesel_input);

    printf("Podaj plec dodawanej osoby (m/k):\n");
    scanf_s(" %c", &lo->dane.Plec, 1);
    while (lo->dane.Plec != 'm' && lo->dane.Plec != 'k') {
        printf("Podaj plec dodawanej osoby (m/k):\n");
        scanf_s(" %c", &lo->dane.Plec, 1);
    }
    //tudaj wypisuje dane w jednej linijce z przecinkami
    char data[100] = {0};
    sprintf_s(data, _countof(data), "%s,%s,%d,%s,%c", lo->dane.Nazwisko, lo->dane.Imie, lo->dane.Wiek, lo->dane.Pesel, lo->dane.Plec);
}

void Dodawanie(struct ListaOsob **dane) {                                                   // pobiera wskaznik do adresu pierwszego elementu listy dwukierunkowej
    struct ListaOsob *temp = *dane;                                                         // tymczasowa zmienna pomocnicza, do której przypisany zostanie adres pierwszego elementu listy
    
    if (*dane) {                                                                            // jeżeli adres pierwszego elementu listy nie jest równy 0
        struct ListaOsob *lo = (struct ListaOsob*) malloc(sizeof(struct ListaOsob));        // utwórz nowy element listy
        
        if (lo == NULL) {
            printf("Blad: nie mozna zaalokowac pamieci dla listy osob... (linia: %d)\n", __LINE__);
            return;
        }

        WprowadzanieDanychPrzezUsera(lo);                                                   // ustawia wartosci do przypisania

        while (temp->wsk_dol) {                                                             // znajduje ostatni element listy
            temp = temp->wsk_dol;
        }
        lo->wsk_gora = temp;                                                                // przypisanie polu wsk_gora nowego elementu listy adresu ostatniego elementu listy
        temp->wsk_dol = lo;                                                                 // przypisanie staremu ostatniemu elementowi listy adresu nowego ostatniego elementu listy
        lo->wsk_dol = 0;                                                                    // przypisanie polu wsk_dol nowego elementu listy wartości zero(ponieważ stanie się on ostatnim elementem listy)
    }
    else {
        *dane = (struct ListaOsob*) malloc(sizeof(struct ListaOsob));                       // tworzenie nowego elementu listy
        WprowadzanieDanychPrzezUsera(*dane);
        (*dane)->wsk_gora = 0;
        (*dane)->wsk_dol = 0;                                       
    }
}
//potem by się przydało zwolnić pamięć free(lo), free(*dane), z tym że nie wiem do konca gdzie można to zrobić, na pewno nie w tej funkcji bo sypie bledami, bo przeciez ta lista jest ciagle w pamieci operacyjnej.
//nie zauwazylem wzrastania zuzycia pamieci w nieskonczonosc

void Wyszukiwanie(struct ListaOsob *dane, const char *nazwisko, struct ListaOsob **znaleziona) {
    struct ListaOsob *temp = dane;
    while (temp) {
        if (strcmp(temp->dane.Nazwisko, nazwisko) == 0) {
            *znaleziona = temp;
            return;
        }
        temp = temp->wsk_dol;
    }
    *znaleziona = NULL;
}

void Usuwanie(struct  ListaOsob **dane, const char *Nazwisko, struct ListaOsob **usuwana) {
    struct ListaOsob *temp = *dane;
    if (temp == NULL) {
        printf("Lista jest pusta, brak elementow do usuniecia\n");
        return;
    }
    if (strcmp(temp->dane.Nazwisko, Nazwisko) == 0) {
        if (temp->wsk_dol == NULL) {                                    //jezeli na liscie istnieje tylko jedna osoba
            *dane = NULL;
        }
        else {
            *dane = temp->wsk_dol;
            temp->wsk_dol->wsk_gora = NULL;
        }
        free(temp);
        printf("Osoba pomyslnie usunieta\n");
        return;
    }
    while (temp->wsk_dol != NULL) {
        if (strcmp(temp->wsk_dol->dane.Nazwisko, Nazwisko) == 0) {
            struct ListaOsob *temp_to_remove = temp->wsk_dol;
            temp->wsk_dol = temp->wsk_dol->wsk_dol;
            if (temp->wsk_dol != NULL) {
                temp->wsk_dol->wsk_gora = temp;
            }
            free(temp_to_remove);
            printf("Usunieto osobe o podanym nazwisku.\n");
            return;
        }
        temp = temp->wsk_dol;
    }
    printf("Nie znaleziono osoby o nazwisku %s.\n", Nazwisko);
}

void Wyswietlanie(struct ListaOsob *dane) {
    if (dane) {
        printf("+-------------------------------------------+\n");
        printf("| Nazwisko | Imie | Wiek |   Pesel   | Plec |\n");
        do {
            printf("%s, %s, %d, %s, %c\n", dane->dane.Nazwisko, dane->dane.Imie, dane->dane.Wiek, dane->dane.Pesel, dane->dane.Plec);
            dane = dane->wsk_dol;
        } while (dane);
        printf("+-------------------------------------------+\n");
    }
}

void OdczytaniePliku(struct ListaOsob **dane) {
    FILE *file = NULL;
    errno_t err = fopen_s(&file, "daneosob.txt", "r");
    if (err != 0) {
        printf("Blad otwarcia pliku\n");
        return;
    }

    char line[100] = { 0 };
    while (fgets(line, sizeof(line), file)) {                                                   //Funkcja fgets odczytuje linię tekstu ze strumienia plików i zapisuje ją w buforze. Funkcja przestaje czytać, gdy osiągnie 
        struct ListaOsob *temp = (struct ListaOsob*) malloc(sizeof(struct ListaOsob));          //koniec linii, koniec pliku lub określoną liczbę znaków, w zależności od tego, co nastąpi wcześniej.

        if (temp == NULL) {
            printf("Blad: nie mozna zaalokowac pamieci dla listy osob... (linia: %d)\n", __LINE__);
            return;
        }

        temp->wsk_gora = NULL;
        temp->wsk_dol = NULL;
        //temp->wsk_gora = NULL" ustawia wskaźnik "wsk_gora" wewnątrz struktury "temp", która jest typu "ListaOsob" na wskazanie NULL. 
        //Wsk_gora jest wskaźnikiem, który wskazuje na górny element listy dwukierunkowej. Ustawiając go na NULL wskazuje, że bieżący element listy, 
        //na który wskazuje "temp", nie ma żadnego górnego elementu.Analogicznie jest w przypadku wsk_dol

        sscanf_s(line, 
            "%[^,]," // Nazwisko
            "%[^,]," // Imie
            "%d," // Wiek
            "%[^,]," // Pesel
            "%c", // Plec
            temp->dane.Nazwisko, _countof(temp->dane.Nazwisko), 
            temp->dane.Imie, _countof(temp->dane.Imie), 
            &temp->dane.Wiek, 
            temp->dane.Pesel, _countof(temp->dane.Pesel), 
            &temp->dane.Plec, 1);

        if (*dane == NULL) {
            *dane = temp;
        }
        else {
            struct ListaOsob* temp2 = *dane;
            while (temp2->wsk_dol != NULL) {
                temp2 = temp2->wsk_dol;
            }
            temp2->wsk_dol = temp;
            temp->wsk_gora = temp2;
        }
    }

    fclose(file);
}

void ZapisywaniePliku(struct ListaOsob *dane, char *nazwaPliku) {
    FILE* plik;
    errno_t err = fopen_s(&plik, nazwaPliku, "w");
    if (err != 0) {
        printf("Blad podczas tworzenia pliku %s.\n", nazwaPliku);
        return;
    }
    while (dane) {
        char data[100];
        sprintf_s(data, _countof(data), "%s,%s,%d,%s,%c\n", dane->dane.Nazwisko, dane->dane.Imie, dane->dane.Wiek, dane->dane.Pesel, dane->dane.Plec);
        //Pierwszym parametrem funkcji jest wskaźnik na bufor, w którym przechowywany jest wynikowy string. W tym przypadku jako bufor wykorzystana jest zmienna "dane".
        //Drugi parametr to rozmiar bufora, w tym przypadku jest to _countof(dane).
        //Trzecim parametrem jest ciąg formatu, który zawiera specyfikatory formatu, które wskazują, jak dane powinny być sformatowane. W tym przypadku ciąg formatu to "%s,%s,%d,%s,%c".
        fprintf(plik, "%s", data);
        dane = dane->wsk_dol;
    }
    fclose(plik);
    printf("Dane zostaly zapisane do pliku %s.\n", nazwaPliku);
}

void SortowanieAZ(struct ListaOsob* poczateklisty) {
    struct ListaOsob* temp = poczateklisty;
    int n = 0;
    while (temp) {
        n++;
        temp = temp->wsk_dol;
    }
    for (int i = 0; i < n; i++) {
        temp = poczateklisty;
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(temp->dane.Nazwisko, temp->wsk_dol->dane.Nazwisko) > 0) {
                struct DaneOsobowe temp_data = temp->dane;
                temp->dane = temp->wsk_dol->dane;
                temp->wsk_dol->dane = temp_data;
            }
            temp = temp->wsk_dol;
        }
    }
    //Sortowanie babelkowe, wolniejsze im dluzsza jest lista, ale proste w implementacji.
    //W każdej iteracji pętli wewnętrznej kod porównuje dane.nazwisko bieżącego elementu (wskazywanego przez "temp") z dane.nazwisko następnego elementu (wskazywanego przez "temp->wsk_dol"). 
    //Jeśli dane.nazwisko bieżącego elementu jest większe niż dane.nazwisko następnego elementu, zamienia dane obu elementów za pomocą zmiennej tymczasowej "temp_data".
}

void SortowanieZA(struct ListaOsob* poczateklisty) {
    struct ListaOsob* temp = poczateklisty;
    int n = 0;
    while (temp) {
        n++;
        temp = temp->wsk_dol;
    }
    for (int i = 0; i < n; i++) {
        temp = poczateklisty;
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(temp->dane.Nazwisko, temp->wsk_dol->dane.Nazwisko) < 0) {
                struct DaneOsobowe temp_data = temp->dane;
                temp->dane = temp->wsk_dol->dane;
                temp->wsk_dol->dane = temp_data;
            }
            temp = temp->wsk_dol;
        }
    }
}

void Menu(struct ListaOsob* dane) {
    
    printf("+---------------------------------------------------------------------------------------------------------+\n");
    printf("1. Dodawanie osoby / osob do listy\n");
    printf("2. Wyszukiwanie osoby / osob po nazwisku lub imieniu\n");
    printf("3. Usuwanie osoby z listy (poprzez podanie jej nazwiska)\n");
    printf("4. Wyswietlanie listy od poczatku\n");
    printf("5. Odczytywanie listy z pliku (dodawanie odczytanych elementow z pliku do istniejacej w pamieci listy)\n");
    printf("6. Zapisywanie listy do pliku\n");
    printf("7. Sortowanie listy po nazwisku\n");
    printf("+---------------------------------------------------------------------------------------------------------+\n");
    printf("Wybierz, co chcesz zrobic wpisujac liczbe odpowiadajaca wybranemu dzialaniu (1-7).\n");

    int opcja;
    while (1) {
        scanf_s("%d", &opcja);
        if (opcja >= 1 && opcja <= 7) {
            break;
        }
        printf("Wprowadzono nieprawidlowa wartosc. Upewnij sie, ze wybierasz opcje pomiedzy 1 a 7!\n");
    }
    struct ListaOsob *osoba = NULL;
    char nazwaPlikuZapis[] = "lista.txt";
    switch (opcja)
    {
    case 1:
        //Dodawanie osoby do listy
        printf("+---------------------+\n");
        printf("Funkcja Dodawanie\n");
        Dodawanie(&dane);
        break;
    case 2:
        //Wyszukiwanie osoby po nazwisku
        printf("+---------------------+\n");
        printf("Funkcja Wyszukiwanie\n");
        char NazwiskoWyszOs[40];
        printf("Podaj nazwisko osoby, ktora chcesz wyszukac:\n");
        scanf_s("%39s", NazwiskoWyszOs, sizeof(NazwiskoWyszOs));
        Wyszukiwanie(dane, NazwiskoWyszOs, &osoba);
        if (osoba) {
            printf("Imie wyszukanej osoby: %s\n", osoba->dane.Imie);
            printf("Wiek wyszukanej osoby: %d\n", osoba->dane.Wiek);
            printf("Pesel wyszukanej osoby: %s\n", osoba->dane.Pesel);
            printf("Plec wyszukanej osoby: %c\n", osoba->dane.Plec);
        }
        else {
            printf("Nie znaleziono osoby o podanym nazwisku!\n");
        }
        break;
    case 3:
        //Usuwanie osoby z listy (poprzez podanie jej nazwiska)
        printf("+---------------------+\n");
        printf("Funkcja Usuwanie\n");
        char NazwiskoUsOs[40];
        printf("Podaj nazwisko osoby, ktora chcesz usunac:\n");
        scanf_s("%39s", NazwiskoUsOs, sizeof(NazwiskoUsOs));
        Usuwanie(&dane, NazwiskoUsOs, &osoba);
        break;
    case 4:
        //Wyswietlanie listy
        printf("+---------------------+\n");
        printf("Funkcja Wyswietlanie\n");
        Wyswietlanie(dane);
        break;
    case 5:
        //Odczytywanie listy z pliku (dodawanie odczytanych elementów z pliku do istniejacej w pamieci listy)
        printf("+---------------------+\n");
        printf("Funkcja OdczytywaniePliku\n");
        OdczytaniePliku(&dane);
        Wyswietlanie(dane);
        break;
    case 6:
        //Zapisywanie listy do pliku
        printf("+---------------------+\n");
        printf("Funkcja ZapisywaniePliku\n");
        ZapisywaniePliku(dane, nazwaPlikuZapis);
        break;
    case 7:
        //Sortowanie listy po nazwisku (od A do Z lub od Z do A)
        printf("+---------------------+\n");
        printf("Funkcja Sortowanie\n");
        if (dane == NULL) {
            printf("Lista jest pusta, aby ja posortowac dodaj do niej jakies osoby.\n");
        }
        else{
            int typsortowania;
            printf("Wybierz, w jaki sposob chcesz posortowac liste:\n");
            printf("1. Sortuj liste od A-Z.\n");
            printf("2. Sortuj liste od Z-A.\n");
            scanf_s("%d", &typsortowania);
            if (typsortowania == 1) {
                SortowanieAZ(dane);
                Wyswietlanie(dane);
            }
            else if (typsortowania == 2) {
                SortowanieZA(dane);
                Wyswietlanie(dane);
            }
            else {
                printf("Sortowanie domyslne od A-Z.\n");
                SortowanieAZ(dane);
                Wyswietlanie(dane);
            }
        }
        break;
    }
    Menu(dane);
}
int main()
{
    struct ListaOsob *dane = NULL;  // wskaźnik na pierwszy element listy
    Menu(dane);
}
