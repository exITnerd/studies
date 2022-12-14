//Napisz  program,  który  wczytuje  ze  standardowego  wejścia  trzy  liczby  całkowite  i  wypisuje  na standardowym wyjściu ich średnią arytmetyczną.
int a;
int b;
int c;
float srednia;
printf("Podaj trzy liczby całkowite, aby obliczyć ich średnią\n");
scanf_s("%i", &a);
scanf_s("%i", &b);
scanf_s("%i", &c);
srednia = (float)(a + b + c) / 3;
printf("%f\n", srednia);
