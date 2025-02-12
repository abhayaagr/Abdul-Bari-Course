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

void mergeSort(int A[], int n){      // Time - O(nlogn) | Space - O(n)
    int p, l, h, mid, i;
    for(p=2; p<=n; p*=2){
        for(i=0; i+p-1<n; i+=p){
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(A,l,mid,h);
        }
    }
    if(p/2 < n){
        merge(A,0,p/2-1,n-1);
    }
}

int main() {
    int A[] = {5,7,9,5,1,52,14,52,2,8};
    mergeSort(A, 10);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";

    return 0;
}
