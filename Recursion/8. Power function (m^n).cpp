#include <iostream>
using namespace std;

int pow_recursion(int m, int n){    //Time Complexity - O(n)
    if(n==0){                       //Space Complexity - O(n)
        return 1;
    }
    else{
        return pow_recursion(m,n-1) * m;
    }
}

int pow_recursion_opt(int m, int n){        //Time Complexity - O(log2(n))
    if(n==0)                                //Space Complexity - O(log2(n))
        return 1;
    if(n%2 == 0)
        return pow_recursion_opt(m*m,(n/2));
    else
        return m * pow_recursion_opt(m*m, (n-1)/2);
}

int pow_loops(int m, int n){                //Time Complexity - O(n)
    int ans=1;                              //Space Complexity - O(1)
    for(int i=1;i<=n;i++){
        ans *= m;
    }
    return ans;
}

int main()
{
    int m = 2;
    int n = 9;
    cout<<"Power using recursion: "<<pow_recursion(m,n)<<endl;
    cout<<"Power using recursion optimized: "<<pow_recursion_opt(m,n)<<endl;
    cout<<"Power using loops: "<<pow_loops(m,n)<<endl;
    return 0;
}
