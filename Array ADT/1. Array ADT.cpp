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
}

int main()
{
    Array arr;
    arr.initialise();
    arr.display();
    
    return 0;
}
