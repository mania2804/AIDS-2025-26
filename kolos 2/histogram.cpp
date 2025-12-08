//chodzi o poprawienie kontrastu na obrazku
//wyliczyc dystrybuantę
//wzor  z wikipedii

//p5 jest bajtowy i chodzi o to zeby bylo 12 bajtow  w pliku bo dla p2 czyta tez spacje w ascii
//wczytujemy obrazek plik.get()  lub plik.put()




#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;


int main() {
    string rodzaj;
    fstream plik("9.pgm");
    plik>>rodzaj;
    cout<<rodzaj<<endl;
    int  szer, wys,zakres;
    plik>>szer>>wys>>zakres;
    cout<<szer<<" "<<wys<<endl;
    cout<<zakres<<endl;
    plik.ignore();   //pomijamy znak nowej linii

    int rozmiar=szer*wys;
    unsigned char **tab=new unsigned char *[wys];

    for (int i=0; i<wys; i++) {
        tab[i]=new unsigned char[szer];
    }

    for (int i=0; i<wys; i++) {
        for (int j=0; j<szer; j++) {
            tab[i][j]=plik.get();
        }
    }
    // for (int i=0; i<szer; i++) {
    //     for (int j=0; j<wys; j++) {
    //         cout<<int(tab[i][j])<<" ";   //rzutowanie na inta
    //     }
    // }

    //tworzenie histogramu
    //{}powoduje wypelnienie zerami
    int histogram[255]{};

//przechodzimy przez tab i tworzymy histogram
    for(int i=0; i<wys; i++){
        for (int j=0; j<szer; j++){
            histogram[(int)tab[i][j]]++;
        }
    }

//dystrybuanta
    int dystrybua[256]{};
    int suma=0;
    for(int i=0; i<256; i++){
        suma+=histogram[i];
        dystrybua[i]=suma;
    }

//szukamy pierwszej niezerwoej wartosci
    int min_dyst =0;
    for(int i=0; i<256; i++){
        if(dystrybua[i]>0){
            min_dyst=i;
            break;
        }
    }

//dla kazdego poziomu intensywnisci i obliczamy nowa wartosc która rozciagnie dystrybuante i wyrówna histogram

    int size=szer*wys;
    unsigned char newValues[256]{};
    for(int i=0; i<256; i++)
        newValues[i]=int(round (255.f *(dystrybua[i]-min_dyst)/(size-min_dyst)));

    //aktualizujemy obraz
    for(int i=0; i<wys; i++){
        for(int j=0; j<szer; j++){
            tab[i][j] = newValues[tab[i][j]];
        }
    }

//zapisujemy nowy obraz do pliku

    ofstream file("9_out1.pgm",ios::binary);

    file<<rodzaj <<endl;
    file<<szer<<" "<<wys<<" "<<endl;
    file<<zakres<<endl;

    for(int sz=0; sz<wys; sz++){
        for(int w=0; w<szer; w++){
            file.put(tab[sz][w]);
        }
    }



    plik.close();
    file.close();

    for (int i=0; i<wys; i++) {
        delete[] tab[i];
    }
    delete []tab;
    return 0;
}