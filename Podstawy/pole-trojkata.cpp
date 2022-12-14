//Napisz program obliczający pole trójkąta na podstawie wymiarów podanych przez użytkownika. Użytkownik powinien mieć możliwość podania długości podstawy i wysokości lub wszystkich boków trójkąta. 
#include <iostream>

int main()
{    
    int typobliczen;
    float wysokosc;
    float podstawa;
    float bok1;
    float bok2;
    float bok3;
    float pole;
    float polowaobwodu;
//tak, można to zdefiniować szybciej poprzez float pole, bok1, bok2, bok3 etc.
    printf("Wybierz sposob w jaki chcesz obliczyc pole trojkata.\nW tym celu wybierz jedna z opcji:\n1.Obliczanie przy uzyciu dlugosci podstawy i jej wysokosci.\n2.Obliczanie przy pomocy dlugosci bokow trojkata.\n");
    scanf_s("%i", &typobliczen);
    if (typobliczen == 1)
    {
        printf("Podaj dlugosc podstawy trojkata:\n");
        scanf_s("%f", &podstawa);
        printf("Podaj dlugosc wyokosci trojkata:\n");
        scanf_s("%f", &wysokosc);
        pole = (podstawa / 2) * wysokosc;
        printf("Pole trojkata wynosi: %.2f jednostek kwadratowych.\n", pole);
    }
    else if (typobliczen == 2)
    {
        printf("Podaj dlugosc pierwszego boku trojkata:\n");
        scanf_s("%f", &bok1);
        printf("Podaj dlugosc drugiego boku trojkata:\n");
        scanf_s("%f", &bok2);
        printf("Podaj dlugosc trzeciego boku trojkata:\n");
        scanf_s("%f", &bok3);
        polowaobwodu = (bok1 + bok2 + bok3) / 2;
        //printf("Polowa obwodu trojkata wynosi %.2f\n", polowaobwodu);
        pole = sqrt((polowaobwodu * (polowaobwodu - bok1) * (polowaobwodu - bok2) * (polowaobwodu - bok3)));
        printf("Pole trojkata wynosi: %.2f jednostek kwadratowych.\n", pole);
    }
    else
    {
        printf("Wybrano nieprawidlowa funkcje, nalezy wybrac 1 lub 2");
    }
}
