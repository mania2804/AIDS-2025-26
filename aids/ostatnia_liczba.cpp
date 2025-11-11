
#include <iostream>
#include <cstring>

using namespace std;



int main()
{
  
  
    int a;
    cin>>a;
    if(a>=0){
        int ostatnia=a%10;
        
        switch(ostatnia){
            case 0: cout<<"zero"<<endl;
            break;
            case 1: cout<<"jeden"<<endl;
            break;
            case 2: cout<<"dwa"<<endl;
            break;
            case 3: cout<<"trzy"<<endl;
            break;
            case 4: cout<<"cztery"<<endl;
            break;
            case 5: cout<<"pięć"<<endl;
            break;
            case 6: cout<<"sześć"<<endl;
            break;
            case 7: cout<<"siedem"<<endl;
            break;
            case 8: cout<<"osiem"<<endl;
            break;
            case 9: cout<<"dziewięć"<<endl;
            break;
            
        default:cout<<"Niepoprawna liczba";
        break;
        
        }
    }
        
    else if(a<0)
        cout<<"Liczba a musi być nie ujemna";
   
  
  
  
    return 0;
}
