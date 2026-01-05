
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


zadanie stos

#include <iostream>
#include <stack>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>


using namespace std;

struct Node {
    string data;
    Node* next;
};

//funkcje

void odloz(Node*& top, const string& tekst, int& licznik) {
    Node* nowy=new Node;
    nowy->data=tekst;
    nowy->next=top; //nowy wezel wskakuje na obecny szczyt
    top=nowy;  //nowy wezel staje sie szczytem
    licznik++;
}

void zdejmij(Node*& top, int& licznik) {
    if (top==nullptr) {
        cout<<"Stos jest pusty, nie można zdjąć elementu."<<endl;
        return;
    }
    Node* temp=top;
    top= top->next;
    delete temp;
    licznik--;
}

void podejrzyj(Node*top) {
    if (top!=nullptr) {
        cout<<"Na wierzchu stosu: "<<top->data<<endl;
    } else {
        cout<<"Stos jest pusty."<<endl;
    }
}

void rozmiar(int licznik) {
    cout<<"Rozmiar stosu: "<<licznik<<endl;
}

void czy_pusty(Node* top) {
    if (top==nullptr) {
        cout<<"Stos jest pusty."<<endl;
    }else {
        cout<<"Stos nie jest pusty."<<endl;
    }
}

void wypisz(Node* top) {
    if (top==nullptr) {
        cout<<"Stos jest pusty."<<endl;
        return;
    }
    cout<<"Stos:"<<endl;
    int i=1;
    for (Node* aktualny=top;aktualny!=nullptr; aktualny=aktualny->next) {
        cout<<"["<<setw(3)<<i++<<"] "<<aktualny->data<<endl;
    }
}
void wyczysc(Node*& top, int& licznik) {
    while (top!=nullptr) {
        Node* temp=top;
        top=top->next;
        delete temp;
    }
    licznik=0;
}

int main(int argc, char* argv[]) {
    if (argc<2) {
        cout<<"Użycie: "<<argv[0]<<"<nazwa_pliku"<<endl;
        return 1;
    }

    ifstream plik(argv[1]);
    if (!plik.is_open()) {
        cout<<"Nie można otworzyć pliku: "<<argv[1]<<endl;
        return 1;
    }


    Node* stackTop=nullptr;
    int stackSize = 0;
    string komenda;
    string linia;

    while (getline(plik, linia)) {
        if (linia.empty()) continue;

        stringstream ss(linia);
        ss>>komenda;
        if (komenda=="odloz") {
            string tekst;
            getline(ss>>ws,tekst);
            odloz(stackTop, tekst, stackSize);
        }
        else if (komenda=="zdejmij"){
            zdejmij(stackTop, stackSize);
        }
        else if (komenda=="podejrzyj") {
            podejrzyj(stackTop);
        }
        else if (komenda=="rozmiar") {
            rozmiar(stackSize);
        }
        else if (komenda=="czy_pusty") {
            czy_pusty(stackTop);
        }
        else if (komenda=="wypisz") {
            wypisz(stackTop);
        }
    }

    plik.close();
    wyczysc(stackTop, stackSize); //usuwanie stosu
    return 0;
}
