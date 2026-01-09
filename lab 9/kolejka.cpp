#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct Node {
    string imie;
    string nazwisko;
    int wiek;
    double waga;
    Node* next = nullptr;
};

void zakolejkuj(Node*& head, string imie, string nazwisko, int wiek, double waga) {
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

void pobierz(Node*&head) {
    if (head==nullptr) {
        cout<<"Kolejka jest pusta, nie można pobrać elementu"<<endl;;
    }
    else {
        Node*temp=head;
        head=head->next;
        delete temp;
    }
}

void rozmiar(Node *&head, int licznik) {
    if (head==nullptr) {
        cout<<"Rozmiar kolejki 0"<<endl;;
    }
    Node* temp = head;
    while (temp!=nullptr) {
        temp=temp->next;
        licznik++;
    }
    cout<<"Rozmiar kolejki "<<licznik<<endl;;
}

void wypisz(Node* head) {
    if (head == nullptr) {
        cout << "Kolejka jest pusta" << endl;
        return;
    }
    cout << "Kolejka:" << endl;
    cout << setw(3) << "NR" << "|"
         << setw(25) << "IMIE" << "|"
         << setw(25) << "NAZWISKO" << "|"
         << setw(4) << "WIEK" << "|"
         << setw(5) << "WAGA" << endl;
    int nr=1;
    Node* temp = head;
    while (temp != nullptr) {
        cout <<setw(3) <<nr<<"|"
            <<setw(25)<<temp->imie<<"|"
            <<setw(25)<< temp->nazwisko<<"|"
            << setw(4)<<temp->wiek<<"|"
            << setw(5)<< temp->waga << "|"
            << endl;
        temp = temp->next;
        nr++;
    }
}


int main(int argc, char*argv[]) {
    if (argc<2) {
        cout<<"Podaj nazwę pliku jako paramtr."<<endl;
        return 1;
    }
    Node* head = nullptr;
    int licznik=0;
    ifstream plik(argv[1]);

    if (!plik.is_open()) {
        cout<<"Nie można otworzyć pliku."<<endl;
        return 1;
    }
    string komenda;
    while (plik>>komenda) {
        if (komenda=="zakolejkuj") {
            string i, n;
            int wi;
            double w;
            plik>>i>>n>>wi>>w;
            zakolejkuj(head, i, n, wi, w);
        }
        else if (komenda=="pobierz") {
            pobierz(head);
        }
        else if (komenda=="rozmiar") {
            rozmiar (head, licznik);
        }
        else if (komenda=="wypisz") {
            wypisz(head);
        }
    }
    
    plik.close();

    // zakolejkuj(head, "marysia", "dziedzic", 10, 20);
    // zakolejkuj(head, "julia", "blizniak", 30, 10);
    // zakolejkuj(head, "stary", "rok", 50, 60);
    // wypisz(head);
    // rozmiar(head, licznik);
    // pobierz(head);
    // cout<<endl;
    // wypisz(head);
    // rozmiar(head, licznik);

    return 0;
}
