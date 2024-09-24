#include <iostream>
using namespace std;

int fact(int n){              //Time Complexity - O(n)
    if(n==0){                 //Space Complexity - O(n)
        return 1;
    }
    else{
        return fact(n-1) * n;
    }
}

int ncr_fact(int n, int r){    //Time Complexity - O(n)
    int x = fact(n);           //Space Complexity - O(n)
    int y = fact(r);
    int z = fact(n-r);
    return x/(y*z);     // n!/(r!(n-r)!)
}

int ncr_recursion(int n, int r){      //Time Complexity - O(2^n)
    if(r == 0 || n == r){             //Space Complexity - O(n)
        return 1;
    }
    return ncr_recursion(n-1, r-1) + ncr_recursion(n-1, r);      //nCr = n-1Cr-1 + n-1Cr
}

int main()
{
    int n = 5, r = 3;
    cout<<"nCr using factorial function: "<<ncr_fact(n,r)<<endl;
    cout<<"nCr using recursion (Pascal's triangle): "<<ncr_recursion(n,r);
    return 0;
}
