#include "Kulka.hpp"

// Konstruktor
Kulka::Kulka(Kolor c) : kolor(c) {}

// Getter koloru
Kolor Kulka::getKolor() const {
    return kolor;
}

// Konwersja koloru na znak
char Kulka::kolorNaZnak(Kolor k) {
    switch (k) {
    case Kolor::Czerwony:     return 'C';
    case Kolor::Zielony:      return 'Z';
    case Kolor::Niebieski:    return 'N';
    case Kolor::Szary:        return 'S';
    case Kolor::Fioletowy:    return 'F';
    case Kolor::Pomaranczowy: return 'P';
    case Kolor::Rozowy:       return 'R';
    default:                  return '?';
    }
}

// Konwersja znaku na kolor
Kolor Kulka::znakNaKolor(char c) {
    switch (c) {
    case 'C': return Kolor::Czerwony;
    case 'Z': return Kolor::Zielony;
    case 'N': return Kolor::Niebieski;
    case 'S': return Kolor::Szary;
    case 'F': return Kolor::Fioletowy;
    case 'P': return Kolor::Pomaranczowy;
    case 'R': return Kolor::Rozowy;
    default:  return Kolor::Szary; // Domyœlny kolor
    }
}