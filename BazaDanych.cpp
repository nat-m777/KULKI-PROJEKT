#include "BazaDanych.hpp"
#include "ObslugaGry.hpp"
#include <iostream>

// ---KONSTRUKTOR ---
// Inicjalizuje wskaŸnik na dane gry jako nullptr i nazwê pliku jako pusty string
BazaDanych::BazaDanych() : plikZDanymi(""), daneZGry(nullptr) {};

// --- SETTERY ---

// Ustawia wskaŸnik na aktualny obiekt gry, którego dane bêd¹ zapisywane lub aktualizowane
void BazaDanych::setDaneZGry(ObslugaGry* gra) {
    daneZGry = gra;
}

// Ustawia nazwê pliku, z którego lub do którego bêd¹ zapisywane dane
void BazaDanych::setPlikZDanymi(const string& nazwa) {
    plikZDanymi = nazwa;
}

// --- GETTERY ---

// Zwraca wskaŸnik na dane gry
ObslugaGry* BazaDanych::getDaneZGry() {
    return daneZGry;
}

// Zwraca nazwê pliku z danymi gry
string BazaDanych::getPlikZDanymi() const {
    return plikZDanymi;
}

// --- ZAPIS STANU GRY ---
// Zapisuje stan gry (nick, planszê jako tekst, wynik) do pliku tekstowego
void BazaDanych::zapiszStanGry(ObslugaGry* przekazanaGra) {
    ofstream wyniki(plikZDanymi, ios::app); // otwiera plik w trybie dopisywania
    if (!wyniki.is_open()) {
        cerr << "Nie mozna otworzyc pliku do zapisu stanu gry." << endl;
        return;
    }

    setDaneZGry(przekazanaGra);  // aktualizuje wskaŸnik na grê
    wyniki << daneZGry->getNick() << " "           // zapisuje nick
        << daneZGry->getPlansza() << " "        // zapisuje planszê w formie tekstowej
        << daneZGry->getWynik() << endl;        // zapisuje wynik

    wyniki.close();  // zamyka plik
}

// --- ODCZYT STANU GRY DLA GRACZA ---
// Odczytuje dane zapisane w pliku dla gracza o podanym nicku
void BazaDanych::odczytaj(string nickOdUzytkownika) {
    ifstream plik(plikZDanymi); // otwiera plik do odczytu
    if (!plik.is_open()) {
        cerr << "Nie mozna otworzyc pliku z danymi gry." << endl;
        return;
    }

    string linia;
    bool znaleziono = false; // Flaga wskazuj¹ca, czy znaleziono przynajmniej jedno dopasowanie

    while (getline(plik, linia)) {  // przetwarza ka¿d¹ liniê osobno
        istringstream ss(linia);    // przekszta³ca liniê w strumieñ danych
        string nick, plansza;
        int wynik;

        ss >> nick >> plansza >> wynik;  // odczytuje dane z linii

        // Jeœli znajdzie dane dla gracza o wskazanym nicku — aktualizuje dane w obiekcie gry
        if (nick == nickOdUzytkownika) {
            daneZGry->setNick(nick);
            daneZGry->setWynik(wynik);
            daneZGry->setPlansza(plansza);
            znaleziono = true; // Ustaw flagê na true, gdy znajdzie dopasowanie
        }
    }

    // Jeœli nie znaleziono danych
    if (!znaleziono) {
        cout << "Nie znaleziono danych dla gracza: " << nickOdUzytkownika << endl;
    }
}
