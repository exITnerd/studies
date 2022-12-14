//Napisz program, który wczytuje ze standardowego wejścia trzy liczby całkowite i wypisuje na standardowym wyjściu największą z ich wartości (pamiętaj o przypadku gdy wszystkie podane liczby lub dwie z nich są równe).  
int main()
{
    int c;
    int d;
    int e;
    printf("Podaj trzy liczby całkowite\n");
    scanf_s("%i", &c);
    scanf_s("%i", &d);
    scanf_s("%i", &e);
    if (c > d && (c > e || c == e))
    {
        printf("Liczba %i jest największa\n", c);
    }
    else if ((c > d || c == d) && (c > e))
    {
        printf("Liczba %i jest największa\n", c);
    }
    else if (d > c && (d > e || d == e))
    {
        printf("Liczba %i jest największa\n", d);
    }
    else if ((d > c || d == c) && (d > e))
    {
        printf("Liczba %i jest największa\n", d);
    }
    else if (e > c && (e > d || e == d))
    {
        printf("Liczba %i jest największa\n", e);
    }
    else if ((e > c || e == c) && (e > d))
    {
        printf("Liczba %i jest największa\n", e);
    }
    else
        printf("Wszystkie liczby są takie same!\n");
}
//Tak, da się łatwiej, to bardziej w celu ćwiczenia ifów
