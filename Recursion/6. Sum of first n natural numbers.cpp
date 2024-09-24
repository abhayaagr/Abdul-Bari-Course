#include <iostream>
using namespace std;

int sum_recursion(int n){
    if(n==0){
        return 0;
    }
    else{
        return sum_recursion(n-1) + n;
    }
}

int sum_loops(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum += i;
    }
    return sum;
}

int sum_formula(int n){
    return n*(n+1)/2;
}

int main()
{
    int x = 7;
    cout<<"Sum using recursion: "<<sum_recursion(x)<<endl;
    cout<<"Sum using loops: "<<sum_loops(x)<<endl;
    cout<<"Sum using formula: "<<sum_formula(x)<<endl;
    
    return 0;
}
