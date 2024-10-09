#include <iostream>
using namespace std;

void findPairSumSorted(int arr[], int n, int k){      // Time - O(n) | Space - O(1)
    int i=0,j=n-1;
    while(i<j){
        if(arr[i]+arr[j] > k)   j--;
        else if(arr[i]+arr[j] < k)  i++;
        else{
            cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
            i++;
            j--;
        }
    }
    
}

int main() {
    int arr[] = {1,3,4,5,6,8,9,10,12,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 10;
    findPairSumSorted(arr,n,k);
    return 0;
}
