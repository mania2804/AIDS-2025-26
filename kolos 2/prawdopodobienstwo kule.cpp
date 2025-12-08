#include <iostream>
#include <cstdlib>

using namespace std;

enum class Priorytet {
    czarne,
    biale,
    zielone,
    szare,
    niebieskie
};



Priorytet *priorytety (int n) {
    Priorytet *tab=new Priorytet[n];
    int czarne=50;
    int biale=czarne+30;
    int zielone=biale+20;
    int szare=zielone+10;
    int niebieskie= szare+10;
    srand(time(0));
    for (int i=0; i<n; i++) {
        int losowa_liczba=rand()%120+1;
        if (losowa_liczba<=czarne)
            tab[i]=Priorytet::czarne;
        else if (losowa_liczba<=biale)
            tab[i]=Priorytet::biale;
        else if (losowa_liczba<=zielone)
            tab[i]=Priorytet::zielone;
        else if(losowa_liczba<=szare)
            tab[i]=Priorytet::szare;
        else if (losowa_liczba<=niebieskie)
            tab[i]=Priorytet::niebieskie;
    }
    return tab;
}

int main() {

    int n=2;


    Priorytet *wynik=priorytety(n);
    for (int i=0; i<n; i++) {
        switch (wynik[i]) {
            case Priorytet::czarne:
                cout<<"czarna kula ";
                break;
            case Priorytet::biale:
                cout<<"biala kula ";
                break;
            case Priorytet::zielone:
                cout<<"zielona kula ";
                break;
            case Priorytet::szare:
                cout<<"szara kula ";
                break;
            case Priorytet::niebieskie:
                cout<<"niebieska kula ";
                break;
        }
    }
    delete[] wynik;
    return 0;
}