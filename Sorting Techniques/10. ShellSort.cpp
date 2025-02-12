#include <bits/stdc++.h>
using namespace std;

void shellSort(int A[], int n){              // Time - O(nlogn) | Space - O(1)
    for(int gap = n/2; gap>=1; gap/=2){
        for(int i=gap; i<n; i++){
            int temp = A[i];
            int j = i-gap;
            while(j>=0 && A[j]>temp){
                A[j+gap] = A[j];
                j -= gap;
            }
            A[j+gap] = temp;
        }
    }
}

int main() {
    int A[] = {5,7,9,5,1,52,14,52,2,8};
    shellSort(A, 10);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";

    return 0;
}
