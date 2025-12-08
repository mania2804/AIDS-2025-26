#include <vector>
#include <iostream>

using namespace std;

void bubble1(int tab[], int n) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7-1; j++) {
            if (tab[j] > tab[j+1]) {
                int temp = tab[j+1];
                tab[j+1] = tab[j];
                tab[j] = temp;
            }
        }
    }
}
//chyba to jest poprawne



//to chyba nie jest bąbelkowe tylko przez wybor
void bubble(int tab[], int n) {
    for (int i = 0; i < 6; i++) {
        for (int j = i; j < 6; j++) {
            if (tab[j] < tab[i]) {
                int temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

void selection(int tab[], int n) {
    for (int i = 0; i < 6; i++) {
        int min_lok = i;
        for (int j = i+1; j < 6; j++) {
            if (tab[j] < tab[min_lok]) {
                min_lok = j;
            }
        }
        int temp=tab[i];
        tab[i]=tab[min_lok];
        tab[min_lok]=temp;
    }
}

void quicksort(int tab[], int p, int q) {
    int left=p;
    int right=q;
    int pivot = (p+q)/2;
    int v = tab[pivot];
    do
    {
        while (tab[p] < v) p++;
        while (tab[q] > v) q--;
        if (p<=q)
        {
            int temp = tab[p];
            tab[p] = tab[q];
            tab[q] = temp;
            p++;
            q--;
        }
    } while (p<=q);
    if (q>left) quicksort(tab, left, q);
    if (p<right) quicksort(tab, p, right);
}

void wypisz(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }
}

int main() {

    int tab[7] = {69, 52, 72, 67, 42, 21, 37};
    int p=0,q=6;
    int n=7;

    //quicksort(tab, p, q);
    bubble1(tab, 7);
    wypisz(tab,7);
    return 0;
}
