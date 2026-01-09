#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

class Lista{
public:
    Node* head;
    //tu wpisac funkcje do wypisywania tylem

    Lista() : head(nullptr) {}

    ~Lista() {
        wyczysc();
    }

    //funkcja do pobierania rozmiaru
    int size() const{
        int count=0;
        Node* current = head;
        while(current!=nullptr){
            count++;
            current=current->next;
        }
        return count;
    }
    //tu pozostałe metody
        //dodawanie
    void dodaj(int val){
        Node* newNode = new Node(val);

        //sprawdzamy czy lista jest pusta
        if(head==nullptr){
            head = newNode;
            return;
        }
        //szukanie ostatniego węzła
        Node* current = head;
        while(current->next!=nullptr){
            current=current->next;
            }

        //podłączenie nowego węzła
        current->next=newNode;
    }
        //wypisz
    void wypisz()const{
        Node* current = head;
        while(current!=nullptr){
            cout<<"["<<setw(3)<<current->data<<"]";
            current=current->next;
        }
        cout<<endl;
    }

        //wstawianie
    bool wstawianie(int val, int pos){
        if (pos<0|| pos>size()){
            cerr<<"Bład: Pozycja poza zakresem."<<endl;
            return false;
        }
        Node *newNode = new Node(val);
        //wstawianie na początku
        if (pos==0){
            newNode->next=head;
            head=newNode;
            return true;
        }
        //wstawianie w srodku/nakoncu
        Node *current = head;
        for (int i=0; i<pos-1; i++){
            current=current->next;
        }
        //przekierowanie wskaznikow
        newNode->next=current->next;
        current->next=newNode;
        return true;
    }

    bool usun(int poz) {
        //sprawdzamy czy pozycja istnieje
        if (head==nullptr||poz<0||poz>=size()) {
            cout<<"Nie ma takiej pozycji";
            return false;
        }
        //wskaźnik na element ktory chcemy skasowav

        Node * toDelete=nullptr;

        //usuwamy pierwszy element
        if (poz==0) {
            toDelete=head;
            head=head->next;
        }
        //dla reszty
        else {
            Node *poprzedni = head;
            for (int i=0; i<poz-1; i++) {
                poprzedni=poprzedni->next;
            }
            toDelete=poprzedni->next;
            poprzedni->next=toDelete->next;  //omijamy toDelete i łączymy poprzedni z next
        }

        delete toDelete;
        return true;
    }

    void wyczysc() {
        Node* current = head;
        while(current!=nullptr) {
            Node * nextNode=current->next; //musi widziec kolejny wagon
            delete current;  //usuwa terazniejszy
            current=nextNode; //przeskakuje do nastepnego ktory zapamietal
        }
        head=nullptr;
    }

    void wypisz_odwrotnie(Node *head) {
        if (!head) return;

        wypisz_odwrotnie(head->next);
        cout <<  "["<<setw(3)<<head->data<<"]" ;
    }

    void wypisz_odwrotnie_brutalnie() const {
        int n = size();
        for (int i = n - 1; i >= 0; i--) {
            Node* current = head;
            // Za każdym razem idziemy od początku do pozycji i
            for (int j = 0; j < i; j++) {
                current = current->next;
            }
            cout << "[" << setw(3) << current->data << "] ";
        }
        cout << endl;
    }

    void wypisz_odwrotnie_iteracyjnie() const {
        vector<int> pomocnik;
        Node* current = head;

        // 1. Przepisujemy wszystko do wektora
        while (current != nullptr) {
            pomocnik.push_back(current->data);
            current = current->next;
        }

        // 2. Wypisujemy wektor od końca
        for (int i = pomocnik.size() - 1; i >= 0; i--) {
            cout << "[" << setw(3) << pomocnik[i] << "] ";
        }
        cout << endl;
    }

    void zamien(int poz1, int poz2) {

        Node* current = head;

    }

};


int main(){

    ifstream plik("lista_10.txt");
    if (!plik.is_open()){
        cout<<"Nie można otworzyć pliku "<<"lista_10.txt"<<endl;
        return 0;
    }

    Lista lista;
    string linia;

    while (getline(plik, linia)){
        stringstream ss(linia);
        string komenda;
        ss>>komenda;
        cout<<"komenda: "<<linia<<endl;

        if (komenda=="dodaj"){
            int war;
            if (ss>>war){
                lista.dodaj(war);
            }
        }
        else if (komenda=="wypisz"){
            cout<<"Lista: ";
            lista.wypisz();
        }
        else if (komenda=="wstaw"){
            int war, poz;
            if (ss>>war&&ss>>poz){
                lista.wstawianie(war, poz);
            }
        }
        else if (komenda=="usun") {
            int poz;
            if (ss>>poz) {
                lista.usun(poz);
            }
        }
        else if (komenda=="wyczysc") {
            lista.wyczysc();
        }
        else if (komenda=="wypisz_odwrotnie") {
            lista.wypisz_odwrotnie(lista.head);
        }
        else{
            cout<<"Nieznana komenda!";
        }
    }
    //if (argc !=2){
      //  cout<<"Użycie: "<<argv[0]<<"lista_10.txt"<<endl;
       // return 1;
    //}
   // processCommands(argv[1]);

    return 0;
}
