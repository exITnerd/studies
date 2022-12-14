//Napisz  program,  który  wczytuje  ze  standardowego  wejścia  nieujemną  liczbę  całkowitą  n  i  wypisuje  na standardowym wyjściu liczbę n!.
#include <iostream>

int main()
{
  int wielokrotnosci, n, i;
	n = 0;
	wielokrotnosci = 1;
	printf("Podaj n: \n");
	scanf_s("%i", &n);
	if (n >= 0)
	{
		for (int i = 1; i <= n; i++)
		{
			wielokrotnosci *= i;
		}
		printf("Silnia liczby n: %i \n", wielokrotnosci);
	}
	else
	{
		printf("Podaj liczbe nieujemna!");
	}
}
