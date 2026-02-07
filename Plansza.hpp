#ifndef PLANSZA_HPP
#define PLANSZA_HPP

#include <string>
#include "Kulka.hpp"

const int N = 9; // Rozmiar planszy

/**
 * @class Plansza
 * @brief Reprezentuje planszę gry z kulkami
 *
 * Zawiera tablicę 2D wskaźników do obiektów Kulka.
 * Udostępnia metody do zarządzania stanem planszy.
 */

class Plansza {
protected:
    Kulka* tablica[N][N];

private:
    bool istniejeSciezka(int x1, int y1, int x2, int y2);

public:
    Plansza();
    ~Plansza();

    Kulka* getKulka(int x, int y) const;
    void setKulka(int x, int y, Kulka* k);
    void generujKulki(int ilosc);
    bool przesun(int x1, int y1, int x2, int y2);
    int usunKulki();
    bool czyPelna() const;
    void wyswietl();
    bool czyPuste(int x, int y);
    void odczytajZTekstu(const std::string& tekst);
    std::string zapiszJakoTekst() const;
    //void dodajWynik(int x);
};

#endif