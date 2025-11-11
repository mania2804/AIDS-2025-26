
#include <iostream>
#include <cstring>

using namespace std;



int main()
{
  
  
    int a, b;
    cin>>a>>b;
    int *tab=new int[b-a+1];
    if(a>=0&&a<b){
        int liczba=a;
        for(int i=0;i<=b-a; i++){
        tab[i]=liczba++;  
        cout<<tab[i]<<" ";
        }
        
        double srednia=0, suma=0;
        int licznik=0;
        for(int i=0; i<=b-a; i++){
            if(tab[i]%3==0||tab[i]%5==0){
                suma+=tab[i];
                licznik++;
            }
            
        }
        srednia=suma/licznik;
        cout<<"srednia: "<<srednia;
    }
  
    
    
    
    else if(a<0)
        cout<<"Liczba a musi być nie ujemna";
    else if(a>=b)
        cout<<"Liczba a musi byc mniejsza od b";
  
  
  
  delete[] tab; 
    return 0;
}
