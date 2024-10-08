#include <bits/stdc++.h>
using namespace std;

void duplicatesUnsorted(int arr[], int n){      // Time - O(n^2) | Space - O(1)
    for(int i=0;i<n;i++){
        int j = i+1;
        int count = 1;
        while(j<n){
            if(arr[j] != -1 && arr[i] == arr[j]){
                count++;
                arr[j] = -1;
            }
            j++;
        }
        if(count>1){
            cout<<arr[i]<<" is repeated "<<count<<" times."<<endl;
        }
    }
}

void countDuplicatesUnsorted(int arr[], int n){      // Time - O(n) | Space - O(n)
    int count[n] = {0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if(count[i] > 1){
            cout<<i<<" is repeated "<<count[i]<<" times."<<endl;
        }
    }
}

int main() {
    int arr[] = {8,3,6,4,6,5,6,8,2,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    countDuplicatesUnsorted(arr,n);
    cout<<endl;
    duplicatesUnsorted(arr,n);
    return 0;
}
