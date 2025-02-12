#include <bits/stdc++.h>
using namespace std;

int partition(int A[], int l, int h){       
    int pivot = A[l];
    int i = l, j = h;
    
    do{
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);
        if(i<j)
            swap(A[i], A[j]);
    }while(i<j);
    swap(A[l], A[j]);
    return j;
}

void quickSort(int A[], int l, int h){      // Time - O(nlogn) | Space - O(logn)
    int j;
    if(l<h){
        j = partition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j+1, h);
    }
}

int main() {
    int A[] = {5,7,9,5,1,52,14,52,2,8,INT_MAX};
    quickSort(A, 0, 10);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";

    return 0;
}
