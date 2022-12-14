//Napisz  program  kalkulator,  który  wykonuje  wybraną  przez  użytkownika  operacją  arytmetyczną  na  dwóch wczytanych  liczbach. Program  powinien  wczytywać  dane  ze  standardowego  wejścia  i  wypisywać  wynik  na standardowym wyjściu.
#include <iostream>

void main()
{   
    double dodawanie;
    double odejmowanie;
    double mnozenie;
    double dzielenie;
    int kalkulator;
    float liczba1;
    float liczba2;

    printf("Podaj pierwsza liczbe\n");
    scanf_s("%f", &liczba1);
    printf("Podaj druga liczbe\n");
    scanf_s("%f", &liczba2);
    printf("Wybierz numer dzialania, ktore chcesz wykonac\n");
    printf("1. DODAWANIE\n");
    printf("2. ODEJMOWANIE\n");
    printf("3. MNOZENIE\n");
    printf("4. DZIELENIE\n");
    scanf_s("%i", &kalkulator);
    switch (kalkulator)
    {
    case 1:
        dodawanie = liczba1 + liczba2;
        printf("Wynikiem %f + %f = %f\n", liczba1, liczba2, dodawanie);
        break;
    case 2:
        odejmowanie = liczba1 - liczba2;
        printf("Wynikiem %f - %f = %f\n", liczba1, liczba2, odejmowanie);
        break;
    case 3:
        mnozenie = liczba1 * liczba2;
        printf("Wynikiem %f * %f = %.f\n", liczba1, liczba2, mnozenie);
        break;
    case 4:
        dzielenie = liczba1 / liczba2;
        printf("Wynikiem %f / %f = %f\n", liczba1, liczba2, dzielenie);
        break;
    default:
        printf("Wybrano niepoprawna operacje");
    }
}
