#include <iostream>
using namespace std;

void funB(int n);  //Declaration

void funA(int n){
    if(n>0){
        cout<<n;
        funB(n-1);
    }
}

void funB(int n){  //Defination
    if(n>1){
        cout<<n;
        funA(n/2);
    }
}


int main()
{
    int x = 20;
    funA(x);

    return 0;
}

// Output - 20 19 9 8 4 3 1