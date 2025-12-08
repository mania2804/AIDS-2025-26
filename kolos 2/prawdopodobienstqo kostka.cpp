#include <iostream>
#include <cstdlib>

using namespace std;

enum class Priorytet {
    j_kropka,
    d_kropka,
    t_kropka,
    cz_kropka,
    p_kropka,
    sz_kropka
};



Priorytet *priorytety (int n) {
    Priorytet *tab=new Priorytet[n];
    int jeden=40;
    int dwa=jeden+10;
    int trzy=dwa+10;
    int pięć=trzy+30;
    int szesc= pięć+10;
    srand(time(0));
    for (int i=0; i<n; i++) {
        int losowa_liczba=rand()%100+1;
        if (losowa_liczba<=jeden)
            tab[i]=Priorytet::j_kropka;
        else if (losowa_liczba<=dwa)
            tab[i]=Priorytet::d_kropka;
        else if (losowa_liczba<=trzy)
            tab[i]=Priorytet::t_kropka;
        else if(losowa_liczba<=pięć)
            tab[i]=Priorytet::p_kropka;
        else if (losowa_liczba<=szesc)
            tab[i]=Priorytet::sz_kropka;
    }
    return tab;
}

int main() {

    int n;
    cin>>n;

    Priorytet *wynik=priorytety(n);
     for (int i=0; i<n; i++) {
         switch (wynik[i]) {
             case Priorytet::j_kropka:
                 cout<<"jedna kropka"<<endl;
            break;
            case Priorytet::d_kropka:
                cout<<"dwie kropki"<<endl;
            break;
            case Priorytet::t_kropka:
                cout<<"trzy kropki"<<endl;
            break;
            case Priorytet::cz_kropka:
                 cout<<"Cztery kropki"<<endl;
            break;
            case Priorytet::p_kropka:
                 cout<<"piec kropek"<<endl;
            break;
             case Priorytet::sz_kropka:
                 cout<<"szesc kropek"<<endl;
            break;
         }
     }
    delete[] wynik;
    return 0;
}