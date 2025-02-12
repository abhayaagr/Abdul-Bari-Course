#include <bits/stdc++.h>
using namespace std;

void merge(int A[], int l, int mid, int h){       
    int i, j, k;
    i = l;
    j = mid+1;
    k = l;
    vector<int> v;
    while(i<=mid && j<=h){
        if(A[i] < A[j])
            v.push_back(A[i++]);
        else
            v.push_back(A[j++]);
    }
    while(i<=mid)
        v.push_back(A[i++]);
    while(j<=h)
        v.push_back(A[j++]);
    
    for(i=0; i<v.size(); i++){
        A[l++] = v[i];
    }
}

void mergeSort(int A[], int l, int h){      // Time - O(nlogn) | Space - O(n)
    if(l<h){
        int mid = (l+h)/2;
        mergeSort(A, l, mid);
        mergeSort(A, mid+1, h);
        merge(A, l, mid, h);
    }
}

int main() {
    int A[] = {5,7,9,5,1,52,14,52,2,8};
    mergeSort(A, 0, 9);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";

    return 0;
}
