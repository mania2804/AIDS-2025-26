#include<iostream>
#include <iomanip>
using namespace std;

float wynik_potega(float arg, int w) {
    float potega = 1;
    for (int i = 0; i < w; i++) {
        potega *= arg;
    }
    return potega;
}

float wartosc_funkcji(int x[], float arg) {
    float suma = 0;
    for (int i = 0; i <= sizeof(x) / sizeof(x[0]); i++) {
        //tak ma byc bo sizeof bierze bajty a nie rozmiar tablicy xD
        suma += x[i] * wynik_potega(arg, i);
    }

    return suma;
    //x[0]*arg^0+x[1]*arg^1+x[2]*arg^2;
}

float bisekcja(float a, float b, int x[], float dokladnosc=0.001) {
    float polowa = (a + b) / 2;
    float war = wartosc_funkcji(x, polowa);

    if ((b-a)<dokladnosc) {
        return polowa;
    }

    float war_polowa=wartosc_funkcji(x, polowa);
    float war_a=wartosc_funkcji(x, a);
    if (war_a*war_polowa  < 0) {
        return bisekcja(a, polowa,x , dokladnosc);
    } else
        return bisekcja(polowa, b, x , dokladnosc);

    return bisekcja(a, b, x);
}




int main() {
    float a = -10;
    float b = 10;;

    //x^2+2x+1
    int n =1;
    int arg = 2;
    // int w = 3;
    int x[n+1] = {1,2};

    // cout << wynik_potega(arg, w) << endl;
    // cout << wartosc_funkcji(x, arg);

    cout<<fixed <<setprecision(3)<<bisekcja(a,b,x);
    return 0;
}
