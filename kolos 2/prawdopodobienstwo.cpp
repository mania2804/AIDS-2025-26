#include <iostream>
#include <cstdlib>

using namespace std;

enum class Priorytet(int n) {
    Zielony,
    Zolty,
    Czerwony
};
Priorytet *priorytety(int n) {
    Priorytet *tablica=new Priorytet[n];
    int zielony=50;
    int zolty=zielony+30;
    int czerwony=zolty+10;

    srand(time(0));

    for (int i=0; i<n; i++) {
        int losowa_liczba=rand()%100+1;
        if (losowa_liczba<=zielony)
            tablica[i]=Priorytet::Zielony;
        else if (losowa_liczba<=zolty)
            tablica[i]=Priorytet::Zolty;
        else if (losowa_liczba<=czerwony)
            tablica[i]=Priorytet::Czerwony;
    }

    return tablica;
}