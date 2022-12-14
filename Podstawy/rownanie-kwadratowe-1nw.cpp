//Napisz  program,  który  wczytuje  ze  standardowego  wejścia  współczynniki  równania  kwadratowego  z  jedną niewiadomą  i  wypisuje  na  standardowym  wyjściu  wszystkie  rozwiązania  rzeczywiste  tego  równania  lub odpowiednią informację w przypadku braku rozwiązań. 
#include <iostream>

int main()
{
    float a;
    float b;
    float c;
    float delta;
    float x1;
    float x2;
    printf("Podaj wspolczynnik a: ");
    scanf_s("%f", &a);
    printf("Podaj wspolczynnik b: ");
    scanf_s("%f", &b);
    printf("Podaj wspolczynnik c: ");
    scanf_s("%f", &c);
    delta = ((b*b)-(4*a*c));
    x1 = (-b - sqrt(delta)) / (2 * a);
    x2 = (-b + sqrt(delta)) / (2 * a);
    if (delta > 0)
    {
        printf("Rozwiazania tego ukladu rownan to:\n");
        printf("X1 = %f\n", x1);
        printf("X2 = %f\n", x2);
    }
    else if (delta == 0)
    {
        printf("Ten uklad ma tylko jedno rozwiazanie\n");
        printf("X = %f\n", x1);
    }
    else 
    {
        printf("Delta wynosi %f, czyli mniej niz zero. Brak rozwiazan!", delta);
    }
}
