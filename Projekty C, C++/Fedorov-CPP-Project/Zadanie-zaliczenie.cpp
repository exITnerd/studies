#include "sprzet.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void wyswietl_biuro(Miejsce*& miejsce);
void wyswietl_magazyn(Miejsce*& miejsce);

int main(int argc, char const* argv[])
{
    Miejsce* miejsce;

    string menu1 = "1. Przejscie do kamer\n2. Przejscie do rejestratorow\n3. Koniec programu";
    string menu2 = "1. Wyswietlenie kamer\n2. Usuniecie losowo wybranej kamery\n3. (Polimorfizm)\n4. Edytowanie danych wybranej kamery\n5. Sortowanie danych\n6. Zestawienie wybranych kamer\n7. Dodawanie kamery w jednej linii\n8. Odczyt danych z pliku\n9. Wypisywanie danych\n10. Wyswietlanie i zamieniane nazwy oraz koloru urzadzen\n11. Cofniecie sie do glownego menu";
    string menu3 = "1. Wyswietlenie rejestratorow\n2. Usuniecie losowo wybranego rejestratora\n3. (Polimorfizm)\n4. Edytowanie danych wybranego rejestratora\n5. Sortowanie danych\n6. Zestawienie wybranych rejestratorow\n7. Dodawanie rejestratora w jednej linii\n8. Odczyt danych z pliku\n9. Wypisywanie danych\n10. Wyswietlanie i zamieniane nazwy oraz koloru urzadzen\n11. Cofniecie sie do glownego menu";

    int wybor_glowny, wybor_kamery, wybor_rejestrator;

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(1, 8);

    Zestaw zestaw("Monitoring", "Dowolny", "Nowy", 0, distribution(generator), distribution(generator));

    zestaw.tworzenie();
    zestaw.tworzenie(1);

    system("cls");
    do
    {
        cout << "-----------------------------" << endl;
        cout << menu1 << endl;
        cout << "-----------------------------" << endl;
        cin >> wybor_glowny;
        system("cls");

        switch (wybor_glowny) // kamery
        {
        case 1:
            do
            {
                cout << "-------------------------------------------" << endl;
                cout << menu2 << endl;
                cout << "-------------------------------------------" << endl;
                cin >> wybor_kamery;
                system("cls");

                switch (wybor_kamery)
                {
                case 1:
                    system("cls");
                    zestaw.wyswietlanie();
                    break;
                case 2:
                    system("cls");
                    zestaw.usuwanie();
                    break;
                case 3:
                    system("cls");
                    wyswietl_magazyn(miejsce);
                    wyswietl_biuro(miejsce);
                    break;
                case 4:
                    system("cls");
                    zestaw.edytowanie();
                    break;
                case 5:
                    system("cls");
                    zestaw.sortowanie();
                    break;
                case 6:
                    system("cls");
                    zestaw.zestawienie();
                    break;
                case 7:
                    system("cls");
                    zestaw.dodanieGetline();
                    break;
                case 8:
                {
                    system("cls");
                    ifstream plikOd("zestawienieKamer.txt");
                    if (plikOd.is_open()) {
                        cout << "Czytanie pliku...\n";
                        plikOd >> zestaw;
                        plikOd.close();
                    }
                    break;
                }
                case 9:
                    system("cls");
                    cout << zestaw; // wykorzystanie przeciążonego operatora wyjścia
                    break;
                case 10:
                    system("cls");
                    // wykorzystanie przeciążonego operatora indeksowania
                    cout << zestaw[0].get_nazwa() << " " << zestaw[0].get_kolor() << endl;
                    cout << zestaw(0).get_nazwa() << " " << zestaw(0).get_kolor() << endl;
                    zestaw[0].set_nazwa("NowaNazwa");
                    zestaw(0).set_kolor("NowyKolor");
                    cout << zestaw[0].get_nazwa() << " " << zestaw[0].get_kolor() << endl;
                    cout << zestaw(0).get_nazwa() << " " << zestaw(0).get_kolor() << endl;
                    break;
                case 11:
                    break;
                default:
                    system("cls");
                    cout << "Bledny wybor, powtorz" << endl;
                    break;
                }
            } while (wybor_kamery != 11);


            break;

        case 2: // rejestratory
            do
            {
                cout << "-----------------------------" << endl;
                cout << menu3 << endl;
                cout << "-----------------------------" << endl;
                cin >> wybor_rejestrator;

                switch (wybor_rejestrator)
                {
                case 1:
                    system("cls");
                    zestaw.wyswietlanie(1);
                    break;
                case 2:
                    system("cls");
                    zestaw.usuwanie(1);
                    break;
                case 3:
                    system("cls");
                    wyswietl_magazyn(miejsce);
                    wyswietl_biuro(miejsce);
                    break;
                case 4:
                    system("cls");
                    zestaw.edytowanie(1);
                    break;
                case 5:
                    system("cls");
                    zestaw.sortowanie(1);
                    break;
                case 6:
                    system("cls");
                    zestaw.zestawienie(1);
                    break;
                case 7:
                    system("cls");
                    zestaw.dodanieGetline(1);
                    break;
                case 8:
                {
                    system("cls");
                    ifstream plikOd("zestawienieRejestratorow.txt");
                    if (plikOd.is_open()) {
                        cout << "Czytanie pliku...\n";
                        plikOd >> zestaw;
                        plikOd.close();
                    }
                    break;
                }
                case 9:
                    system("cls");
                    cout << zestaw; // wykorzystanie przeciążonego operatora wyjścia
                    break;
                case 10:
                    system("cls");
                    // wykorzystanie przeciążonego operatora indeksowania
                    cout << zestaw[0].get_nazwa() << " " << zestaw[0].get_kolor() << endl;
                    cout << zestaw(0).get_nazwa() << " " << zestaw(0).get_kolor() << endl;
                    zestaw[0].set_nazwa("NowaNazwa");
                    zestaw(0).set_kolor("NowyKolor");
                    cout << zestaw[0].get_nazwa() << " " << zestaw[0].get_kolor() << endl;
                    cout << zestaw(0).get_nazwa() << " " << zestaw(0).get_kolor() << endl;
                    break;
                case 11:
                    break;
                default:
                    system("cls");
                    cout << "Bledny wybor, powtorz" << endl;
                    break;
                }
            } while (wybor_rejestrator != 11);

            break;
        case 3:
            break;

        default:
            cout << "Bledny wybor, powtorz" << endl;
            break;
        }
    } while (wybor_glowny != 3);

    return 0;
}

//ZADANIE 6
void wyswietl_biuro(Miejsce*& miejsce)
{
    miejsce = new Biuro;
    miejsce->wyswietl_adres();
}

void wyswietl_magazyn(Miejsce*& miejsce)
{
    miejsce = new Magazyn;
    miejsce->wyswietl_adres();
}