#ifndef OBSLUGAGRY_HPP
#define OBSLUGAGRY_HPP

#include <string>
#include "Plansza.hpp"
#include "Ruch.hpp"
#include "RuchGracza.hpp"
#include "RuchLosowy.hpp"
#include "BazaDanych.hpp"
using namespace std;


/**
 * @class ObslugaGry
 * @brief G��wna klasa zarz�dzaj�ca przebiegiem gry
 *
 * Koordynuje wszystkie aspekty gry: przechowuje stan planszy,
 * wyniki gracza, obs�uguje interfejs u�ytkownika i integruje
 * komponenty. Implementuje g��wn� p�tl� gry i menu.
 */

class ObslugaGry {
private:
    Plansza tablica;
    Ruch* aktualnyRuch;
    string nick;
    int wynik;
    BazaDanych* bazaPtr;

public:
    //konstruktor
    ObslugaGry();

    // Settery
    void setNick(const string& nazwa);
    void setWynik(int x);
    void setPlansza(const string& tekstowaPlansza);
    void ustawBaze(BazaDanych* baza);

    // Gettery
    string getNick() const;
    int getWynik() const;
    string getPlansza() const;

    // Metody gry
    void start(const string& nickPodany);
    void zapiszAktualnyStan();
    void odczytajGre();
    void graWTrakcie();
    void koniec();
    void wyswietlPunktacje() const;
    void dodajWynik(int x);
};

#endif