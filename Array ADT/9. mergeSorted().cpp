#include <iostream>
using namespace std;

int* mergeSorted(int A[], int B[]){      //Time - O(m+n) | Space - O(m+n)
    static int C[10];
    int i=0, j=0, k=0;
    while(i<5 && j<5){
        if(A[i]<B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];    
    }
    for(;i<5;i++)
        C[k++] = A[i];
    for(;j<5;j++)
        C[k++] = B[j];
    return C;
}

int main()
{
    int A[] = {3,8,16,20,25};
    int B[] = {4,10,12,22,23};
    int *C = mergeSorted(A,B);
    for(int i=0;i<10;i++){
        cout<<C[i]<<" ";
    }
    
    return 0;
}
