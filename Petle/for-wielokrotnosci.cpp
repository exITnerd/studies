//Trzy skrypty o podobnej tematyce -  wielokrotności
#include <iostream>

int main()
{
//Napisz program wczytujący ze standardowego wejścia dwie dodatnie liczby całkowite n i m, wypisujący w kolejnych wierszach na standardowym wyjściu wszystkie dodatnie wielokrotności n mniejsze od m.
	int n, m, wynik, i;
	printf("Podaj 2 liczby calkowite:\n");
	scanf_s("%i", &n);
	scanf_s("%i", &m);
	if (n > 0 && m > 0)
	{
		printf("Wielokrotnosci liczby %i to:\n", n);
		wynik = 0;
		for (i = 1; wynik < m; i++)
		{
			wynik = n * i;
			if (wynik < m) 
			{
				printf("%i\n", wynik);
			}
		}
	}

	//Napisz program wczytujący ze standardowego wejścia dwie dodatnie liczby całkowite n i m, wypisujący na standardowym wyjściu m pierwszych wielokrotności liczby n
	int n, m, i, wielokrotnosci;
	printf("Podaj liczbe, ktorej wielokrotnosci chcesz wypisac:\n");
	scanf_s("%i", &n);
	printf("Podaj ilosc wielokrotnosci podanej wczesniej liczby:\n");
	scanf_s("%i", &m);
	if (n > 0 && m > 0)
	{
		printf("%i pierwszych wielokrotnosci liczby %i to:\n", m, n);
		for (i = 1; i <= m; i++)
		{
			wielokrotnosci = n * i;
			printf("%i\n", wielokrotnosci);
		}
	}

	//Napisz program wczytujący ze standardowego wejścia trzy dodatnie liczby całkowite n, m i k, wypisujący w kolejnych wierszach wszystkie wielokrotności n większe od m i mniejsze od k. 
	int n, m, k, i, wielokrotnosci;
	printf("Podaj liczbe n:\n");
	scanf_s("%i", &n);
	printf("Podaj liczbe m:\n");
	scanf_s("%i", &m);
	printf("Podaj liczbe k:\n");
	scanf_s("%i", &k);
	printf("------------------\n");

	if (n > 0 && m > 0 && k > 0)
	{
		i = 1;
		while (true)
		{
			wielokrotnosci = n * i;
			if (wielokrotnosci > (k-1))
			{
				break;
			}
			if (wielokrotnosci < (m+1))
			{
				i++;
				continue;
			}
			printf("%i \n", wielokrotnosci);
			i++;
		}
	}
	else
	{
		printf("Podano liczby niedodatnie");
	}
}
