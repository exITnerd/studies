//Napisz  program,  który  wczytuje  ze  standardowego  wejścia  liczbę  wymierną  i  wypisuje  ją  na standardowym wyjściu z dokładnością do dwóch miejsc po przecinku. 
#include <iostream>
#include <cmath>

int main()
{
    float liczbawymierna;
    printf("Wprowadź liczbę wymierną, a otrzymasz ją w zaokrągleniu do 2 miejsc po przecinku\n");
    scanf_s("%f", &liczbawymierna);
    printf("Ta liczba z dokładnością do 2 liczb po przecinku to %.2f\n", liczbawymierna);
}
    //Aby uzyskać zaokrąglenie do innej liczby, wystarczy zmienić liczbę po prawej stronie ---> %.2f\n.
