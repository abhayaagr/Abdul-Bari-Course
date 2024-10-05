#include <bits/stdc++.h>
using namespace std;

void findingDuplicates(int arr[], int n){      // Time - O(n) | Space - O(1)
    int last_duplicate = -1;
    for(int i=0;i<n-1;i++){
        if(arr[i] == arr[i+1] && arr[i] != last_duplicate){
            last_duplicate = arr[i];
            cout<<arr[i]<<" ";
        }
    }
}

void countDuplicates(int arr[], int n){      // Time - O(n) | Space - O(1)
    int j = 0;
    for(int i=0;i<n-1;i++){
        if(arr[i] == arr[i+1]){
            j=i+1;
            while(arr[j] == arr[i]) j++;
            cout<<arr[i]<<" --> "<<j-i<<" times"<<endl;
            i = j-1;
        }
    }
}

int main() {
    int arr[] = {3,6,8,8,10,12,15,15,15,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    findingDuplicates(arr,n);
    cout<<endl;
    countDuplicates(arr,n);
    
    return 0;
}
