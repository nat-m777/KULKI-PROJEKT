#include "RuchGracza.hpp"
#include "Plansza.hpp"
#include "ObslugaGry.hpp"
#include <iostream>

// Odczytuje od gracza wspó³rzêdne pola startowego i docelowego
// Pyta u¿ytkownika o wspó³rzêdne (x, y) dla pola startowego i docelowego.
// Zapisuje dane do pól x1, y1, x2, y2.
void RuchGracza::odczytPolaStartowegoIKoncowego() {
    cout << "Podaj wspolrzedne pola startowego (x y): ";
    cin >> x1 >> y1;
    cout << "Podaj wspolrzedne pola docelowego (x y): ";
    cin >> x2 >> y2;
}

// Wykonuje ruch gracza na planszy.
// Argumenty:
// - tab: referencja do obiektu planszy,
// - gra: wskaŸnik do obiektu obs³ugi gry.
//
// Etapy:
// 1. Pobiera wspó³rzêdne ruchu od gracza.
// 2. Sprawdza, czy pole startowe zawiera kulkê.
// 3. Próbuje przesun¹æ kulkê.
// 4. Jeœli siê uda³o:
//    - usuwa ewentualne kulki w rzêdzie,
//    - dodaje punkty lub generuje nowe kulki.
// 5. W przeciwnym razie wyœwietla komunikat o b³êdzie.
void RuchGracza::WykonajRuch(Plansza& tab, ObslugaGry* gra) {
    // 1. Pobranie wspó³rzêdnych od gracza
    odczytPolaStartowegoIKoncowego();

    // 2. Sprawdzenie czy pole startowe nie jest puste
    if (tab.czyPuste(x1 - 1, y1 - 1)) {
        cout << "Wybierz pole z kulka!\n";
        return;
    }

    // 3. Próba wykonania ruchu na planszy
    if (tab.przesun(x1 - 1, y1 - 1, x2 - 1, y2 - 1)) {
        // Ruch siê powiód³
         cout << "\nPrzesunieto kulke z pola: (" << x1 << ", " << y1
            << ") do pola: (" << x2 << ", " << y2 << ")\n";

        // 4a. Sprawdzenie czy powsta³ rz¹d do usuniêcia
        int usuniete = tab.usunKulki();
        if (usuniete > 0) {
            // Dodanie punktów za usuniête kulki
            gra->dodajWynik(usuniete);
        }
        else {
            // 4b. Generowanie nowych kulek jeœli nie usuniêto ¿adnych
            tab.generujKulki(3);
        }
    }
    else {
        // 5. Komunikat o b³êdzie ruchu
        cout << "Nie mozna wykonac ruchu. Sprobuj ponownie.\n";
    }
}
