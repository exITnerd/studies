#include <iostream>

//Definiowana jest funkcja alokacjaPamieci, która służy do przydzielenia pamięci dla dwuwymiarowej tablicy za pomocą funkcji malloc.
//Przyjmuje dwa parametry całkowite "w" i "k" i zwraca int**.
int** alokacjaPamieci(int w, int k)
{
    int** macierz;
    macierz = (int**)malloc(w * sizeof(int));
    for (int i = 0; i < w; i++)
        macierz[i] = (int*)malloc(k * sizeof(int));
    //https://learn.microsoft.com/pl-pl/cpp/code-quality/c6386?f1url=%3FappId%3DDev16IDEF1%26l%3DPL-PL%26k%3Dk(C6386)%26rd%3Dtrue&view=msvc-170
    return macierz;
}

//Funkcja odczytMacierzy odczytuje macierz z pliku i przypisuje ją do "m".
void odczytMacierzy(const char* nazwaPliku, int**& m, int& w, int& k)
{
    FILE* plik;
    errno_t error;
    //Otwiera plik przekazany jako pierwszy parametr za pomocą funkcji fopen_s i przypisuje wskaźnik pliku do pliku.
    error = fopen_s(&plik, nazwaPliku, "r");
    if (error != 0)
    {
        printf("Nie znaleziono pliku!");
        exit(1);
    }
    //Następnie odczytuje dwie pierwsze liczby całkowite z pliku, aby uzyskać liczbę wierszy i kolumn danej macierzy.
    fscanf_s(plik, "%d %d", &w, &k);

    //Następnie używa funkcji alokacjaPamieci() do przydzielenia pamięci dla m.
    m = alokacjaPamieci(w, k);

    //Następnie odczytuje pozostałe elementy macierzy z pliku za pomocą pętli for.
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
        {
            fscanf_s(plik, "%d", &m[i][j]);
        }
    }
    fclose(plik);
}

//Funkcja wyswietlanieMacierzy przyjmuje jako parametry macierz (int**), liczbę wierszy (int) i liczbę kolumn (int).
void wyswietlanieMacierzy(int** m, int w, int k)
{
    printf("Macierz: \n");
    //Wykorzystuje zagnieżdżone pętle for do iteracji po wierszach i kolumnach macierzy, wypisując każdy element.
    for (int x = 0; x < w; x++)
    {
        printf("%i W:", x + 1);
        for (int y = 0; y < k; y++)
        {
            printf(" %i", m[x][y]);
        }
        printf("\n");
    }
}

//Funkcja czyszczeniaPamieci przyjmuje jako parametry macierz (int**) i liczbę wierszy (int).
void czyszczeniePamieci(int** macierz, int w)
{
    //Wykorzystuje zagnieżdżoną pętlę do iteracji po wierszach macierzy, zwalniając pamięć przydzieloną dla każdego wiersza.
    for (int i = 0; i < w; i++)
    {
        free(macierz[i]);
    }
    //Następnie zwalnia pamięć przydzieloną dla macierzy.
    free(macierz);
}



int main()
{

    int w_A = 0, k_A = 0;
    int w_B = 0, k_B = 0;

    int** A = NULL;
    int** B = NULL;
    int** C = NULL;

    //Wywołuje odczytMacierzyw celu odczytania pierwszej i drugiej macierzy z plików oraz przypisania ich wartości do A i B.
    odczytMacierzy("macierz1.txt", A, w_A, k_A);
    odczytMacierzy("macierz2.txt", B, w_B, k_B);

    //Wywołuje wyswietlanieMacierzy, aby wypisac obie macierze używane do mnożenia.
    wyswietlanieMacierzy(A, w_A, k_A);
    wyswietlanieMacierzy(B, w_B, k_B);

    //Sprawdza, czy liczba kolumn pierwszej macierzy jest równa liczbie wierszy drugiej macierzy, używając instrukcji if. Jeśli nie są sobie równe, drukuje komunikat o błędzie i wychodzi z programu.
    if (k_A != w_B)
    {
        printf("Liczba kolumn w macierzy A musi być taka sama jak ilosc wierszy w macierzy B\n");

        return 1;
    }

    //Program wywołuje alokacjęPamieci(w_A, k_B) w celu przydzielenia pamięci dla wynikowej macierzy C.
    C = alokacjaPamieci(w_A, k_B);

    //Następnie wykorzystuje zagnieżdżone pętle do wykonania mnożenia macierzy, iterując po wierszach A i kolumnach B oraz wykonując iloczyn skalarny w każdej komórce wynikowej macierzy.
    for (int x = 0; x < w_A; x++)
    {
        for (int y = 0; y < k_B; y++)
        {
            int suma = 0;
            for (int i = 0; i < k_A; i++)
            {
                suma += A[x][i] * B[i][y];
            }
            C[x][y] = suma;
        }
    }
    printf("Macierz C: \n");
    //Wypisuje wartości macierzy wynikowej C.
    for (int x = 0; x < w_A; x++)
    {
        for (int y = 0; y < k_B; y++)
        {
            printf(" %i", C[x][y]);
        }
        printf("\n");
    }

    //Następnie program otwiera plik „wynik.txt” do zapisu i zapisuje wynikową macierz do pliku.
    FILE* plik;
    errno_t err1;
    err1 = fopen_s(&plik, "wynik.txt", "w");
    for (int i = 0; i < w_A; i++) {
        for (int j = 0; j < k_B; j++) {
            fprintf(plik, "%d ", C[i][j]);
        }
        fprintf(plik, "\n");
    }
    fclose(plik);

    //Na koniec wywołuje funkcję czyszczeniePamieci w celu wyczyszczenia pamięci przydzielonej macierzom.
    czyszczeniePamieci(A, w_A);
    czyszczeniePamieci(B, w_B);
    czyszczeniePamieci(C, w_A);
}
