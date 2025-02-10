#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int A[], int n){        // Time - O(n^2) | Space - O(1)
    bool flag;
    for(int i=0;i<n-1;i++){
        flag = 1;
        for(int j=0;j<n-1-i;j++){
            if(A[j] > A[j+1]){
                flag = 0;
                swap(A[j], A[j+1]);
            }
        }
        if(flag)    break;
    }
}

int main() {
    int A[] = {5,7,9,5,1,52,14,52,2,8};
    bubbleSort(A,10);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";

    return 0;
}
