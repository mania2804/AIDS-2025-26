#include <iostream>
#include<iomanip>
#include <string>
#include <fstream>
using namespace std;

bool sprawdzacz(string z, string s ) {
    int temp=0;
    int sizes=s.length();
    //cout<<sizes<<endl;

    for (int i=0; i<z.length(); i++) {
       // cout<<z[i]<<s[temp]<<i<<temp<<sizes<<endl;
        if (z[i]==s[temp])
            temp++;
        else
            temp=0;
        if (temp==sizes)
            return true;
    }
    return false;

}


int main(int argc, char* argv[]) {

    int ile_arg=argc;
    
    fstream plik("lokomotywa.txt");
    if (!plik.is_open()) {
        cout << "Nie udalo sie otworzyc pliku!" << endl;
        return 1;
    }
    
    string linia;
    string caly_tekst;
    
    while (getline(plik, linia)){
        caly_tekst += linia ;
    }
    
    plik.close();


    string szukane = argv[1];
    
    bool check= sprawdzacz(caly_tekst, szukane);
    cout<<szukane<<endl;

    if (check == true) {
        cout<<"Znaleziono slowo";
    }
    else {
        cout<<"nie znaleziono slowa";
    }

    return 0;

}
