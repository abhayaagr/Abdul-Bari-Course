#include <bits/stdc++.h>
using namespace std;

void insertionSort(int A[], int n){        // Time - O(n^2) | Space - O(1)
    for(int i=1;i<n;i++){
        int x = A[i];
        int j = i-1;
        while(j>=0 && A[j] > x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main() {
    int A[] = {5,7,9,5,1,52,14,52,2,8};
    insertionSort(A,10);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";

    return 0;
}
