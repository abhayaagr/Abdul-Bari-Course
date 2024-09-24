#include <iostream>
using namespace std;

int fib_recursion(int n){          //Time Complexity - O(2^n)
    if(n <= 1)                     //Space Complexity - O(n)
        return n;
    return fib_recursion(n-2) + fib_recursion(n-1);
}

int fib_loops(int n){              //Time Complexity - O(n)
    int t0 = 0, t1 = 1, s;         //Space Complexity - O(1)
    if(n<=1)
        return n;
    for(int i = 2;i<=n;i++){
        s = t0+t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int F[10];  //Global Array to store results --> MEMOIZATION
int fib_recursion_optimized(int n){    //Time Complexity - O(n)
    if(n<=1){                          //Space Complexity - O(n)
        F[n] = n;
        return n;
    }
    else{
        if(F[n-2] == -1)
            F[n-2] = fib_recursion_optimized(n-2);
        if(F[n-1] == -1)
            F[n-1] = fib_recursion_optimized(n-1);
        F[n] = F[n-2] + F[n-1];
        return F[n];
    }
}

int main()
{
    for(int i=0;i<10;i++){      //Initialisation of global array with -1
        F[i] = -1;
    }
    
    int n = 10;
    cout<<"Fibonacci using recursion: "<<fib_recursion(n)<<endl;
    cout<<"Fibonacci using loops: "<<fib_loops(n)<<endl;
    cout<<"Fibonacci using recursion optimized: "<<fib_recursion_optimized(n)<<endl;
    return 0;
}
