#include <iostream>
using namespace std;

int wypelnij_i_suma(int **tab, int n) {
    int liczba = 1;

    // Wypełnianie tablicy kolumnami od końca
    for (int kolumna = n - 1; kolumna >= 0; kolumna--) {
        for (int wiersz = 0; wiersz < n; wiersz++) {
            tab[wiersz][kolumna] = liczba++;
        }
    }

    // Obliczanie sumy liczb na przekątnych
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += tab[i][i]; // Przekątna główna
        suma += tab[i][n - 1 - i]; // Przekątna poboczna
    }

    // Jeśli n jest nieparzyste, odejmujemy środkowy element, który został dodany dwa razy
    if (n % 2 == 1) {
        suma -= tab[n / 2][n / 2];
    }

    return suma;
}

int main() {
    int n;
    cout << "Podaj rozmiar tablicy: ";
    cin >> n;

    // Tworzenie tablicy dwuwymiarowej dynamicznej
    int **tab = new int *[n];
    for (int i = 0; i < n; i++) {
        tab[i] = new int[n];
    }

    int suma = wypelnij_i_suma(tab, n);

    // Wyświetlanie tablicy (opcjonalnie)
    cout << "Wypelniona tablica:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << tab[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Suma liczb na przekatnych wynosi: " << suma << endl;

    // Zwolnienie pamięci
    for (int i = 0; i < n; i++) {
        delete[] tab[i];
    }
    delete[] tab;

    return 0;
}
