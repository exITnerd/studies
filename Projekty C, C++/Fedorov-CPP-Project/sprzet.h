#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <random>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

//Polimorfizm i dziedziczenie
//klasa abstrakcyjna
class Miejsce {
public:
    virtual void wyswietl_adres() = 0;
};

class Biuro : public Miejsce {
    string ulica = "Urodzajna";
    int static constexpr numer = 10;
    int static constexpr pietro = 13;
public:
    void wyswietl_adres() {
        cout << "Biuro znajduje sie przy ulicy: " << ulica << " Numer wiezowca: " << numer << " Na pietrze: " << pietro << endl;
    }
};

class Magazyn : public Miejsce {
    string ulica = "Krancowa";
    static constexpr int wielkosc_dzialki = 420;
    static constexpr int numer_magazynu = 1;
public:
    void wyswietl_adres() {
        cout << "Magazyn znajduje sie przy ulicy: " << ulica << " Powierzchnia magazynowa: " << wielkosc_dzialki << " Magazyn numer: " << numer_magazynu << endl;
    }
};


//Dziedziczenie
class Urzadzenie {
private:
    string nazwa;
    string kolor;
    string stan;
    int rozdzielczosc;
public:
    Urzadzenie(string nazwa, string kolor, string stan, int rozdzielczosc) : nazwa(nazwa), kolor(kolor), stan(stan), rozdzielczosc(rozdzielczosc) {};
    Urzadzenie() : nazwa(""), kolor(""), stan(""), rozdzielczosc(0) {}
    string get_nazwa() const { return nazwa; }
    string get_kolor() const { return kolor; }
    string get_stan() const { return stan; }
    int get_rozdzielczosc() const { return rozdzielczosc; }
    void set_nazwa(const string& s) { nazwa = s; }
    void set_kolor(const string& s) { kolor = s; }
    void set_stan(const string& s) { stan = s; }
    void set_rozdzielczosc(const int& i) { rozdzielczosc = i; }
};

class Zestaw {
    class Kamera : public Urzadzenie {
        friend class Zestaw;
    protected:
        Urzadzenie* u;
    public:
        Kamera(string nazwa, string kolor, string stan, int rozdzielczosc) : Urzadzenie(nazwa, kolor, stan, rozdzielczosc), u(this) {};
        Kamera() : Urzadzenie(), u(this) {};
        string get_nazwa() const { return Urzadzenie::get_nazwa(); }
        string get_kolor() const { return Urzadzenie::get_kolor(); }
        string get_stan() const { return Urzadzenie::get_stan(); }
        int get_rozdzielczosc() const { return Urzadzenie::get_rozdzielczosc(); }
        void set_nazwa(const string& s) { Urzadzenie::set_nazwa(s); }
        void set_kolor(const string& s) { Urzadzenie::set_kolor(s); }
        void set_stan(const string& s) { Urzadzenie::set_stan(s); }
        void set_rozdzielczosc(const int& i) { Urzadzenie::set_rozdzielczosc(i); }
    };

    class Rejestrator : public Urzadzenie {
        friend class Zestaw;
    protected:
        Urzadzenie* u;
    public:
        Rejestrator(string nazwa, string kolor, string stan, int rozdzielczosc) : Urzadzenie(nazwa, kolor, stan, rozdzielczosc), u(this) {};
        Rejestrator() : Urzadzenie(), u(this) {};
        string get_nazwa() const { return Urzadzenie::get_nazwa(); }
        string get_kolor() const { return Urzadzenie::get_kolor(); }
        string get_stan() const { return Urzadzenie::get_stan(); }
        int get_rozdzielczosc() const { return Urzadzenie::get_rozdzielczosc(); }
        void set_nazwa(const string& s) { Urzadzenie::set_nazwa(s); }
        void set_kolor(const string& s) { Urzadzenie::set_kolor(s); }
        void set_stan(const string& s) { Urzadzenie::set_stan(s); }
        void set_rozdzielczosc(const int& i) { Urzadzenie::set_rozdzielczosc(i); }
    };

private:
    string nazwa;
    string kolor;
    string stan;
    int rozdzielczosc;
    Kamera* kamery;
    Rejestrator** rejestratory;
    int iloscKamer;
    int iloscRejestratorow;
public:
    Zestaw(string nazwa, string kolor, string stan, int rozdzielczosc, int iloscKamer, int iloscRejestratorow) : nazwa(nazwa), kolor(kolor), stan(stan), rozdzielczosc(rozdzielczosc), iloscKamer(iloscKamer), iloscRejestratorow(iloscRejestratorow) {
        kamery = nullptr;
        rejestratory = nullptr;
    }
    //Konstruktor kopiujacy
    Zestaw(const Zestaw& zestaw);

    //Destruktor
    ~Zestaw() {
        for (int i = 0; i < iloscRejestratorow; i++) {
            delete rejestratory[i];
        }
        delete[] rejestratory;
        delete[] kamery;
    }

    friend istream& operator>>(istream& wejscie, Zestaw& z);
    friend ostream& operator<<(ostream& wyjscie, const Zestaw& z);
    Zestaw& operator=(const Zestaw& other);

    Kamera& operator()(int index)
    {
        if (index < 0 || index >= iloscKamer)
        {
            cout << ("Nieprawidlowy indeks kamery.");
        }
        return kamery[index];
    }

    Rejestrator& operator[](int index)
    {
        if (index < 0 || index >= iloscRejestratorow)
        {
            cout << ("Nieprawidlowy indeks rejestratora.");
        }
        return *rejestratory[index];
    }

    int iloscK() {
        return iloscKamer;
    };

    int iloscR() {
        return iloscRejestratorow;
    };

    Kamera getKamery(int index) {
        return kamery[index];
    }

    void tworzenie();
    void tworzenie(int R);
    void inicjalizacja();
    void inicjalizacja(int R);
    void wyswietlanie();
    void wyswietlanie(int R);
    void usuwanie();
    void usuwanie(int R);
    void edytowanie();
    void edytowanie(int R);
    void sortowanie();
    void sortowanie(int R);
    void zestawienie();
    void zestawienie(int R);
    void dodanieGetline();
    void dodanieGetline(int R);
};