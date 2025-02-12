#include <bits/stdc++.h>
using namespace std;

void selectionSort(int A[], int n){        // Time - O(n^2) | Space - O(1)
    for(int i=0;i<n-1;i++){
        int k = i;
        for(int j=i; j<n; j++){
            if(A[j] < A[k])
                k = j;
        }
        swap(A[i], A[k]);
    }
}

int main() {
    int A[] = {5,7,9,5,1,52,14,52,2,8};
    selectionSort(A,10);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";

    return 0;
}
