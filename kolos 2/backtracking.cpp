#include <iostream>
using namespace std;

const int N = 5;  // rozmiar szachownicy (N hetmanów)

bool kolumnaZajeta[N];          // czy kolumna jest już zajęta przez hetmana
bool przekatna1Zajeta[2*N];     // przekątna typu "/"   indeks = wiersz + kolumna
bool przekatna2Zajeta[2*N];     // przekątna typu "\"  indeks = wiersz - kolumna + N
int pozycjaHetmana[N];          // pozycjaHetmana[w] = kolumna, w której stoi hetman w wierszu w

int liczbaRozwiazan = 0;

void szukaj(int wiersz) {
    if (wiersz == N) {
        // znaleziono poprawne ustawienie
        liczbaRozwiazan++;
        cout << "ROZWIAZANIE " << liczbaRozwiazan << ":\n";
        for (int w = 0; w < N; w++) {
            for (int k = 0; k < N; k++) {
                cout << (pozycjaHetmana[w] == k ? "H " : ". ");
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for (int kol = 0; kol < N; kol++) {

        if (!kolumnaZajeta[kol] &&
            !przekatna1Zajeta[wiersz + kol] &&
            !przekatna2Zajeta[wiersz - kol + N]) {

            // wykonujemy ruch: ustawiamy hetmana
            pozycjaHetmana[wiersz] = kol;
            kolumnaZajeta[kol] = true;
            przekatna1Zajeta[wiersz + kol] = true;
            przekatna2Zajeta[wiersz - kol + N] = true;

            // rekurencja: idziemy do kolejnego wiersza
            szukaj(wiersz + 1);

            // cofnięcie ruchu (BACKTRACKING)
            kolumnaZajeta[kol] = false;
            przekatna1Zajeta[wiersz + kol] = false;
            przekatna2Zajeta[wiersz - kol + N] = false;
        }
    }
}

int main() {
    szukaj(0);
    cout << "Licza wszystkich rozwiazan: " << liczbaRozwiazan << "\n";
}