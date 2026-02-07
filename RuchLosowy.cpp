#include "RuchGracza.hpp"
#include "Plansza.hpp"
#include "ObslugaGry.hpp"
#include <cstdlib>  // dla rand()
#include <iostream>

//losowanie pustych pol startoweho i koncowego
void RuchLosowy::losowePoleStartoweIKoncowe(Plansza& tab) {
    // Losowanie pozycji startowej (niepuste pole)
    do {
        x1 = rand() % N;
        y1 = rand() % N;
    } while (tab.czyPuste(x1, y1));

    // Losowanie pozycji docelowej (puste pole)
    do {
        x2 = rand() % N;
        y2 = rand() % N;
    } while (!tab.czyPuste(x2, y2));
}
//wywolanie funkcji losujacej pole startowe i koncowe i wykonanie ruchu jezeli jest mozliwy lub informacja o niepowodzeniu
void RuchLosowy::WykonajRuch(Plansza& tab, ObslugaGry* gra) {
    losowePoleStartoweIKoncowe(tab);

    if (tab.przesun(x1, y1, x2, y2)) {
        cout << "\nPrzesunieto kulke z pola: (" << x1+1 << ", " << y1+1 << ") do pola: (" << x2 +1<< ", " << y2+1 << ")\n";
        int usuniete = tab.usunKulki();
        if (usuniete > 0) {
            gra->dodajWynik(usuniete); 
        }
        else {
            tab.generujKulki(3);
        }
    }
    else {
        cout << "Losowy ruch nie powiód³ siê.\n";
    }
}