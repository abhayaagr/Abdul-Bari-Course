#include <iostream>
using namespace std;

class Array{
  public:
    int arr[10];
    int length;
    void display(){
        for(int i = 0; i < length; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

Array* unionSorted(Array A, Array B){              // Time - O(n) | Space - O(n)
    Array *C = new Array;
    int i = 0, j = 0, k = 0;
    while(i < A.length && j < B.length){
        if(A.arr[i] < B.arr[j])
            C->arr[k++] = A.arr[i++];
        else if(B.arr[j] < A.arr[i])
            C->arr[k++] = B.arr[j++]; 
        else{
            C->arr[k++] = B.arr[j++];
            i++;
        }
    }
    for(; i < A.length; i++)
        C->arr[k++] = A.arr[i];
    for(; j < B.length; j++)
        C->arr[k++] = B.arr[j];
    C->length = k;
    return C;
}

Array* intersectionSorted(Array A, Array B){         // Time - O(n) | Space - O(n)
    Array *C = new Array;
    int i = 0, j = 0, k = 0;
    while(i < A.length && j < B.length){
        if(A.arr[i] < B.arr[j])
            i++;
        else if(B.arr[j] < A.arr[i])
            j++; 
        else{
            C->arr[k++] = B.arr[j++];
            i++;
        }
    }
    C->length = k;
    return C;
}

Array* differenceSorted(Array A, Array B){          // Time - O(n) | Space - O(n)
    Array *C = new Array;
    int i = 0, j = 0, k = 0;
    while(i < A.length && j < B.length){
        if(A.arr[i] < B.arr[j])
            C->arr[k++] = A.arr[i++];
        else if(B.arr[j] < A.arr[i])
            j++; 
        else{
            j++;
            i++;
        }
    }
    for(; i < A.length; i++)
        C->arr[k++] = A.arr[i];
    C->length = k;
    return C;
}

int main()
{
    Array A = {{2,6,10,15,25}, 5};
    Array B = {{3,6,7,15,20}, 5};
    Array *C = unionSorted(A, B);
    C->display();
    C = intersectionSorted(A, B);
    C->display();
    C = differenceSorted(A, B);
    C->display();
    return 0;
}
