bool czy_fibo( int n){
     if(n<0)
     return false;
     if(n==0||n==1)
     return true;
     
     int a=0,b=1;
     while(b<n){
         int c=a+b;
         a=b;
         b=c;
     }
    
    
    return (b==n);
}
