//Napisz program, który wczytuje ze standardowego wejścia nieujemną liczbę wymierną x i wypisuje na standardowym wyjściu √x. 
#include <iostream>
#include <cmath>

int main()
{
    float x;
    double pierwiastek;
    printf("Podaj liczbę wymierną, aby obliczyć z niej pierwiastek\n");
    scanf_s("%f", &x);
        if (x >= 0) 
        {
            pierwiastek = sqrt(x);
            printf("Pierwiastek podanej liczby to: %f\n", pierwiastek);
        }
        else
        {
            printf("Liczba jest ujemna, nie można znaleźć pierwiastka!\n");
        }
}
