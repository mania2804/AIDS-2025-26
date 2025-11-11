#include <iostream>
#include <cmath>
using namespace std;

bool czy_pierwsza(int liczba) {
    if (liczba <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(liczba); i++) {
        if (liczba % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int liczba;
    cout << "Podaj liczbe: ";
    cin >> liczba;

    if (czy_pierwsza(liczba)) {
        cout << liczba << " jest liczba pierwsza." << endl;
    } else {
        cout << liczba << " nie jest liczba pierwsza." << endl;
    }

    return 0;
}
