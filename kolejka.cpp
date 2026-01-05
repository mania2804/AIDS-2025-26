
#include <iostream>
#include <queue>

int main() {
    std::queue<std::string> kolejkaDoKasy;

    // Dodawanie osób do kolejki
    kolejkaDoKasy.push("Anna");
    kolejkaDoKasy.push("Bartek");
    kolejkaDoKasy.push("Cezary");

    std::cout << "Pierwsza osoba: " << kolejkaDoKasy.front() << std::endl; // Anna
    std::cout << "Ostatnia osoba: " << kolejkaDoKasy.back() << std::endl;  // Cezary

    // Obsługa pierwszej osoby
    kolejkaDoKasy.pop(); // Anna wychodzi

    std::cout << "Nowa pierwsza osoba: " << kolejkaDoKasy.front() << std::endl; // Bartek

    return 0;
}
