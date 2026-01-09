#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node * next = nullptr;
};

void odloz(Node *&head, string data) {
    Node *nowy = new Node;
    nowy->data = data;
    nowy->next = nullptr;

    if (head == nullptr) {
        head = nowy;
    } else {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nowy;
    }
}

void zdejmij(Node *&head) {
    if (head == nullptr) {
        cout << "Nie ma stosu" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void wypisz(Node *head) {
    if (head == nullptr) {
        cout << "Nie ma stosu" << endl;
        return;
    }
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void rozmiar(Node *head) {
    if (head == nullptr) {
        cout << "Nie ma stosu" << endl;
        return;
    }
    int licznik = 0;
    Node *temp = head;
    while (temp != nullptr) {
        licznik++;
        temp = temp->next;
    }
    cout << licznik << endl;
}

void podejrzyj(Node *head, int n) {
    if (head == nullptr) {
        cout << "Nie ma stosu." << endl;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < n && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Podany indeks jest za duzy." << endl;
    } else {
        cout << temp->data << endl;
    }
}

int main() {
    int n = 0;
    cout << "Podaj n (ktory element stosu chcesz zobaczyc): " << endl;
    cin >> n;

    Node *head = nullptr;

    odloz(head, "ala");
    odloz(head, "dupa");
    odloz(head, "sto");
    odloz(head, "wiewiorka");

    wypisz(head);
    rozmiar(head);
    cout << endl;

    zdejmij(head);
    wypisz(head);
    rozmiar(head);
    cout << endl;

    podejrzyj(head, n);

    return 0;
}
