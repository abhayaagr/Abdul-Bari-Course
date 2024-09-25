#include <iostream>
using namespace std;

int main()
{
    int *p;
    p = new int[5];    //Initial size of p = 5
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    p[3] = 7;
    p[4] = 9;
    
    int *q = new int[10];      //New array with increased size
    
    for(int i=0;i<5;i++){      //Data of p is copied in q
        q[i] = p[i];
    }
    delete []p;
    p = q;              //Final size of p = 10;
    q = NULL;
    
    return 0;
}
