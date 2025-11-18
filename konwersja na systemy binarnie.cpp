#include <iostream>

using namespace std;

string dwojkowy(int n){
    if(n==0)
    return "0";
    if(n==1)
    return "1";
   
    return dwojkowy(n/2)+ to_string(n%2);
}

string piatkowy(int n){
    if(n==0)
    return "0";
    if(n<5) 
    return to_string(n);
    
    return piatkowy(n/5)+ to_string(n%5);
}

string siodemkowy(int n){
    if(n==0)
    return "0";
    if(n<7) 
    return to_string(n);
    
    return siodemkowy(n/7)+ to_string(n%7);
}

string osemkowy(int n){
    if(n==0)
    return "0";
    if(n<8) 
    return to_string(n);
    
    return osemkowy(n/8)+ to_string(n%8);
}

string szestnastkowy(int n){
    if(n==0)
    return "0";
    if(n<16) 
    return 
    
}


int main(){
    
    int n;
    
    cin>>n;
    
    cout<<"Binarnie: "<<dwojkowy(n)<<endl;
    cout<<"Piątkowo: "<<piatkowy(n)<<endl;
    cout<<"Siódemkowo: "<<siodemkowy(n)<<endl;
    cout<<"Ósemkowo: "<<osemkowy(n)<<endl;
    cout<<"Szesnastkowo: "<<szestnastkowy(n)<<endl;
    
    return 0; 
}
