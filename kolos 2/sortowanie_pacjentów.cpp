#include<iostream>
#include <fstream>
#include <vector>
#include<fstream>
#include <string>

using namespace std;

struct Sosnicki {
    string date;
    string hour;
    string pesel;
    string kolorjebany;
    string name;
    string surname;
    int kurwajebanaacyferkajakas;
};

int oblicz_rok_ur(const string& pesel) {
    int rok =  (int(pesel[0]))*10 +(int(pesel[1]));
    return rok + 1900;
}

void bubble(vector<Sosnicki>& kurwy) {
    int n=kurwy.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-1; j++) {
            if (oblicz_rok_ur(kurwy[j].pesel)<oblicz_rok_ur(kurwy[j+1].pesel)) {
                Sosnicki temp=kurwy[j];
                kurwy[j]=kurwy[j+1];
                kurwy[j+1]=temp;
            }
        }
    }
}
void quick(vector<Sosnicki>& kurwy,int p, int q) {

    int n=kurwy.size();
    int left=p;
    int right=q;
    string pivot = kurwy[(p+q)/2].surname;

    do
    {
        while (kurwy[left].surname < pivot) left++;
        while (kurwy[right].surname > pivot) right--;


        if (left<=right)
        {
            string temp = kurwy[left].surname;
            kurwy[left].surname = kurwy[right].surname;
            kurwy[right].surname = temp;
            left++;
            right--;
        }

    } while (left<=right);

    if (q>left) quick(kurwy, left, q);
    if (p<right) quick(kurwy, p, right);
}

//wyszukiwanie binarne

bool search(vector<Sosnicki>& kurwy, string surname, int a, int b) {
    int polowa=(a+b)/2;
    if (surname==kurwy[polowa].surname) return true;
    if ((b-a)==1) return false;
    if (surname<kurwy[polowa].surname) {
        return search(kurwy, surname, a, polowa);
    }
    else return search(kurwy, surname, polowa ,b );

}


int main() {
    ifstream file("triaz_5.txt");
    vector<Sosnicki> kurwy;

    while (!file.eof()) {
        Sosnicki kurwa;
        file >> kurwa.date;

        file >> kurwa.hour;

        file >> kurwa.pesel;

        file >> kurwa.kolorjebany;

        file >> kurwa.name;

        file >> kurwa.surname;

        file >> kurwa.kurwajebanaacyferkajakas;

        kurwy.push_back(kurwa);
    }


    quick(kurwy, 0, kurwy.size()-1);

    for (int i = 0; i < kurwy.size(); i++) {
        // string pesel = kurwy[i].pesel;
        // cout << pesel << " " <<oblicz_rok_ur(pesel)<<" " <<kurwy[i].name<<"\n";

        cout<<kurwy[i].surname<<endl;

    }

    cout<<search(kurwy, "Marysia", 0,  kurwy.size());




    return 0;
}
