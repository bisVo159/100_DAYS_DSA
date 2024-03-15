#include<iostream>
 #include<cmath>
using namespace std;

  int getBase(int n){
        long int base=1;
        while(n>0){
            n=n/10;
            base=base*10;
        }
        return base/10;
    }
    int countDigitOne(int n,int base){
        if(n==0)
        return 0;
        if(n<10)
        return 1;

        int b=getBase(n%base);
        int oneInBase=(n/base==1)?(n-base+1):base;

        return (n/base)*countDigitOne(base-1,base/10)+oneInBase+countDigitOne(n%base,b);
    }

int main(){
    // 233. Number of Digit One
        int n=1011;
         int base=getBase(n);

        cout<<"Number of 1 in "<<n<<" : "<<countDigitOne(n,base)<<endl;
    return 0;
}