#include <bits/stdc++.h>
using namespace std;

void missingUnsorted(int arr[], int n){      // Time - O(n) | Space - O(n)
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i = 0;i<n;i++){
        if(max<arr[i]){
            max = arr[i];
        }
        if(min>arr[i]){
            min = arr[i];
        }
    }
    int temp[max] = {0};
    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }
    for(int i=min;i<max;i++){
        if(temp[i] == 0)
            cout<<i<<" ";
    }
    return;
}

int main() {
    int arr[] = {3,7,4,9,12,6,1,11,2,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    missingUnsorted(arr,n);
    
    return 0;
}
