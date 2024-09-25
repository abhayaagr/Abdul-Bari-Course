#include <iostream>
using namespace std;

int main()
{
    int A[5] = {2,4,6,8,10};    //Static Array
    int *p;
    p = new int[5];             //Dynamic Array
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    p[3] = 7;
    p[4] = 9;
    
    for(int i=0;i<5;i++){
        cout<<A[i]<<" "<<i[A]<<" "<<*(A+i)<<"   ";      //Different methods of accessing
    }
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<p[i]<<" ";
    }
    
    return 0;
}
