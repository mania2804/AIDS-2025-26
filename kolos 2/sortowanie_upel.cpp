#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

void bubble(int *tab, int n) {
    for ( int i=0; i<n; i++) {
        for (int j=0; j<n-1; j++) {
            if (tab[j]>tab[j+1]) {
                int temp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
            }
        }
    }
}

void selection(int *tab, int n) {    //wybieranie
    for (int i=0; i<n; i++) {
        int max_lok=i;
        for (int j=i+1; j<n; j++) {
            if (tab[j]<tab[max_lok]) {
                max_lok=j;
            }
        }
        int temp=tab[i];
        tab[i]=tab[max_lok];
        tab[max_lok]=temp;
    }
}
void insertion(int *tab, int n) {  //wstawianie
    for (int i=0; i<n; i++) {
        int temp=tab[i];
        int j=i-1;
        while (j>=0 && tab[j]>temp) {
            tab[j+1]=tab[j];
            j--;
        }
    tab[j+1]=temp;
    }
}

void merge(int*tab, int left, int mid, int right) {  //scalanie
    //dzielimy na 2 podtablice
    int n1=mid-left +1;
    int n2=right-mid;

    int L[n1],R[n2];
    for (int i=0; i<n1; i++) {
        L[i]=tab[left+i];
    }
    for (int i=0; i<n2; i++) {
        R[i]=tab[mid+1+i];
    }


}
void kopcowanie(int *tab, int n) {

}


void quick(int *tab, int n, int p, int q) {
    int left =p;
    int right =q;
    int pivot=(p+q)/2;

    do


}
void wypisz(int *tab, int n) {
    for (int i=0; i<n; i++) {
        cout<<tab[i]<<endl;
    }
}

int main() {


    ifstream plik("plik_10.txt");
    if (!plik.is_open()) {
        cout<<"Nie można otworzyć pliku";
        return -1;
    }
    int n;
    plik>>n;

    int *tab=new int[n];
    for (int i=0; i<n; i++) {
        plik>>tab[i];
    }
    plik.close();

    string wybor;
    cout<<"wybor: ";
    cin>>wybor;

    if (wybor=="bubble") {
        bubble(tab, n);
    }
    else if (wybor=="selection") {
        selection(tab, n);
    }
    else if (wybor=="insertion") {
        insertion(tab, n);
    }
    else if (wybor=="kopcowanie") {
        kopcowanie(tab, n);
    }
    else if (wybor=="merge") {
        merge(tab, n);
    }
    else if (wybor=="quick") {
        int p=0;
        int q=0;
        quick(tab, n, p, q);
    }

    wypisz(tab, n);


    delete []tab;
    return 0;
}