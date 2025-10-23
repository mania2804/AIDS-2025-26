#include <iostream>
#include <iomanip>

using namespace std;

void wypelnijSpirala(int** tab, int N, int M) {
    int wartosc = 1;
    int min_wiersz = 0, max_wiersz = N - 1;
    int min_kolumna = 0, max_kolumna = M - 1;

    while (min_wiersz <= max_wiersz && min_kolumna <= max_kolumna) {
        // W prawo
        for (int i = min_kolumna; i <= max_kolumna; ++i) {
            tab[min_wiersz][i] = wartosc++;
        }
        min_wiersz++;

        // W dół
        for (int i = min_wiersz; i <= max_wiersz; ++i) {
            tab[i][max_kolumna] = wartosc++;
        }
        max_kolumna--;

        // W lewo
        if (min_wiersz <= max_wiersz) {
            for (int i = max_kolumna; i >= min_kolumna; --i) {
                tab[max_wiersz][i] = wartosc++;
            }
            max_wiersz--;
        }

        // W górę
        if (min_kolumna <= max_kolumna) {
            for (int i = max_wiersz; i >= min_wiersz; --i) {
                tab[i][min_kolumna] = wartosc++;
            }
            min_kolumna++;
        }
    }
}

int main() {
    int N, M;
    cout << "Podaj wymiar N: ";
    cin >> N;
    cout << "Podaj wymiar M: ";
    cin >> M;

    // Alokacja tablicy
    int** tab = new int*[N];
    for (int i = 0; i < N; ++i) {
        tab[i] = new int[M];
    }

    // Wypełnianie spirali
    wypelnijSpirala(tab, N, M);

    // Wypisywanie tablicy
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << setw(6) << tab[i][j];
        }
        cout << endl;
    }

    // Zwolnienie pamięci
    for (int i = 0; i < N; ++i) {
        delete[] tab[i];
    }
    delete[] tab;

    return 0;
}
