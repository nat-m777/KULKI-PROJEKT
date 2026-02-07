#ifndef KULKA_HPP
#define KULKA_HPP

#include <string>

enum class Kolor {
    Czerwony, Zielony, Niebieski, Szary, Fioletowy, Pomaranczowy, Rozowy
};

/**
 * @class Kulka
 * @brief Reprezentuje pojedyncz¹ kulkê na planszy
 *
 * Przechowuje informacje o kolorze kulki i udostêpnia metody
 * konwersji miêdzy reprezentacj¹ enum a znakow¹.
 * Jest komponentem wykorzystywanym przez klasê Plansza.
 */

class Kulka {
protected:
    Kolor kolor;
public:
    Kulka(Kolor c);
    Kolor getKolor() const;
    static char kolorNaZnak(Kolor k);
    static Kolor znakNaKolor(char c);
};

#endif