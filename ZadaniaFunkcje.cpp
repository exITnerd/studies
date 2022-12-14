#include <iostream>
//zmienna gobalna 
int n = 0;

void ZAD1(int n)
{
    if (n >= 0)
    {
        printf("Wartosc bezwgledna liczby n to: %i", n);
    }
    else
    {
        printf("Wartosc bezwgledna liczby n to: %i", -n);
    }
}

void SILNIA()
{
    //int n;
    int silnia = 1;
    for (int i = n; i > 1; i--)
    {
        silnia = silnia * i;
    }
    printf("Silnia liczby n wynosi: %i", silnia);
}

void LiczbaNieujemna()
{
    printf("Podaj liczbe n: \n");
    scanf_s("%i", &n);
    if (n < 0)
    {
        printf("Podaj liczbe nieujemna! \n");
        LiczbaNieujemna();
    }
}
int _LiczbaNieujemna()
{
    printf("Podaj liczbe n: \n");
    scanf_s("%i", &n);
    if (n < 0)
    {
        printf("Podaj liczbe nieujemna! \n");
        LiczbaNieujemna();
    }
    return n;
}

void ZAD3()
{
    
}

void ZAD4(int n)
{
    int dwadontej = 2;
    if (n == 0)
        printf("Wartosc 2^0 wynosi: 1");
    else if (n == 1)
        printf("Wartosc 2^1 wynosi: 2");
    else {
        for (int i = 2; i <= n; i++)
        {
            dwadontej *= 2;
        }
        printf("Wartosc 2^%i wynosi: %i", n, dwadontej);
    }
}

void ZAD5(int n)
{
    int dwadontejjj = 2;
    if (n == 0)
        printf("Wartosc 2^0 wynosi: 1");
    else if (n == 1)
        printf("Wartosc 2^1 wynosi: 2");
    else {
        for (int i = 2; i <= n; i++)
        {
            dwadontejjj *= 2;
        }
        printf("Wartosc 2^%i wynosi: %i", n, dwadontejjj);
    }
}

void ZAD6()
{
    int n;
    int m;
    printf("Podaj liczbe n: \n");
    scanf_s("%i", &n);
    printf("Podaj liczbe m: \n");
    scanf_s("%i", &m);
    if ((n < 0 || m < 0) && n != 0)
    {
        printf("Podaj liczby nieujemne! \n");
        ZAD6();
    }
    else
    {
        int wynik = n;
        if (m == 0)
        {
            printf("Wynik potegowania wynosi: 1\n");
        }
        else
        {
            for (int x = 2; x <= m; x++)
            {
                wynik *= n;
            }
            printf("Wynik potegowania wynosi: %i\n", wynik);
        }

    }
}
void ZAD7()
{
    int n;
    int m;
    printf("Podaj liczbe n: \n");
    scanf_s("%i", &n);
    printf("Podaj liczbe m: \n");
    scanf_s("%i", &m);


    if (m == 0)
    {
        printf("Wynik potegowania wynosi: 1\n");
    }
    else
    {
        float wynik;
        if (m > 0)
        {
            wynik = n;
        }
        else
        {
            wynik = float(1 / n);
        }

        for (int x = 2; x <= abs(m); x++)
        {
            if (m < 0)
            {
                wynik *= float(1 / n);
            }
            else
            {
                wynik *= n;
            }
        }
        printf("Wynik potegowania wynosi: %f \n", wynik);
    }
}

void ZAD8()
{
    float n;
    printf("Podaj liczbe n: \n");
    scanf_s("%f", &n);
    if (n > 0)
    {
        float b = n / 2; // aktualny 'strzal'
        float c = 0; // dzielenie a/strzal
        float d = 0; // srednia z obu
        for (int i = 1; i <= 10; ++i) {
            c = n / b;
            d = (b + c) / 2;
            b = d;
            //printf("Iteracja nr %i wynik: %f \n", i, b);
        }
        printf("Pierwiastek z liczby n wynosi: %f", b);
        //("Faktyczna wartosc : % f",sqrt(n));
    }
    else 
    {
        printf("Podaj liczbe dodatnia!\n");
        ZAD8();
    }
}

void ZAD9()
{
    float n;
    int m;
    printf("Podaj liczbe n: \n");
    scanf_s("%f", &n);
    printf("Podaj liczbe m: \n");
    scanf_s("%i", &m);
    if (n >= 0 && m > 1)
    {
        float b = n / 2; // aktualny 'strzal'
        float c = 0; // dzielenie a/strzal
        float d = 0; // srednia z obu
        for (int i = 1; i <= 10; ++i) {
            c = n / b;
            d = (b + c) / 2;
            b = d;
        }
        printf("Pierwiastek z liczby n wynosi: %f", b);
    }
}

unsigned int NWD(unsigned int a, unsigned int b)
{
    while (a != b)
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    return a;
}

void ZAD10()
{
    int n = 0;
    printf("Podaj liczbe n: \n");
    scanf_s("%i", &n);
    int suma = 0;

    for (int i = 0; i < n; i++)
    {
        if (NWD(i, n))
            suma += i;
    }
    printf("Suma wynosi: %d \n", suma);
}

float pierwiastekKwadratowy(int _n)
{
    float n = _n;
    float b = n / 2.0; // aktualny 'strzal'
    float c = 0; // dzielenie a/strzal
    float d = 0; // srednia z obu
    for (int i = 1; i <= 10; ++i)
    {
        c = n / b;
        d = (b + c) / 2;
        b = d;
        //printf("Iteracja nr %i z liczby %f wynik: %f \n", i,n, b);
    }
    return b;
}

float pierwiastekKwadratowy(int _n)
{
    float n = _n;
    float b = n / 2.0; // aktualny 'strzal'
    float c = 0; // dzielenie a/strzal
    float d = 0; // srednia z obu
    for (int i = 1; i <= 10; ++i)
    {
        c = n / b;
        d = (b + c) / 2;
        b = d;
        //printf("Iteracja nr %i z liczby %f wynik: %f \n", i,n, b);
    }
    return b;
}

void ZAD11()
{
    int n;
    float m;
    printf("Podaj liczbe n: \n");
    scanf_s("%i", &n);
    float sumaPierwiastkow = 0;
    for (int i = 1; i <= n; i++)
    {
        sumaPierwiastkow += pierwiastekKwadratowy(i);
    }
    printf("Suma pierwiastkow wynosi: %f \n", sumaPierwiastkow);
}


void ZAD12()
{
    int n;
    float m;
    printf("Podaj liczbe n: \n");
    scanf_s("%i", &n);
    printf("Podaj liczbe m: \n");
    scanf_s("%f", &m);
    float sumaPierwiastkow = 0;
    for (int i = 1; i <= n; i++)
    {
        sumaPierwiastkow += pierwiastekKwadratowy(i) * m;
    }
    printf("Suma pierwiastkow wynosi: %f \n", sumaPierwiastkow);
}

int pierw(unsigned int x)
{
    int pocz = 0;
    int kon = x;
    int sr;

    while (kon - pocz > 1)
    {
        sr = (pocz + kon) / 2;
        if (sr * sr <= x)
            pocz = sr;
        else
            kon = sr;
    }
    if (x <= 1)
        return kon;
    else
        return pocz;
}

void ZAD13a()
{
    int n;
    printf("Podaj liczbe n: \n");
    scanf_s("%i", &n);

    int p;
    for (int i = 1; i <= pierw(n); i++)
    {
        p = pierw(n - i * i);
        if ((p != 0) && (i * i + p * p == n))
            printf("%d*%d+%d*%d=%d \n", i, i, p, p, n);
    }
}

void ZAD13b()
{
    int n;
    printf("Podaj liczbe n: \n");
    scanf_s("%i", &n);

    int p;
    for (int i = 1; i <= pierw(n); i++)
    {
        p = pierw(n - i * i);
        if ((i * i + p * p == n) && (i < p))
            printf("%d*%d+%d*%d=%d \n", i, i, p, p, n);
    }
}

void ZAD14()
{
    // tresc zadania taka sama jak w 13
}

int potega(int n, int m)
{
    int wynik = n;
    if (m == 1)
    {
        return wynik;
    }
    else if (m == 0)
    {
        return 1;
    }
    else
    {
        for (int i = 2; i <= m; i++)
        {
            wynik *= n;
        }
    }
    return wynik;
}

void ZAD15()
{
    int n;
    printf("Podaj liczbe n: \n");
    scanf_s("%i", &n);
    int m;
    printf("Podaj liczbe m: \n");
    scanf_s("%i", &m);

    int p;
    for (int i = 1; i <= pierw(n); i++)
    {
        p = pierw(n - i * i);
        if ((potega(i, m) + potega(p, m) == n) && (i < p))
            printf("%d^%d+%d^%d=%d \n", i, m, p, m, n);
    }
}

void ZAD17() 
{
    static unsigned int ilosc = 0;
    ilosc++;
    printf("Funkcja wywolana zostala %i razy\n", ilosc);
}

void pseudolosowe(double poprzednia) {
    printf("Liczba: %f\n", poprzednia);
    if (poprzednia < 0.0001)
    {
        return;
    }
    pseudolosowe(1.0 - poprzednia * poprzednia);
}

void ZAD18()
{
    pseudolosowe(0.7);
}

int sumowaniewartosci(int n, int* sum)
{
        *sum += n;
        return n;
}

/*
int ZAD19() 
{
int suma = 0;
int n, a;
printf("Podaj ilosc liczb, ktore chcesz odejmowac lub dodawac\n");
scanf_s("%i", &n);
for (int i = 0; i < n; i++)
{
    scanf_s("%i", &a);
    int f = sumowaniewartosci(a, &suma);
    printf("Podana liczba: %i SUMA: %i\n", f, suma);
    printf("Podaj dowolna liczbe calkowita\n");
}
    return 0;
}

float rek(int n)
{
    float a = 0;
    if (n == 0) a = 1;
    if (n > 0) a = 2 * rek(n - 1) + 5;
    return a;
}
*/

int ZAD19()
{
    int tmp;
    static int suma = 0;

    scanf_s("%i", &tmp);

    suma = suma + tmp;
    printf("Dodałem %i teraz mam %i \n", tmp, suma);

    return tmp;
}

unsigned int ZAD20(unsigned int n)
{
    if (n <= 1)
        return 1;
    else
        return ZAD20(n - 1) * n;
}


float rek1(int n)
{
    float a;
    if (n == 0) a = 1;
    if (n > 0) a = 2 * rek1(n - 1) + 5;
    return a;
}

void ZAD21()
{
    int n;
    printf("Podaj liczbe n: \n");
    scanf_s("%i", &n);
    float wynik = rek1(n);
    printf("Wynik wynosi: %f \n", wynik);
}

float rek2(int n)
{
    float a = 0;
    if (n == 0 || n == 1) a = 1;
    if (n > 1) a = rek2(n - 1) + 2 * rek2(n - 2) + 3;
    return a;
}

void ZAD22()
{
    int n;
    printf("Podaj liczbe n: \n");
    scanf_s("%i", &n);
    float wynik = rek2(n);
    printf("Wynik wynosi: %f \n", wynik);
}

unsigned int ZAD23(unsigned int n)
{
    if (n <= 1)
        return 1;
    else
        return ZAD23(n - 1) + ZAD23(n - 2);
}

unsigned int ZAD24(unsigned int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    int suma = 0;

    for (int i = 0; i < n; i += 1)
    {
        suma = suma + ZAD24(i);
    }

    return suma;
}

unsigned int ZAD25(unsigned int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    if (n % 2 == 0)
    {
        return ZAD25(n - 1) + n;
    }
    else if (n % 2 == 1)
    {
        return ZAD25(n - 1) * n;
    }
}



unsigned int ZAD26(unsigned int n)
{
    if (n <= 2)
        return 1;
    else
        switch (n % 3)
        {
        case 0:
            return ZAD26(n - 1) + ZAD26(n - 2);
        case 1:
            return 5 * ZAD26(n - 1) + 4;
        case 2:
            return ZAD26(n - 1);
        }
}

unsigned int ZAD27(unsigned int n, unsigned int m)
{
    if (n == 0)
    {
        return m;
    }
    if (m == 0)
    {
        return n;
    }
    return ZAD27(n - 1, m) + ZAD27(n, m - 1) + ZAD27(n - 1, m - 1);
}

unsigned int ZAD28(unsigned int n, unsigned int m)
{
    if (m == 0)
    {
        return n;
    }
    if (n >= m)
    {
        return n - m + ZAD28(n - 1, m) + ZAD28(n, m - 1);
    }
    return n - m + ZAD28(n - 1, m) + ZAD27(n, m - 1);
}

unsigned ZAD29(unsigned int n, unsigned int m)
{
    if (n == m)
        return m;
    if (n > m)
        return NWD(n % m, m);
    else
        return NWD(m % n, n);
}


//DEFINICJE FUNKCJI POWYZEJ
int main()
{
    //ZAD 1
    //Napisz program, który wczytuje ze  standardowego  wejścia  liczbę  całkowitą  n  i  wypisuje  na  standardowe wyjście wartość bezwzględną z n. 
    //Do rozwiązania zadania nie używaj funkcji bibliotecznych za wyjątkiem operacji  wejścia/wyjścia.  W  programie  użyj  samodzielnie  zaimplementowanej  
    //funkcji liczącej wartość bezwzględną.
    /*
    int n;
    printf("Podaj liczbe n: \n");
    scanf_s("%i", &n);
    ZAD1(n);
    */

    //ZAD 2
    //Napisz  program, który  wczytuje  ze  standardowego  wejścia  nieujemną  liczbę  całkowitą  n  i  wypisuje  na standardowym  wyjściu  liczbę  n!.
    //W  programie  użyj  samodzielnie  zaimplementowanej  funkcji  liczącej wartość silni.
    /*
    LiczbaNieujemna();
    SILNIA();
    */

    //ZAD 3
    //Napisz program, który wczytuje ze standardowego wejścia nieujemną liczbę całkowitą n (n > 2) i wypisuje na standardowym wyjściu największą liczbę k taką, 
    //że k dzieli n i k < n. Algorytm wyszukiwania liczby k spełniającej powyższe warunki umieść w oddzielnej funkcji. 
    /*
    printf("Podaj liczbe n wieksza od 2\n");
    int x = _LiczbaNieujemna();
    if (x > 2)
    {
        ZAD3();
    }
    else
    {
        printf("Liczba n jest nie wieksza od 2.");
    }
    */
    //NIE DZIALA 3 DO KOŃCA!!!
    
    //ZAD 4
    //Napisz funkcję, która dostaje jako argument nieujemną liczbę całkowitą n i zwraca jako wartość liczbę 2^n. 
    /*
    LiczbaNieujemna();
    ZAD4(n);
    */

    //ZAD 5
    //Napisz funkcję, która dostaje jako argument liczbę całkowitą n i zwraca jako wartość liczbę 2^n.


    //ZAD6
    //Napisz funkcję, która dostaje jako argumenty nieujemne liczby całkowite n i m, z których co najmniej jedna jest rożna od zera i zwraca jako wartość n^m.
    //ZAD6();

    //ZAD7
    //Napisz funkcję, która dostaje jako argumenty liczby całkowite n i m, z których co najmniej jedna jest rożna od zera i zwraca jako wartość n^m. 
    //ZAD7();

    //ZAD8
    //Napisz funkcję, która dostaje jako argumenty liczbę dodatnią n i zwraca jako wartość ⌊√n⌋. Rozwiąż zadanie nie wykorzystując funkcji bibliotecznych. 
    //ZAD8();
    
    //ZAD9
    //Napisz funkcję, która dostaje jako argumenty liczbę całkowitą m (m > 1) oraz nieujemną liczbę n i zwraca jako wartość ⌊m√n⌋. Rozwiąż zadanie nie wykorzystując funkcji bibliotecznych. 

    //ZAD10
    // Napisz program, który wczytuje ze standardowego wejścia nieujemną liczbę całkowitą n i wypisuje na standardowym wyjściu sumę liczb mniejszych od n i zarazem względnie pierwszych z n.
    // Algorytm wyliczania sumy podziel na dwie funkcje.
    //ZAD10()
    
    //ZAD11
    //Napisz  program,  który  wczytuje  ze  standardowego  wejścia  nieujemną  liczbę  całkowitą  n  i  wypisuje  na standardowym wyjściu następującą sumę _√0_ + _√1_ + . . . + ⌊√n⌋. Algorytm wyliczania sumy podziel na dwie funkcje. 
    //ZAD11();

    //ZAD12
    //Napisz  program,  który  wczytuje  ze  standardowego  wejścia  nieujemne  liczby  całkowitą  n  i  m  (m  >  1),  i wypisuje na standardowym wyjściu następującą sumę _ m√0_ + _ m√1_ + . . . + ⌊m√n⌋. Algorytm wyliczania sumy podziel na dwie funkcje.
    //ZAD12()

    //ZAD13
    //Napisz funkcję, która dostaje jako argument dodatnią liczbę całkowitą n i wypisuje na standardowym wyjściu wszystkie możliwe rozkłady liczby n na sumy dwóch kwadratów dodatnich
    //liczb całkowitych.Rozważ dwa przypadki(jeżeli zajdzie taka potrzeba, możesz w rozwiązaniu używać funkcji pomocniczych):
    // a. gdy „a2 + b2 ” i „b2 + a2” dla a 6 = b traktujemy jako dwa równe rozkłady,
    //b.gdy „a2 + b2” i „b2 + a2” traktujemy jako ten sam rozkład i wypisujemy tylko jedne z nich.
    //ZAD13()
    
    //ZAD14
    // tO SAmo co w 13(?)
    //ZAD14()
    
    //ZAD15
    // //JW
    //ZAD15()
    
    //ZAD16
    // //JW
    //ZAD16()
    
    //ZAD17
    //Napisz funkcję, która zlicza i wypisuje na standardowym wyjściu liczbę swoich wywołań. 
    //ZAD17()
    
    //ZAD 18
    //Napisz funkcję generującą liczby pseudolosowe. Pierwszą wartością funkcji powinna być dowolna liczba z przedziału(0, 1)
    //ZAD18();

    //ZAD19
    //Napisz funkcję, która wczytuje ze standardowego wejścia liczbę całkowitą i zwraca ją jako swoją wartość.
    //Dodatkowo funkcja powinna sumować wszystkie dotychczas wczytane wartości i przy każdym swoim wywołaniu wypisywać na standardowym wyjściu ich aktualną sumę .
    //ZAD19();
    
    //ZAD20
    //Napisz rekurencyjną funkcję, która dla otrzymanej w argumencie nieujemnej całkowitej liczby n zwraca jako wartość n!.
    //ZAD20()

    //ZAD21
    //Napisz  rekurencyjną  funkcję  zwracającą  dla  otrzymanej  w  argumencie  nieujemnej  liczby  całkowitej  n wartośćelementu o indeksie n ciągu zdefiniowanego w następujący sposób:  
    //a0 = 1,  an = 2 ∗ an−1 + 5 dla n > 0. 
    //ZAD21()

    //ZAD22
    //Napisz  rekurencyjną  funkcję  zwracającą  dla  otrzymanej  w  argumencie  nieujemnej  liczby  całkowitej  n wartośćelementu o indeksie n ciągu zdefiniowanego w następujący sposób:  
    //a0 = a1 = 1, an = an−1 + 2 ∗ an−2 + 3 dla n > 1 
    //ZAD22()

    //ZAD23
    //Napisz rekurencyjną funkcję zwracającą dla otrzymanej w argumencie nieujemnej liczby całkowitej n wartość elementu ciągu Fibonacciego o indeksie n.
    //ZAD23()

    //ZAD24
    //Napisz rekurencyjną funkcję zwracającą dla otrzymanej w argumencie nieujemnej liczby całkowitej n wartość elementu o indeksie n ciągu zdefiniowanego w następujący sposób:
    //a0 = a1 = 1, an = a0 + a1 + ... + an−1 dla n > 1
    //ZAD24()

    //ZAD25
    //Napisz funkcję rekurencyjną, która dla otrzymanej w argumencie nieujemnej liczby całkowitej n zwraca wartość elementu o indeksie n ciągu zdefiniowanego w następujący sposób:
    //a0 = a1 = 1, an = an−1 + n dla n parzystych, an = an−1 ∗ n dla n nieparzystych.
    //ZAD25()

    //ZAD26
    // Napisz funkcję rekurencyjną, która dla otrzymanej w argumencie nieujemnej liczby całkowitej n zwraca wartość elementu o indeksie n ciągu zdefiniowanego w następujący sposób:
    //a0 = a1 = a2 = 1 oraz dla k > 2, a3·k = a3·k−1 + a3·k−2, a3·k + 1 = 5 ∗ a3·k + 4, a3·k + 2 = a3·k + 1.
    //ZAD26()

    //ZAD27
    //Napisz funkcję rekurencyjną, która dla otrzymanej w argumentach pary nieujemnych liczb całkowitych n i m zwraca wartość f(n, m) gdzie funkcja f jest zdefiniowana w następujący sposób:
    //f(n, 0) = n, f(0, m) = m, f(n, m) = f(n − 1, m) + f(n, m− 1) + f(n − 1, m − 1) dla n, m > 0.
    //ZAD27()

    //ZAD28
    //Napisz funkcję rekurencyjną, która dla otrzymanej w argumentach pary nieujemnych liczb całkowitych n i 
    //m zwraca wartość f(n, m) gdzie funkcja f jest zdefiniowana w następujący sposób :
    //f(n, 0) = n
    //f(n, m) = f(m, n)
    //f(n, m) = n − m + f(n − 1, m) + f(n, m− 1) dla n ≥ m > 0.
    //ZAD28()
    
    //ZAD29
    //. Napisz rekurencyjną funkcję, która dostaje jako argumenty dwie dodatnie liczby całkowite n i m, i zwraca jako wartość największy wspólny dzielnik tych liczb obliczony algorytmem Euklidesa.
    //ZAD29()
}


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
