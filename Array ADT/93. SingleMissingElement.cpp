#include <iostream>
using namespace std;

int singleMissing(int arr[], int n){        // Time - O(n) | Space - O(1)
    if(n==0)    return 0;
    int diff = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] - i != diff){
            return i+diff;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5,6,8,9,10,11,12,13,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<singleMissing(arr,n);
    
    return 0;
}
