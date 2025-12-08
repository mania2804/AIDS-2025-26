#include <iostream>
#include <cstdlib>

using namespace std;
bool wyszukiwanie (Pacjent*pacjenci, int n, string nazwisko){
    int lewy=0;
    int prawy=n-1;

    return szukaj_binarnie(pacjenci, lewy, prawy, nazwisko);
}
bool szukaj_binarnie(Pacjent * pacjenci, int lewy, int prawy, string surname ){
    int polowa = (lewy+prawy)/2
    if(prawy<lewy)
        return false;

    if(nazwisko==pacjenci[polowa].nazwisko)
        return true;
    else if(nazwisko>pacjenci[polowa].nazwisko)
        return szukaj_binarnie(pacjenci,polowa, prawy , nazwisko);
    else
        return szukaj_binarnie(pacjenci, lewy, polowa, nazwisko);
}
int main(){




    return 0;
}
