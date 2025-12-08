#include <iostream>
#include <string>

using namespace std;
struct Pacjent {
    string nazwisko;
    int waga;
};
string tab[6]={"ski","ska","wski","wska","cki","cka"};
bool szukanie( string nazwisko) {
    int a=0;
    for (int j=0; j<6;  j++) {
        int b=tab[0].size();
        for(int i=0; i<nazwisko.size(); i++) {
            // cout<<i<<" "<<nazwisko[i]<<"  "<<tab[j][a]<<endl;
            if(nazwisko[i]==tab[j][a])
                a++;
            else
                a=0;
            if (a==b) {
                return true;
            }

        }
    }
    return false;
}
    int policz_wyrazy(const Pacjent *pacjenci, int n) {
        int licznik=0;
        for (int i=0; i<sizeof(pacjenci)/sizeof(pacjenci[0]); i++) {
            if (szukanie(pacjenci->nazwisko))
                licznik++;
        }
        return licznik;
    }

    int main(){

        cout<<szukanie("Kowalski");




        return 0;
    }