#include <iostream>
#include <string>

using namespace std;

struct Node {
    string imie;
    string nazwisko;
    int wiek;
    int waga;
    Node* next = nullptr;
};

void zakolejkuj(Node*& head, string imie, string nazwisko, int wiek, int waga) {
    Node* nowy = new Node;
    nowy->imie = imie;
    nowy->nazwisko = nazwisko;
    nowy->wiek = wiek;
    nowy->waga = waga;
    nowy->next = nullptr;

    if (head == nullptr) {
        head = nowy;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nowy;
    }
}

void wypisz(Node* head) {
    if (head == nullptr) {
        cout << "Nie ma kolejki" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->imie << "," << temp->nazwisko << "," << temp->waga << "," << temp->wiek << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = nullptr;

    zakolejkuj(head, "marysia", "dziedzic", 10, 20);
    wypisz(head);

    return 0;
}
