#include <iostream>
#include <string>
#include <iomanip>

struct Pacjent {
    int waga;
    // inne pola struktury Pacjent
};
using namespace std;
void sortowanie2 (Pacjent*pacjenci, int p, int q){
    int left=p;
    int right=q;
    int polowa=(p+q)/2;
    int pivot=pacjenci[polowa].waga;

    do
    {
        while(pacjenci[left].waga<pivot)left++;
        while(pacjenci[right].waga>pivot)right--;

        if(left<=right)
         {
            int temp=pacjenci[left].waga;
            pacjenci[left].waga=pacjenci[right].waga;
            pacjenci[right].waga=temp;
            left++;
            right--;
           }
	}while(left<=right);

	if(q>left) sortowanie2(pacjenci, left, q);
	if (p<right) sortowanie2(pacjenci, p, right);
}
void bubble(Pacjent*pacjenci, int n) {
    for (int i=0;i<n;i++) {
        for (int j=0; j<n-1; j++) {
            if (pacjenci[j].waga>pacjenci[j+1].waga) {
                int temp=pacjenci[j].waga;
                pacjenci[j].waga=pacjenci[j+1].waga;
                pacjenci[j+1].waga=temp;
            }
        }
    }
}
void sortowanie(Pacjent *pacjenci, int n){
    //sortowanie2(pacjenci,0,n-1);
    bubble(pacjenci, n);
}

int main() {
    Pacjent pacjenci[] = {{60}, {50}, {90}, {70}, {80}, {55}};
    int n = sizeof(pacjenci) / sizeof(pacjenci[0]);

    sortowanie(pacjenci, n);

    for (int i = 0; i < n; ++i) {
        cout << pacjenci[i].waga << " ";
    }

    return 0;
}