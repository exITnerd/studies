#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned short i, j, row, col;

    printf("Podaj ilosc wierszy generowanej macierzy: ");
    scanf_s("%hu", &row);

    printf("\nPodaj ilosc kolumn generowanej macierzy: ");
    scanf_s("%hu", &col);

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {

            printf("%d ", rand() % 100);
        }
        printf("\n");
    }

    return 0;
}
