#include <iostream>
using namespace std;

class Array{
    private:
        int *A;
        int size;
        int length;
        
    public:
        void initialise();              //Time - O(n) | Space - O(n)
        void display();                 //Time - O(n) | Space - O(1)
        void insertInSorted(int x);     //Time - O(n) | Space - O(1)
        bool isSorted();                //Time - O(n) | Space - O(1)
        void sortNegativePositive();    //Time - O(n) | Space - O(1)
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

void Array :: insertInSorted(int x){
    int i = length-1;
    while(A[i] > x){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;
}

bool Array :: isSorted(){
    for(int i=0;i<length-1;i++){
        if(A[i] > A[i+1])
            return false;
    }
    return true;
}

void Array :: sortNegativePositive(){
    int i = 0, j = length-1;
    while(i<j){
        while(A[i] < 0) i++;
        while(A[j] > 0) j--;
        if(i<j)
            swap(A[i], A[j]);
    }
}

int main()
{
    Array arr;
    arr.initialise();
    arr.display();
    arr.insertInSorted(5);
    arr.display();
    cout<<arr.isSorted();
    arr.sortNegativePositive();
    arr.display();
    
    return 0;
}
