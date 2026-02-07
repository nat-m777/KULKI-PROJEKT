#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <ctime>
#include "ObslugaGry.hpp"
#include "BazaDanych.hpp"

using namespace std;

int main() {
    // Inicjalizacja generatora liczb losowych
    srand(static_cast<unsigned int>(time(NULL)));

    // Tworzymy obiekt głównej obsługi gry i bazy danych
    ObslugaGry gra;
    BazaDanych baza;

    // Przypisujemy wzajemne powiązania
    baza.setDaneZGry(&gra);  // żeby BazaDanych mogła zapisywać/odczytywać dane gry
    gra.ustawBaze(&baza);    // żeby ObslugaGry mogła korzystać z tej samej bazy

    // Pobranie nazwy użytkownika
    string nazwaUzytkownika;
    cout << "Podaj nazwe uzytkownika: ";
    getline(cin, nazwaUzytkownika);

    // Walidacja nicku
    if (nazwaUzytkownika.empty()) {
        cerr << "Nie podano nazwy użytkownika. Program zostaje zakonczony." << endl;
        return 1;
    }

    // Rozpoczęcie gry
    gra.start(nazwaUzytkownika);  // ustawienia początkowe
    gra.graWTrakcie();            // główna pętla gry
    gra.koniec();                 // zakończenie i zapis wyniku

    cout << "Dziekujemy za gre!" << endl;

    return 0;
}
