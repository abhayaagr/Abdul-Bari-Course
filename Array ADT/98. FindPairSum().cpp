#include <iostream>
using namespace std;

void findPairSum(int arr[], int n, int k){      // Time - O(n^2) | Space - O(1)
    for(int i = 0;i<n;i++){
        int j=i+1;
        while(j<n){
            if(arr[i]+arr[j] == k)
                cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
            j++;
        }
    }
}

void findPairSumOptimized(int arr[], int n, int k){      // Time - O(n) | Space - O(n)
    int max = -1;
    for(int i=0;i<n;i++){
        if(max<arr[i])  max = arr[i];
    }
    int count[max+1] = {0};
    for(int i = 0;i<n;i++){
        if(k>arr[i] && count[(k-arr[i])] != 0){
            cout<<"("<<arr[i]<<","<<k-arr[i]<<")"<<endl;
        }
        count[arr[i]]++;
    }
}

int main() {
    int arr[] = {6,3,8,10,16,7,5,2,9,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 10;
    findPairSum(arr,n,k);
    cout<<endl;
    findPairSumOptimized(arr,n,k);
    return 0;
}
