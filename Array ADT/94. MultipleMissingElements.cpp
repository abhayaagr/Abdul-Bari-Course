#include <iostream>
using namespace std;

void multipleMissing(int arr[], int n){      // Time - O(n) | Space - O(1)
    if(n==0)    return;
    int diff = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] - i != diff){
            while(diff<arr[i]-i){
                cout<<i+diff<<" ";
                diff++;
            }
        }
    }
    return;
}

int main() {
    int arr[] = {6,7,8,9,11,12,15,16,17,18,19};
    int n = sizeof(arr)/sizeof(arr[0]);
    multipleMissing(arr,n);
    
    return 0;
}
