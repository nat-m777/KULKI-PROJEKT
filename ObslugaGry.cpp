#include "ObslugaGry.hpp"
#include "Ruch.hpp"        // Konieczne, by znać klasę bazową
#include "RuchGracza.hpp"  // Konieczne, by wiedzieć, że dziedziczy po Ruch
#include "RuchLosowy.hpp"  // Konieczne dla RuchLosowy
#include <iostream>
using namespace std;

// Konstruktor klasy ObslugaGry - inicjalizuje pola domy�lnymi warto�ciami
ObslugaGry::ObslugaGry()
    : tablica(), aktualnyRuch(nullptr), nick(""), wynik(0), bazaPtr(nullptr) {}

// Setter - ustawia nazw� gracza
void ObslugaGry::setNick(const string& nazwa) {
    nick = nazwa;
}

// Setter - ustawia wynik gracza
void ObslugaGry::setWynik(int x) {
    wynik = x;
}

// Setter - ustawia plansz� na podstawie tekstowej reprezentacji
void ObslugaGry::setPlansza(const string& tekstowaPlansza) {
    tablica.odczytajZTekstu(tekstowaPlansza);
}

// Setter - ustawia wska�nik do bazy danych
void ObslugaGry::ustawBaze(BazaDanych* baza) {
    bazaPtr = baza;
}

// Getter - zwraca nazw� gracza
string ObslugaGry::getNick() const {
    return nick;
}

// Getter - zwraca aktualny wynik gracza
int ObslugaGry::getWynik() const {
    return wynik;
}

// Getter - zwraca plansz� jako tekst
string ObslugaGry::getPlansza() const {
    return tablica.zapiszJakoTekst();
}

// Rozpoczyna now� gr�: ustawia nick i generuje pocz�tkowe kulki
void ObslugaGry::start(const string& nickPodany) {
    setNick(nickPodany);
    tablica.generujKulki(3);
}

// Zapisuje aktualny stan gry do pliku
void ObslugaGry::zapiszAktualnyStan() {
    if (!bazaPtr) {
        cerr << "B��d: Baza danych nie zosta�a ustawiona!" << endl;
        return;
    }

    string nazwaPlikuOdUzytkownika;
    cout << "Podaj nazwe pliku do zapisu: ";
    cin >> nazwaPlikuOdUzytkownika;

    bazaPtr->setPlikZDanymi(nazwaPlikuOdUzytkownika);
    bazaPtr->zapiszStanGry(this);
}

// Odczytuje zapisany stan gry z pliku
void ObslugaGry::odczytajGre() {
    if (!bazaPtr) {
        cerr << "Baza danych nie zosta�a ustawiona!" << endl;
        return;
    }

    string nazwaPlikuOdUzytkownika;
    cout << "Podaj nazwe pliku z danymi do odczytania: ";
    cin >> nazwaPlikuOdUzytkownika;

    bazaPtr->setPlikZDanymi(nazwaPlikuOdUzytkownika);
    bazaPtr->setDaneZGry(this);  // ustawia dane kontekstu gry w bazie
    bazaPtr->odczytaj(nick);     // odczytuje stan gry
}

// G��wna p�tla gry - pozwala u�ytkownikowi wybra� rodzaj ruchu lub inne akcje
void ObslugaGry::graWTrakcie() {
    string wybor;

    while (!tablica.czyPelna()) {
        tablica.wyswietl();         // wy�wietla plansz�
        wyswietlPunktacje();        // wy�wietla aktualny wynik

        // Menu wyboru
        cout << "[G] Ruch gracza\n";
        cout << "[L] Losowy ruch\n";
        cout << "[Z] Zapisz i wyjdz\n";
        cout << "[K] Kontynuj zapisana gre\n";
        cout << "Twoj wybor: ";
        cin >> wybor;

        // Wyb�r rodzaju ruchu
        if (wybor == "G" || wybor == "g") {
            aktualnyRuch = new RuchGracza();  // ruch r�czny gracza
        }
        else if (wybor == "L" || wybor == "l") {
            aktualnyRuch = new RuchLosowy();  // losowy ruch
        }
        else if (wybor == "Z" || wybor == "z") {
            zapiszAktualnyStan();             // zapisanie gry
            break;
        }
        else if (wybor == "K" || wybor == "k") {
            odczytajGre();                    // kontynuacja zapisanej gry
            continue;
        }
        else {
            cout << "Nieznana opcja.\n";      // obs�uga b��dnego wyboru
            continue;
        }

        // Wykonuje wybrany ruch
        aktualnyRuch->WykonajRuch(tablica, this);
        delete aktualnyRuch;         // zwalnia pami��
        aktualnyRuch = nullptr;
    }
}

// Informuje o zako�czeniu gry i pokazuje wynik
void ObslugaGry::koniec() {
    cout << "\nGra zakonczona!\n";
    cout << "Twoj wynik: " << wynik << endl;
}

// Wy�wietla aktualn� punktacj�
void ObslugaGry::wyswietlPunktacje() const {
    cout << "Aktualny wynik: " << wynik << endl;
}

// Dodaje podan� ilo�� punkt�w do wyniku gracza
void ObslugaGry::dodajWynik(int x) {
    wynik += x;
}
