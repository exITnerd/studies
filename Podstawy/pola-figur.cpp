//Napisz  program,  który  w  zależności  od  wyboru  użytkownika  wczytuje  ze  standardowego  wejścia  wymiary: kwadratu, prostokąta lub trójkąta i wypisuje na standardowym wyjściu pole figury o wczytanych wymiarach.
#include <iostream>

int main()
{
    float kwadrat;
    float trojkat;
    float prostokat;
    int figura;
    float a;
    float b;
    float h;
    printf("Wybierz figure ktorej pole\n");
    printf("Aby obliczyc pole kwadratu wybierz 1, dla prostokata wybierz 2, a dla trojkata wybierz 3\n");
    scanf_s("%i", &figura);
    switch (figura)
    {
    case 1:
        printf("Aby obliczyc pole kwadratu podaj dlugosc jego boku\n");
        scanf_s("%f", &a);
        kwadrat = (a * a);
        printf("Pole kwadratu wynosi %f\n", kwadrat);
            break;
    case 2:
        printf("Aby obliczyc pole prostokata podaj dlugosc pierwszego boku\n");
        scanf_s("%f", &a);
        printf("Aby obliczyc pole prostokata podaj dlugosc drugiego boku\n");
        scanf_s("%f", &b);
        prostokat = (a * b);
        printf("Pole prostokata wynosi %f\n", prostokat);
            break;
    case 3:
        printf("Aby obliczyc pole trojkata podaj dlugosc podstawy\n");
        scanf_s("%f", &a);
        printf("Aby obliczyc pole trojkata podaj dlugosc wysokosci\n");
        scanf_s("%f", &h);
        trojkat = ((a/2) * h);
        printf("Pole trojkata wynosi %f\n", trojkat);
            break;
    default:
        printf("Wprowadz prawidlowa wartosc!\n");
}
