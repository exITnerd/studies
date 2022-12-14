//Napisz  program,  który  wczytuje  ze  standardowego  wejścia  liczbę  wymierną  i  wypisuje  ją  na standardowym wyjściu w notacji wykładniczej (czyli takiej, w której 0.2 to 2.0e-1).
float ntwy;
printf("Podaj dowolną liczbę wymierną\n");
scanf_s("%f", &ntwy);
printf("Ta liczba w notacji wykładniczej to: %E\n", ntwy);
