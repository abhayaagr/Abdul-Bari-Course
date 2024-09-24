#include <iostream>
using namespace std;

int fact_recursion(int n){    //Time Complexity - O(n)
    if(n==0){                 //Space Complexity - O(n)
        return 1;
    }
    else{
        return fact_recursion(n-1) * n;
    }
}

int fact_loops(int n){        //Time Complexity - O(n)
    int ans=1;                //Space Complexity - O(1)
    for(int i=1;i<=n;i++){
        ans *= i;
    }
    return ans;
}

int main()
{
    int x = 5;
    cout<<"Factorial using recursion: "<<fact_recursion(x)<<endl;
    cout<<"Factorial using loops: "<<fact_loops(x)<<endl;

    return 0;
}
