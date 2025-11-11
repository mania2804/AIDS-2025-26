
#include <iostream>
#include <cstring>

using namespace std;

char *male_litery(const char* tekst, int n){
       char* wynik = new char[n+1];
       
       for(int i=0; i<n; i++){
           char c=tekst[i];
           if(c>= 'A'&&c<='Z')
           wynik[i]=c+('a'-'A');
           else
           wynik[i]=c;
       }
       
        wynik[n] = '\0';
        return wynik;
   }

int main()
{
   const char* tekst= "Jak sie masz ";
   
   int n=strlen(tekst);
   
   char* wynik = male_litery(tekst, n);
   cout<<wynik<<endl;
   
   delete[] wynik;
   
    return 0;
}
