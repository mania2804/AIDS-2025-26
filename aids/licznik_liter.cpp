#include <iostream>
#include <cctype> // dla funkcji tolower
#include <cstring> // dla funkcji strlen

int policz_litery(const char* tekst, char litera) {
    int licznik = 0;
    char litera2 = tolower(litera);

    for (int i = 0; i < strlen(tekst); i++) {
        if (tolower(tekst[i]) == litera2) {
            licznik++;
        }
    }

    return licznik;
}

int main() {
    const int n = 100;
    char tekst[n];
    char litera;

    std::cout << "Podaj ciag znakow: ";
    std::cin.getline(tekst, n);

    std::cout << "Podaj litere do policzenia: ";
    std::cin >> litera;

    int wynik = policz_litery(tekst, litera);
    std::cout << "Liczba wystapien litery '" << litera << "' wynosi: " << wynik << std::endl;

    return 0;
}
