#include <iostream>
using namespace std;

int sum_recursion(int n){    //Time Complexity - O(n)
    if(n==0){                //Space Complexity - O(n)
        return 0;
    }
    else{
        return sum_recursion(n-1) + n;
    }
}

int sum_loops(int n){        //Time Complexity - O(n)
    int sum=0;               //Space Complexity - O(1)
    for(int i=1;i<=n;i++){
        sum += i;
    }
    return sum;
}

int sum_formula(int n){        //Time Complexity - O(1)  --> Best approach
    return n*(n+1)/2;          //Space Complexity - O(1)
}

int main()
{
    int x = 7;
    cout<<"Sum using recursion: "<<sum_recursion(x)<<endl;
    cout<<"Sum using loops: "<<sum_loops(x)<<endl;
    cout<<"Sum using formula: "<<sum_formula(x)<<endl;
    
    return 0;
}
