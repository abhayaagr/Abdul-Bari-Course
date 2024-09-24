#include <iostream>
using namespace std;

int normal(int n){
    if(n>0){
        return normal(n-1)+n;
    }
    return 0;
}

int stat(int n){
    int static st = 0;
    if(n>0){
        st++;
        return stat(n-1)+st;
    }
    return 0;
}

int g = 0;
int global(int n){
    if(n>0){
        g++;
        return global(n-1)+g;
    }
    return 0;
}

int main()
{
    int a=5;
    cout<<"Normal output : "<<normal(a);
    cout<<endl;
    cout<<"Static output : "<<stat(a);
    cout<<endl;
    cout<<"Global output : "<<global(a);

    return 0;
}
