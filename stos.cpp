
#include <iostream>
#include <stack> // Nagłówek wymagany do obsługi stosu

int main() {
    std::stack<int> mojStos;

    // Dodawanie elementów
    mojStos.push(10);
    mojStos.push(20);
    mojStos.push(30);

    std::cout << "Liczba elementów: " << mojStos.size() << std::endl; // Wynik: 3
    std::cout << "Element na szczycie: " << mojStos.top() << std::endl; // Wynik: 30

    // Usuwanie elementu
    mojStos.pop(); // Usuwa 30(bo tyle otatnio dodalismy)

    std::cout << "Nowy szczyt: " << mojStos.top() << std::endl; // Wynik: 20

    return 0;
}
