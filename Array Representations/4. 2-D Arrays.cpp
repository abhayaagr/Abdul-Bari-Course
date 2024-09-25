#include <iostream>
using namespace std;

int main()
{
    int A[3][4] = {{1,2,3,4},{2,4,6,8},{3,5,7,9}};      //Everything in stack
    
    int *B[3];                    //Pointer array in stack, rest in heap
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];
    
    int **C;                      //Single pointer in stack, rest in heap
    C = new int*[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];
    
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<A[i][j]<<" ";
            B[i][j] = A[i][j] + 10;
            C[i][j] = A[i][j] + 20;
        }
        cout<<endl;
    }
    
    cout<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
