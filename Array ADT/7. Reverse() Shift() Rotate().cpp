#include <iostream>
using namespace std;

class Array{
    private:
        int *A;
        int size;
        int length;
        
    public:
        void initialise();          //Time - O(n) | Space - O(n)
        void display();             //Time - O(n) | Space - O(1)
        void reverse();             //Time - O(n) | Space - O(1)
        void leftShift();           //Time - O(n) | Space - O(1)
        void leftRotate();          //Time - O(n) | Space - O(1)
        void rightShift();          //Time - O(n) | Space - O(1)
        void rightRotate();         //Time - O(n) | Space - O(1)
};

void Array :: initialise(){
        cout<<"Enter size of array: ";
        cin>>size;
        A = new int[size];
            
        cout<<"Enter length of numbers: ";
        cin>>length;
            
        cout<<"Enter all elements:"<<endl;
        for(int i = 0;i<length;i++){
            cin>>A[i];
        }
}

void Array :: display(){
        cout<<"Displaying all the elements of array:"<<endl;
        for(int i = 0;i<length;i++){
           cout<<A[i]<<" ";
        }
        cout<<endl;
}

void Array :: reverse(){
    for(int i=0, j=length-1;i<j;i++,j--){
        swap(A[i], A[j]);
    }
}

void Array :: leftShift(){
    for(int i = 0;i<length-1;i++){
        A[i] = A[i+1];
    }
    A[length-1] = 0;
}

void Array :: leftRotate(){
    int temp = A[0];
    for(int i = 0;i<length-1;i++){
        A[i] = A[i+1];
    }
    A[length-1] = temp;
}

void Array :: rightShift(){
    for(int i = length-1;i>0;i--){
        A[i] = A[i-1];
    }
    A[0] = 0;
}

void Array :: rightRotate(){
    int temp = A[length-1];
    for(int i = length-1;i>0;i--){
        A[i] = A[i-1];
    }
    A[0] = temp;
}

int main()
{
    Array arr;
    arr.initialise();
    arr.display();
    arr.reverse();
    arr.display();
    arr.leftShift();
    arr.display();
    arr.leftRotate();
    arr.display();
    arr.rightShift();
    arr.display();
    arr.rightRotate();
    arr.display();
    
    return 0;
}
