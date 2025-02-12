#include <bits/stdc++.h>
using namespace std;

int findMax(int A[], int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        if(A[i] > maxi)
            maxi = A[i];
    }
    return maxi;
}

void countSort(int A[], int n){      // Time - O(n) | Space - O(INT_MAX)
    int max = findMax(A,n);
    int *c = new int[max+1];
    for(int i=0;i<max+1;i++){
        c[i] = 0;
    }
    for(int i=0;i<n;i++){
        c[A[i]]++;
    }
    int i=0, j=0;
    while(i<max+1){
        if(c[i]){
            A[j++] = i;
            c[i]--;
        }
        else
            i++;
    }
}

int main() {
    int A[] = {5,7,9,5,1,52,14,52,2,8};
    countSort(A, 10);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";

    return 0;
}
