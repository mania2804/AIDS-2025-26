#include <iostream>
using namespace std;

const int N = 5; // Rozmiar labiryntu

// Labirynt: 1 = ściana, 0 = droga, M = meta
char labirynt[N][N] = {
    {'1', '0', '1', '1', '1'},
    {'1', '0', '0', '0', '1'},
    {'1', '1', '1', '0', '1'},
    {'1', '0', '0', '0', '0'},
    {'1', '1', '1', '1', 'M'}
};

// Tablica do śledzenia odwiedzonych komórek
bool odwiedzone[N][N] = {false};

// Możliwe kierunki ruchu: góra, prawo, dół, lewo
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// Funkcja wypisująca labirynt
void wypiszLabirynt() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << labirynt[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Funkcja rekurencyjna rozwiązująca labirynt
bool rozwiazLabirynt(int x, int y) {
    // Sprawdź, czy wyszliśmy poza labirynt lub natrafiliśmy na ścianę
    if (x < 0 || x >= N || y < 0 || y >= N || labirynt[x][y] == '1' || odwiedzone[x][y]) {
        return false;
    }

    // Sprawdź, czy dotarliśmy do mety
    if (labirynt[x][y] == 'M') {
        labirynt[x][y] = 'X'; // Oznacz metę jako część drogi
        return true;
    }

    // Oznacz aktualną komórkę jako odwiedzoną
    odwiedzone[x][y] = true;
    labirynt[x][y] = 'X'; // Oznacz drogę

    // Próbuj iść we wszystkich możliwych kierunkach
    for (int i = 0; i < 4; ++i) {
        int nowyX = x + dx[i];
        int nowyY = y + dy[i];

        if (rozwiazLabirynt(nowyX, nowyY)) {
            return true; // Jeśli znaleziono drogę, zwróć true
        }
    }

    // Cofnij się, jeśli nie znaleziono drogi
    labirynt[x][y] = '0';
    return false;
}

int main() {
    cout << "Labirynt przed rozwiązaniem:" << endl;
    wypiszLabirynt();

    // Ustaw pozycję startową
    int startX = 0, startY = 1;

    if (rozwiazLabirynt(startX, startY)) {
        cout << "Rozwiązany labirynt:" << endl;
        wypiszLabirynt();
    } else {
        cout << "Brak drogi do mety!" << endl;
    }

    return 0;
}
