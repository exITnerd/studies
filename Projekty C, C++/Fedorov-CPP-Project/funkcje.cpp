#include "sprzet.h"

random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<int> distribution(1, 8);

// przeciazenie operatora wejscia
istream& operator>>(istream& wejscie, Zestaw& z) {
    int Typ;
    cout << "Podaj typ (0 w celu odczytania kamer, 1 w celu odczytania rejestratorow)" << endl;
    cin >> Typ;

    if (Typ == 0)
    {
        delete[] z.kamery;
        wejscie >> z.iloscKamer;
        Zestaw::Kamera* nowa_kamera = new Zestaw::Kamera[z.iloscKamer];
        for (int i = 0; i < z.iloscKamer; i++) {
            string nazwa, kolor, stan;
            int rozdzielczosc;
            wejscie >> nazwa;
            wejscie >> kolor;
            wejscie >> rozdzielczosc;
            wejscie >> stan;
            nowa_kamera[i] = Zestaw::Kamera(nazwa, kolor, stan, rozdzielczosc);
        }
        z.kamery = nowa_kamera;
    }
    else {
        delete[] z.rejestratory;
        wejscie >> z.iloscRejestratorow;
        Zestaw::Rejestrator** nowy_rejestrator = new Zestaw::Rejestrator * [z.iloscRejestratorow];
        for (int i = 0; i < z.iloscRejestratorow; i++) {
            string nazwa, kolor, stan;
            int rozdzielczosc;
            wejscie >> nazwa;
            wejscie >> kolor;
            wejscie >> rozdzielczosc;
            wejscie >> stan;
            nowy_rejestrator[i] = new Zestaw::Rejestrator(nazwa, kolor, stan, rozdzielczosc);
        }
        z.rejestratory = nowy_rejestrator;
    }
    return wejscie;
}

// przeciazenie operatora wyjscia (konsola)
ostream& operator<<(ostream& wyjscie, const Zestaw& z) {
    wyjscie << "Informacje o stanie magazynowym" << endl;
    wyjscie << "Nazwa:" << z.nazwa << endl;
    wyjscie << "Nazwa: " << "Kolor: " << "Stan: " << "Ilosc kamer: " << z.iloscKamer << " Ilosc rejestratorow: " << z.iloscRejestratorow << endl;
    for (int i = 0; i < z.iloscRejestratorow; i++) {
        wyjscie << z.rejestratory[i]->get_nazwa() << " " << z.rejestratory[i]->get_kolor() << " " << z.rejestratory[i]->get_stan() << endl;
    }
    for (int i = 0; i < z.iloscKamer; i++) {
        wyjscie << z.kamery[i].get_nazwa() << " " << z.kamery[i].get_kolor() << " " << z.kamery[i].get_stan() << endl;
    }
    return wyjscie;
}

// przeciazenie operatora przypisania
Zestaw& Zestaw::operator=(const Zestaw& z) {
    if (this != &z) { // sprawdzenie, czy nie probujemy przypisac obiektu do samego siebie
        // przypisanie wartooci pol z innego obiektu
        nazwa = z.nazwa;
        stan = z.stan;
        kolor = z.kolor;
        rozdzielczosc = z.rozdzielczosc;
        iloscKamer = z.iloscKamer;
        iloscRejestratorow = z.iloscRejestratorow;

        // usuniecie istniejacych kamer i rejestratorow
        for (int i = 0; i < iloscRejestratorow; i++) {
            delete rejestratory[i];
        }
        delete[] rejestratory;
        delete[] kamery;

        // alokacja pamieci dla nowych kamer i rejestratorow
        rejestratory = new Rejestrator * [iloscRejestratorow];
        for (int i = 0; i < iloscRejestratorow; i++) {
            rejestratory[i] = new Rejestrator(*(z.rejestratory[i]));
        }
        kamery = new Kamera[iloscKamer];
        for (int i = 0; i < iloscKamer; i++) {
            kamery[i] = z.kamery[i];
        }
    }
    return *this; // zwracenie referencji do obiektu
}

void Zestaw::tworzenie()
{
    iloscKamer = distribution(generator);
    kamery = new Kamera[iloscKamer];
    inicjalizacja();
}

void Zestaw::tworzenie(int R)
{
    iloscRejestratorow = distribution(generator);
    rejestratory = new Rejestrator * [iloscRejestratorow];
    for (size_t ind = 0; ind < iloscRejestratorow; ind++)
        //for (int ind = 0; ind < iloscRejestratorow; ind++)
        rejestratory[ind] = new Rejestrator();
    inicjalizacja(1);
}

//Inicjalizacja obiektu Kamera
void Zestaw::inicjalizacja()
{
    string nazwa_kamera[] = { "Xiaomi", "Imou", "Alkon", "Hikvision", "Dahua", "Eufy" };
    string kolor_kamera[] = { "Czarny", "Szary", "Bialy" };
    string stan_kamera[] = { "Nowy", "Uzywany" };

    std::uniform_int_distribution<int> nazwa_kamera_dist(0, 5);
    std::uniform_int_distribution<int> kolor_kamera_dist(0, 2);
    std::uniform_int_distribution<int> rozdzielczosc_dist(1, 3);
    std::uniform_int_distribution<int> stan_kamera_dist(0, 1);

    for (int i = 0; i < iloscKamer; i++)
    {
        kamery[i].set_nazwa(nazwa_kamera[nazwa_kamera_dist(generator)]);
        kamery[i].set_kolor(kolor_kamera[kolor_kamera_dist(generator)]);
        kamery[i].set_rozdzielczosc(rozdzielczosc_dist(generator));
        kamery[i].set_stan(stan_kamera[stan_kamera_dist(generator)]);
    }
}

//Inicjalizacja obiektu Rejestrator
void Zestaw::inicjalizacja(int R)
{
    string nazwa_rejestrator[] = { "HP", "Imou", "Alkon", "Hikvision", "Dahua", "Eufy" };
    string kolor_rejestrator[] = { "Czarny", "Szary", "Bialy" };
    string stan_rejestrator[] = { "Nowy", "Uzywany" };

    std::uniform_int_distribution<int> nazwa_rejestrator_dist(0, 5);
    std::uniform_int_distribution<int> kolor_rejestrator_dist(0, 2);
    std::uniform_int_distribution<int> rozdzielczosc_dist(1, 3);
    std::uniform_int_distribution<int> stan_rejestrator_dist(0, 1);

    for (int i = 0; i < iloscRejestratorow; i++)
    {
        rejestratory[i]->set_nazwa(nazwa_rejestrator[nazwa_rejestrator_dist(generator)]);
        rejestratory[i]->set_kolor(kolor_rejestrator[kolor_rejestrator_dist(generator)]);
        rejestratory[i]->set_rozdzielczosc(rozdzielczosc_dist(generator));
        rejestratory[i]->set_stan(stan_rejestrator[stan_rejestrator_dist(generator)]);
    }
}

//Wyswietlanie obiektu Kamera
void Zestaw::wyswietlanie()
{
    for (int i = 0; i < iloscKamer; i++)
    {
        cout << "Nr kamery: " << i + 1 << endl;
        cout << "Nazwa kamery: " << kamery[i].get_nazwa() << endl;
        cout << "Kolor kamery: " << kamery[i].get_kolor() << endl;
        cout << "Rozdzielczosc kamery: " << kamery[i].get_rozdzielczosc() << "MPx" << endl;
        cout << "Stan kamery: " << kamery[i].get_stan() << endl << endl;
    }
}

//Wyswietlanie obiektu Rejestrator
void Zestaw::wyswietlanie(int R)
{
    for (int i = 0; i < iloscRejestratorow; i++)
    {
        cout << "Nr rejestratora: " << i + 1 << endl;
        cout << "Nazwa rejestratora: " << rejestratory[i]->get_nazwa() << endl;
        cout << "Kolor rejestratora: " << rejestratory[i]->get_kolor() << endl;
        cout << "Rozdzielczosc rejestratora: " << rejestratory[i]->get_rozdzielczosc() << "MPx" << endl;
        cout << "Stan rejestratora: " << rejestratory[i]->get_stan() << endl
            << endl;
    }
}

//Usuwanie obiektu Kamera
void Zestaw::usuwanie()
{
    // odpowiedz w przypadku braku kamer
    if (iloscKamer == 0)
    {
        cout << "Brak kamer do usuniecia" << endl;
        return;
    }

    // wylosowanie kamery do usuni�cia
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(0, iloscKamer - 1);
    int kamera_do_usuniecia = distribution(generator);

    // tworzenie nowej tablicy kamer bez wylosowanej kamery
    Kamera* nowy_kamera = new Kamera[iloscKamer - 1];
    for (int i = 0, j = 0; j < iloscKamer - 1; i++)
    {
        if (i != kamera_do_usuniecia)
        {
            nowy_kamera[j] = kamery[i];
            j++;
        }
    }

    // zwolnienie pamieci poprzedniej tablicy i przypisanie do niej nowej tablicy
    delete[] kamery;
    kamery = nowy_kamera;
    iloscKamer--;

    cout << "Usunieto kamere o numerze: " << kamera_do_usuniecia + 1 << endl;
}

//Usuwanie obiektu Rejestrator
void Zestaw::usuwanie(int R)
{
    // odpowiedz w przypadku braku rejestratorow
    if (iloscRejestratorow == 0)
    {
        cout << "Brak rejestratorow do usuniecia" << endl;
        return;
    }

    // wylosowanie rejestratora do usuni�cia
    // int rejestrator_do_usuniecia = rand() % rozmiar;
    std::random_device rd;
    std::default_random_engine generator(rd());

    std::uniform_int_distribution<int> distribution(0, iloscRejestratorow - 1);
    int rejestrator_do_usuniecia = distribution(generator);

    // usuniecie wylosowanego rejestratora
    delete rejestratory[rejestrator_do_usuniecia];

    // przesuniecie pozostalych elementow w tablicy
    for (int i = rejestrator_do_usuniecia; i < iloscRejestratorow - 1; i++)
    {
        rejestratory[i] = rejestratory[i + 1];
    }
    iloscRejestratorow--;

    // Realokacja pamieci
    Rejestrator** nowy_rejestrator = new Rejestrator * [iloscRejestratorow];
    for (int i = 0; i < iloscRejestratorow; i++)
    {
        nowy_rejestrator[i] = rejestratory[i];
    }
    delete[] rejestratory;
    rejestratory = nowy_rejestrator;

    cout << "Usunieto rejestrator o numerze: " << rejestrator_do_usuniecia + 1 << endl;
}

//   Edytowanie obiektu Kamera
void Zestaw::edytowanie()
{

    int nr_kamery_do_edycji, wybor;
    // wybor kamery do edytowania
    do
    {
        cout << "Podaj numer kamery, ktora chcesz edytowac (1-" << iloscKamer << "):";
        cin >> nr_kamery_do_edycji;
        system("cls");
        if (nr_kamery_do_edycji <= 0 || nr_kamery_do_edycji > iloscKamer)
        {
            cout << "Nieprawidlowy numer kamery" << endl;
        }

    } while (nr_kamery_do_edycji <= 0 || nr_kamery_do_edycji > iloscKamer);
    nr_kamery_do_edycji--;

    string wybory = "1. Nazwa\n2. Kolor\n3. Predkosc\n4. Stan\n5. Cofniecie sie do poprzedniego menu";
    do
    {
        // wypisanie danych kamery do edycji
        cout << "Wybrana kamera: " << kamery[nr_kamery_do_edycji].get_nazwa() << endl;
        cout << "Jej kolor: " << kamery[nr_kamery_do_edycji].get_kolor() << endl;
        cout << "Jej rozdzielczosc: " << kamery[nr_kamery_do_edycji].get_rozdzielczosc() << "Mpx" << endl;
        cout << "Jej stan: " << kamery[nr_kamery_do_edycji].get_stan() << endl
            << endl;

        // wybor rzeczy do edycji
        cout << "Wybierz co chcesz edytowac:" << endl;
        cout << wybory << endl;
        cin >> wybor;
        system("cls");

        // ponowne wypisanie danych kamery do edycji
        cout << "Wybrana kamera: " << kamery[nr_kamery_do_edycji].get_nazwa() << endl;
        cout << "Jej kolor: " << kamery[nr_kamery_do_edycji].get_kolor() << endl;
        cout << "Jej rozdzielczosc: " << kamery[nr_kamery_do_edycji].get_rozdzielczosc() << "Mpx" << endl;
        cout << "Jej stan: " << kamery[nr_kamery_do_edycji].get_stan() << endl
            << endl;

        switch (wybor)
        {
        case 1:
        {
            string nowa_nazwa;
            cout << "Nowa nazwa: ";
            cin >> nowa_nazwa;
            kamery[nr_kamery_do_edycji].set_nazwa(nowa_nazwa);
            break;
        }
        case 2:
        {
            string nowy_kolor;
            cout << "Nowy kolor: ";
            cin >> nowy_kolor;
            kamery[nr_kamery_do_edycji].set_kolor(nowy_kolor);
            break;
        }
        case 3:
        {
            int nowa_rozdzielczosc;
            cout << "Nowa rozdzielczosc: ";
            cin >> nowa_rozdzielczosc;
            kamery[nr_kamery_do_edycji].set_rozdzielczosc(nowa_rozdzielczosc);
            break;
        }
        case 4:
        {
            string nowy_stan;
            cout << "Nowy stan (Nowy lub Uzywany): ";
            cin >> nowy_stan;
            kamery[nr_kamery_do_edycji].set_stan(nowy_stan);
            break;
        }
        case 5:
            break;
        default:
            break;
        }
        system("cls");
    } while (wybor != 5);
}

//Edytowanie obiektu Rejestrator
void Zestaw::edytowanie(int R)
{
    int nr_rejestratora_do_edycji, wybor;
    // wybor rejestratora do edytowania
    do
    {
        cout << "Podaj numer rejestratora, ktory chcesz edytowac (1-" << iloscRejestratorow << "):";
        cin >> nr_rejestratora_do_edycji;
        system("cls");
        if (nr_rejestratora_do_edycji <= 0 || nr_rejestratora_do_edycji > iloscRejestratorow)
        {
            cout << "Nieprawidlowy numer rejestratora" << endl;
        }

    } while (nr_rejestratora_do_edycji <= 0 || nr_rejestratora_do_edycji > iloscRejestratorow);
    nr_rejestratora_do_edycji--;

    string wybory = "1. Nazwa\n2. Kolor\n3. Predkosc\n4. Stan\n5. Cofniecie sie do poprzedniego menu";
    do
    {
        // wypisanie danych rejestratora do edycji
        cout << "Wybrany rejestrator: " << rejestratory[nr_rejestratora_do_edycji]->get_nazwa() << endl;
        cout << "Jego kolor: " << rejestratory[nr_rejestratora_do_edycji]->get_kolor() << endl;
        cout << "Jego rozdzielczosc: " << rejestratory[nr_rejestratora_do_edycji]->get_rozdzielczosc() << "Ma" << endl;
        cout << "Jego stan: " << rejestratory[nr_rejestratora_do_edycji]->get_stan() << endl
            << endl;

        // wybor rzeczy do edycji
        cout << "Wybierz co chcesz edytowac:" << endl;
        cout << wybory << endl;
        cin >> wybor;
        system("cls");

        // ponowne wypisanie danych rejestratora do edycji
        cout << "Wybrany rejestrator: " << rejestratory[nr_rejestratora_do_edycji]->get_nazwa() << endl;
        cout << "Jego kolor: " << rejestratory[nr_rejestratora_do_edycji]->get_kolor() << endl;
        cout << "Jego rozdzielczosc: " << rejestratory[nr_rejestratora_do_edycji]->get_rozdzielczosc() << "Ma" << endl;
        cout << "Jego stan: " << rejestratory[nr_rejestratora_do_edycji]->get_stan() << endl
            << endl;
        switch (wybor)
        {
        case 1:
        {
            string nowa_nazwa;
            cout << "Nowa nazwa: ";
            cin >> nowa_nazwa;
            rejestratory[nr_rejestratora_do_edycji]->set_nazwa(nowa_nazwa);
            break;
        }
        case 2:
        {
            string nowy_kolor;
            cout << "Nowy kolor: ";
            cin >> nowy_kolor;
            rejestratory[nr_rejestratora_do_edycji]->set_kolor(nowy_kolor);
            break;
        }
        case 3:
        {
            int nowa_rozdzielczosc;
            cout << "Nowa rozdzielczosc: ";
            cin >> nowa_rozdzielczosc;
            rejestratory[nr_rejestratora_do_edycji]->set_rozdzielczosc(nowa_rozdzielczosc);
            break;
        }
        case 4:
        {
            string nowy_stan;
            cout << "Nowy stan (Nowy lub Uzywany): ";
            cin >> nowy_stan;
            rejestratory[nr_rejestratora_do_edycji]->set_stan(nowy_stan);
            break;
        }
        case 5:
            break;

        default:
            break;
        }
        system("cls");
    } while (wybor != 5);
}

//Zestawienie obiektow Kamera
void Zestaw::zestawienie() {
    string kolor;
    int rozdzielczosc;
    bool dowolnyKolor = false;
    cout << "Podaj kolor kamery (Czarny, Szary, Bialy lub Dowolny): ";
    cin >> kolor;
    if (kolor == "Dowolny") {
        dowolnyKolor = true;
    }
    cout << "Podaj minimalna rozdzielczosc kamery (wartosc liczbowa w zakresie 1-3): ";
    cin >> rozdzielczosc;

    // wyszukanie i wypisanie pasuj�cych kamer
    bool znalezionoKamery = false;
    cout << "Znalezione kamery:" << endl;
    int liczbaSpe�niaj�cychKamery = 0;
    for (int i = 0; i < iloscKamer; i++) {
        if ((dowolnyKolor || kamery[i].get_kolor() == kolor) && kamery[i].get_rozdzielczosc() >= rozdzielczosc) {
            cout << "Nazwa kamery: " << kamery[i].get_nazwa() << endl;
            cout << "Kolor kamery: " << kamery[i].get_kolor() << endl;
            cout << "Rozdzielczosc kamery: " << kamery[i].get_rozdzielczosc() << endl;
            cout << "Stan kamery: " << kamery[i].get_stan() << endl;
            cout << endl;
            znalezionoKamery = true;
            liczbaSpe�niaj�cychKamery++;
        }
    }

    if (!znalezionoKamery) {
        cout << "Brak kamer o wymaganej specyfikacji" << endl;
    }

    // zapisanie wyniku do pliku
    ofstream plik("zestawienieKamer.txt");
    if (plik.is_open()) {
        plik << liczbaSpe�niaj�cychKamery << endl;

        for (int i = 0; i < iloscKamer; i++) {
            if ((dowolnyKolor || kamery[i].get_kolor() == kolor) && kamery[i].get_rozdzielczosc() >= rozdzielczosc) {
                plik << kamery[i].get_nazwa() << endl;
                plik << kamery[i].get_kolor() << endl;
                plik << kamery[i].get_rozdzielczosc() << endl;
                plik << kamery[i].get_stan() << endl;
            }
        }

        plik.close();
        cout << "Wynik zapisany do pliku zestawienieKamer.txt" << endl;
    }
    else {
        cout << "Nie udaLo sie otworzyc pliku zestawienieKamer.txt" << endl;
    }
}

//Zestawienie obiektow Rejestrator
void Zestaw::zestawienie(int R) {
    string kolor;
    int rozdzielczosc;
    bool dowolnyKolor = false;
    cout << "Podaj kolor rejestratora (Czarny, Szary, Bialy lub Dowolny): ";
    cin >> kolor;
    if (kolor == "Dowolny") {
        dowolnyKolor = true;
    }
    cout << "Podaj minimalna rozdzielczosc obslugiwana przez rejestrator (wartosc liczbowa w zakresie 1-3): ";
    cin >> rozdzielczosc;

    // wyszukanie i wypisanie pasuj�cych rejestratorow
    bool znalezionoRejestratory = false;
    cout << "Znalezione rejestratory:" << endl;
    int liczbaSpe�niaj�cychRejestratory = 0;
    for (int i = 0; i < iloscRejestratorow; i++) {
        if ((dowolnyKolor || rejestratory[i]->get_kolor() == kolor) && rejestratory[i]->get_rozdzielczosc() >= rozdzielczosc) {
            cout << "Nazwa rejestratora: " << rejestratory[i]->get_nazwa() << endl;
            cout << "Kolor rejestratora: " << rejestratory[i]->get_kolor() << endl;
            cout << "Rozdzielczosc rejestratora: " << rejestratory[i]->get_rozdzielczosc() << endl;
            cout << "Stan rejestratora: " << rejestratory[i]->get_stan() << endl;
            cout << endl;
            znalezionoRejestratory = true;
            liczbaSpe�niaj�cychRejestratory++;
        }
    }

    if (!znalezionoRejestratory) {
        cout << "Brak rejestratorow o wymaganej specyfikacji" << endl;
    }

    // zapisanie wyniku do pliku
    ofstream plik("zestawienieRejestratorow.txt");
    if (plik.is_open()) {
        plik << liczbaSpe�niaj�cychRejestratory << endl;

        for (int i = 0; i < iloscRejestratorow; i++) {
            if ((dowolnyKolor || rejestratory[i]->get_kolor() == kolor) && rejestratory[i]->get_rozdzielczosc() >= rozdzielczosc) {
                plik << rejestratory[i]->get_nazwa() << endl;
                plik << rejestratory[i]->get_kolor() << endl;
                plik << rejestratory[i]->get_rozdzielczosc() << endl;
                plik << rejestratory[i]->get_stan() << endl;
            }
        }

        plik.close();
        cout << "Wynik zapisany do pliku zestawienieRejestratorow.txt" << endl;
    }
    else {
        cout << "Nie udalo sie otworzyc pliku zestawienieRejestratorow.txt" << endl;
    }
}

//Sortowanie obiektow Kamera
void Zestaw::sortowanie() {
    int wybor;
    cout << "Wedlug czego chcesz posortowac kamery? (1 - wedlug rozdzielczosci, 2 - wedlug nazwy): ";
    cin >> wybor;
    while (wybor != 1 && wybor != 2) {
        cout << "Nieprawidlowy wybor. Sprobuj jeszcze raz." << endl;
        cout << "Wedlug czego chcesz posortowac kamery? (1 - wedlug rozdzielczosci, 2 - wedlug nazwy): ";
        cin >> wybor;
    }

    // sortowanie kamery
    if (wybor == 1) {
        for (int i = 0; i < iloscKamer - 1; i++) {
            for (int j = 0; j < iloscKamer - i - 1; j++) {
                if (kamery[j].get_rozdzielczosc() > kamery[j + 1].get_rozdzielczosc()) {
                    Kamera temp = kamery[j];
                    kamery[j] = kamery[j + 1];
                    kamery[j + 1] = temp;
                }
            }
        }
    }
    else if (wybor == 2) {
        for (int i = 0; i < iloscKamer - 1; i++) {
            for (int j = 0; j < iloscKamer - i - 1; j++) {
                if (kamery[j].get_nazwa() > kamery[j + 1].get_nazwa()) {
                    Kamera temp = kamery[j];
                    kamery[j] = kamery[j + 1];
                    kamery[j + 1] = temp;
                }
            }
        }
    }

    // wypisanie posortowanych kamer
    cout << "Posortowane kamery:" << endl;
    for (int i = 0; i < iloscKamer; i++) {
        cout << "Nazwa kamery: " << kamery[i].get_nazwa() << endl;
        cout << "Kolor kamery: " << kamery[i].get_kolor() << endl;
        cout << "Rozdzielczosc kamery: " << kamery[i].get_rozdzielczosc() << endl;
        cout << "Stan kamery: " << kamery[i].get_stan() << endl;
        cout << endl;
    }
}

//Sortowanie obiektow Rejestrator
void Zestaw::sortowanie(int R) {
    int wybor;
    cout << "Wedlug czego chcesz posortowac rejestratory? (1 - wedlug rozdzielczosci, 2 - wedlug nazwy): ";
    cin >> wybor;
    while (wybor != 1 && wybor != 2) {
        cout << "Nieprawidlowy wybor. Sprobuj jeszcze raz." << endl;
        cout << "Wedlug czego chcesz posortowac rejestrator? (1 - wedlug rozdzielczosci, 2 - wedlug nazwy): ";
        cin >> wybor;
    }

    // sortowanie rejestratory
    if (wybor == 1) {
        for (int i = 0; i < iloscRejestratorow - 1; i++) {
            for (int j = 0; j < iloscRejestratorow - i - 1; j++) {
                if (rejestratory[j]->get_rozdzielczosc() > rejestratory[j + 1]->get_rozdzielczosc()) {
                    Rejestrator* temp = rejestratory[j];
                    rejestratory[j] = rejestratory[j + 1];
                    rejestratory[j + 1] = temp;
                }
            }
        }
    }
    else if (wybor == 2) {
        for (int i = 0; i < iloscRejestratorow - 1; i++) {
            for (int j = 0; j < iloscRejestratorow - i - 1; j++) {
                if (rejestratory[j]->get_nazwa() > rejestratory[j + 1]->get_nazwa()) {
                    Rejestrator* temp = rejestratory[j];
                    rejestratory[j] = rejestratory[j + 1];
                    rejestratory[j + 1] = temp;
                }
            }
        }
    }

    // wypisanie posortowanych kamer
    cout << "Posortowane rejestrator:" << endl;
    for (int i = 0; i < iloscRejestratorow; i++) {
        cout << "Nazwa rejestratora: " << rejestratory[i]->get_nazwa() << endl;
        cout << "Kolor rejestratora: " << rejestratory[i]->get_kolor() << endl;
        cout << "Rozdzielczosc rejestratora: " << rejestratory[i]->get_rozdzielczosc() << endl;
        cout << "Stan rejestratora: " << rejestratory[i]->get_stan() << endl;
        cout << endl;
    }
}

//Dodawanie w jednej linii Kamery
void Zestaw::dodanieGetline()
{
    Kamera* stworz_kamera = new Kamera[iloscKamer + 1];
    for (int i = 0; i < iloscKamer; i++)
    {
        stworz_kamera[i] = kamery[i];
    }
    cout << "Podaj dane kamery w formacie: nazwa,kolor,stan,rozdzielczosc\n";

    // zmienna do przechowywania wczytanej linii
    string linia;
    // usuniecie znaku \n z bufora
    cin.ignore();
    // wczytanie linii ze standardowego wejscia
    getline(cin, linia, '\n');
    // podzielenie linii za pomoca funkcji find i substr
    size_t pozycja = linia.find(',');
    stworz_kamera[iloscKamer].set_nazwa(linia.substr(0, pozycja));
    linia.erase(0, pozycja + 1);
    pozycja = linia.find(',');
    stworz_kamera[iloscKamer].set_kolor(linia.substr(0, pozycja));
    linia.erase(0, pozycja + 1);
    pozycja = linia.find(',');
    stworz_kamera[iloscKamer].set_stan(linia.substr(0, pozycja));
    linia.erase(0, pozycja + 1);
    stworz_kamera[iloscKamer].set_rozdzielczosc(stoi(linia));
    iloscKamer++;
    system("cls");
    cout << "Dodano kamere nr.: " << iloscKamer << endl;

    delete[] kamery;
    kamery = stworz_kamera;
}

//Dodawanie w jednej linii Rejestratora
void Zestaw::dodanieGetline(int R)
{
    Rejestrator** stworz_rejestrator = new Rejestrator * [iloscRejestratorow + 1];
    for (int i = 0; i < iloscRejestratorow; i++)
    {
        stworz_rejestrator[i] = rejestratory[i];
    }
    stworz_rejestrator[iloscRejestratorow] = new Rejestrator();
    cout << "Podaj dane rejestratora w formacie: nazwa,kolor,stan,rozdzielczosc\n";

    // zmienna do przechowywania wczytanej linii
    string linia;
    // usuni�cie znaku \n z bufora
    cin.ignore();
    // wczytanie linii ze standardowego wejscia
    getline(cin, linia, '\n');
    // podzielenie linii za pomoc� funkcji find i substr
    // znalezienie pozycji pierwszego przecinka
    size_t pozycja = linia.find(',');
    // wyci�cie imienia menedzera od poczatku do pierwszego przecinka
    stworz_rejestrator[iloscRejestratorow]->set_nazwa(linia.substr(0, pozycja));
    // usuni�cie imienia menedzera z linii
    linia.erase(0, pozycja + 1);
    pozycja = linia.find(',');
    stworz_rejestrator[iloscRejestratorow]->set_kolor(linia.substr(0, pozycja));
    linia.erase(0, pozycja + 1);
    pozycja = linia.find(',');
    stworz_rejestrator[iloscRejestratorow]->set_stan(linia.substr(0, pozycja));
    linia.erase(0, pozycja + 1);
    stworz_rejestrator[iloscRejestratorow]->set_rozdzielczosc(stoi(linia)); // stosujemy funkcje stoi do konwersji stringa na int
    iloscRejestratorow++;
    system("cls");
    cout << "Dodano rejestrator nr.: " << iloscRejestratorow << endl;

    delete[] rejestratory;
    rejestratory = stworz_rejestrator;
}

Zestaw::Zestaw(const Zestaw& zestaw) {
    nazwa = zestaw.nazwa;
    kolor = zestaw.kolor;
    stan = zestaw.stan;
    rozdzielczosc = zestaw.rozdzielczosc;
    iloscKamer = zestaw.iloscKamer;
    kamery = new Kamera[zestaw.iloscKamer];

    for (size_t i = 0; i < zestaw.iloscKamer; ++i) {
        kamery[i] = zestaw.kamery[i];
    }

    iloscRejestratorow = zestaw.iloscRejestratorow;
    rejestratory = new Rejestrator * [zestaw.iloscRejestratorow];

    for (size_t i = 0; i < zestaw.iloscRejestratorow; ++i) {
        rejestratory[i] = new Rejestrator(*zestaw.rejestratory[i]);
    }
}