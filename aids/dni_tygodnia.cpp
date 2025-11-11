
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
    int n;
    cout<<"Podaj dzień: ";
    cin>>n;
    
    if(n>=1&&n<=7){
        switch(n){
            case 1:
            cout<<"poniedziałek";break;
            case 2:
            cout<<"wtorek";break;
            case 3:
            cout<<"środa";break;
            case 4:
            cout<<"czwartek";break;
            case 5:
            cout<<"piątek";break;
            case 6:
            cout<<"sobota";break;
            case 7:
            cout<<"niedziela";break;
        }
        
    }
    
    else
    cout<<"Dzień musi być w zakresie od 1 do 7";
    return 0;
}
