#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const char* tablica_rejestracyjna() {
    static const char dozwolone_litery[] = "ACEGJKLMNPQRSTUVWX";
    static const char dozwolone_cyfry[] = "0123456789";
    static char tablica[9]; // KR + spacja + 5 znaków + NULL

    // Inicjalizacja generatora liczb pseudolosowych
    srand(time(0));

    // Ustawienie początku tablicy
    tablica[0] = 'K';
    tablica[1] = 'R';
    tablica[2] = ' ';

    // Generowanie 5 znaków
    for (int i = 0; i < 5; i += 2) {
        // Losowanie, czy pierwsza pozycja w parze to litera (0) czy cyfra (1)
        int losowa_decyzja = rand() % 2;

        if (losowa_decyzja == 0) {
            // Pierwsza pozycja w parze to litera
            tablica[3 + i] = dozwolone_litery[rand() % (sizeof(dozwolone_litery) - 1)];
            tablica[3 + i + 1] = dozwolone_cyfry[rand() % (sizeof(dozwolone_cyfry) - 1)];
        } else {
            // Pierwsza pozycja w parze to cyfra
            tablica[3 + i] = dozwolone_cyfry[rand() % (sizeof(dozwolone_cyfry) - 1)];
            tablica[3 + i + 1] = dozwolone_litery[rand() % (sizeof(dozwolone_litery) - 1)];
        }
    }

    tablica[8] = '\0'; // Zakończenie stringa

    return tablica;
}

int main() {
    // Przykładowe wywołanie
    const char* wynik = tablica_rejestracyjna();
    cout << wynik << endl;
    return 0;
}
