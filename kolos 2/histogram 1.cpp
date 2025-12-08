#include <iostream>
#include <iomanip>

int *histogram_wagi(Pacjent *pacjenci, int n, int bin) {
    int max=0;
    for (int i=0; i<n;i++) {
        if (max<pacjenci->waga)
            max=pacjenci->waga;
    }
    int min=0;
    for (int i=0; i<n;i++) {
        if (min>pacjenci->waga)
            min=pacjenci->waga;
    }
    int *histogram=new int[bin]{};

    for (int i=0; i<n; i++) {
        histogram[pacjenci[i].waga-min]++;
    }
    return histogram;
}
