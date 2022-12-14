//Napisz program, który wczytuje ze standardowego wejścia współczynniki układu dwóch równań liniowych z dwoma  niewiadomymi i  wypisuje  na  standardowym  wyjściu  rozwiązanie  układu  równań.  W  przypadku nieskończonej liczby lub braku rozwiązań program powinien wypisać na standardowym wyjściu odpowiednią informację. 
#include <iostream>

void main()
{
    float a1;
    float b1;
    float c1;
    float a2;
    float b2;
    float c2;
    float wx;
    float wy;
    float w;
    float wxw;
    float wyw;
    printf("Podaj wspolczynnik a1\n");
    scanf_s("%f", &a1);
    printf("Podaj wspolczynnik b1\n");
    scanf_s("%f", &b1);
    printf("Podaj wspolczynnik c1\n");
    scanf_s("%f", &c1);
    printf("Podaj wspolczynnik a2\n");
    scanf_s("%f", &a2);
    printf("Podaj wspolczynnik b2\n");
    scanf_s("%f", &b2);
    printf("Podaj wspolczynnik c2\n");
    scanf_s("%f", &c2);

    wx = ((c1 * b2) - (b1 * c2));
    wy = ((a1 * c2) - (c1 * a2));
    w = ((a1 * b2) - (b1 * a2));
    wxw = (wx / w);
    wyw = (wy / w);

    if (w != 0)
    {
        printf("x = %f\n", wxw);
        printf("y = %f\n", wyw);
    }
    else if ((wx == 0) && (wy == 0))
    {
        printf("Uklad niezonaczony");
    }
    else
    {
        printf("Uklad sprzeczny");
    }
}
