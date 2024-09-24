#include <iostream>
using namespace std;

double e(int m, int n){                    //Time Complexity - O(n)
    static double p = 1, f = 1;            //Space Complexity - O(n)
    if(n==0)
        return 1;
    double r = e(m, n-1);
    p *= m;
    f *= n;
    return r + p/f;
}

double ehl(int m, int n){                  //Time Complexity - O(n)
    double s = 1;                          //Space Complexity - O(1)
    while(n>0){
        s = 1 + (double(m)/double(n))*s;    // 1+m*s/n will not need typecasting
        n--;
    }
    return s;
}

double ehr(int m,int n){                   //Time Complexity - O(n)
    double static r = 1;                   //Space Complexity - O(n)
    if(n==0){                              //But number of multiplications reduced from O(n^2) to O(n)
        return 1;
    }
    r = 1 + double(m)/double(n)*r;
    ehr(m,n-1);
    return r;
}

int main()
{
    int m = 1;
    int n = 20;
    cout<<"Using recursion: "<<e(m,n)<<endl; // Value of e^m using n terms of taylor series
    cout<<"Using horner's rule loops: "<<ehl(m,n)<<endl; 
    cout<<"Using horner's rule recursion: "<<ehr(m,n)<<endl;
    return 0;
}
