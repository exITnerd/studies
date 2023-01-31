#include <iostream>
#include<stdio.h>
#include <errno.h>

int main() {
    srand(time(0));
    unsigned short i, j, row, col;
    FILE* zapis;
    errno_t err;

    if ((err = fopen_s(&zapis, "generatorfile.txt", "w")) != 0) {
        printf("Niepowodzenie tworzenia pliku.");
    }
    else {
        printf("Podaj ilosc wierszy generowanej macierzy: ");
        scanf_s("%hu", &row);
        fprintf(zapis, "%d ", row);
        printf("Podaj ilosc kolumn generowanej macierzy: ");
        scanf_s("%hu", &col);
        fprintf(zapis, "%d\n", col);
        printf("\n");

        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                int rand1 = (rand() % 100 + 1);
                printf("%d ", rand1);
                fprintf(zapis, "%d ", rand1);
            }
            printf("\n");
            fprintf(zapis, "\n");
        }
        printf("\nWygenerowana macierz dostepna rowniez w pliku generatorfile:\nC:/Users/NazwaUzytkownika/source/repos/KalkulatorMacierzy/GeneratorMacierzy\n");
        fclose(zapis);
    }
}
