//chodzi o poprawienie kontrastu na obrazku
//wyliczyc dystrybuantę
//wzor  z wikipedii

//p5 jest bajtowy i chodzi o to zeby bylo 12 bajtow  w pliku bo dla p2 czyta tez spacje w ascii
//wczytujemy obrazek plik.get()  lub plik.put()




#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
    string rodzaj;
    fstream plik("9.pgm");
    plik>>rodzaj;
    cout<<rodzaj<<endl;
    int  wymiar1, wymiar2,zakres;
    plik>>wymiar1>>wymiar2>>zakres;
    cout<<wymiar1<<" "<<wymiar2<<endl;
    cout<<zakres<<endl;


    int rozmiar=wymiar1*wymiar2;
    char **tab=new char *[rozmiar];

    for (int i=0; i<wymiar1; i++) {
        tab[i]=new char[wymiar2];
    }

    for (int i=0; i<wymiar1; i++) {
        for (int j=0; j<wymiar2; j++) {
            tab[i][j]=plik.get();
        }
    }
    for (int i=0; i<wymiar1; i++) {
        for (int j=0; j<wymiar2; j++) {
            cout<<tab[i][j]<<" ";
        }
    }


    for (int i=0; i<wymiar1; i++) {
        delete[] tab[i];
    }
    delete []tab;
    return 0;
}
