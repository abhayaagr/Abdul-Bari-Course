
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
        bool isValid(int index);        //Time - O(1) | Space - O(1)
        bool isFull();                  //Time - O(1) | Space - O(1)
        int get(int index);             //Time - O(1) | Space - O(1)
        void set(int index, int x);     //Time - O(1) | Space - O(1)
        int max();                      //Time - O(n) | Space - O(1)
        int min();                      //Time - O(n) | Space - O(1)
        int sum();                      //Time - O(n) | Space - O(1)
        int avg();                      //Time - O(n) | Space - O(1)
};

void Array :: initialise(){                            
        cout<<"Enter size of array: ";                 
        cin>>size;
        A = new int[size];
            
        cout<<"Enter length of numbers: ";
        cin>>length;
        
        while(length>size){
            cout<<"Error: initialise(): Length>Size"<<endl;
            cout<<"Enter new length: ";
            cin>>length;
        }
            
        cout<<"Enter all elements:"<<endl;
        for(int i = 0;i<length;i++)
        cin>>A[i];
}

void Array :: display(){
        cout<<"Displaying all the elements of array:"<<endl;
        for(int i = 0;i<length;i++){
           cout<<A[i]<<" ";
        }
        cout<<endl;
}


bool Array :: isValid(int index){
    if(index >= 0 && index <= length){
        return 1;
    }
    cout<<"Error: Invalid index"<<endl;
    return 0;
}

bool Array :: isFull(){
    if(length>=size){
        cout<<"Error: Size full"<<endl;
        return 1;
    }
    return 0;
}

int Array :: get(int index){
    if(isValid(index))
        return A[index];
    return -1;
}             

void Array :: set(int index, int x){
    if(isValid(index)){
        A[index] = x;
    }
    return;
}

int Array :: max(){
    int maxi = A[0];
    for(int i=0;i<length;i++){
        if(A[i] > maxi)
            maxi = A[i];
    }
    return maxi;
}

int Array :: min(){
    int mini = A[0];
    for(int i=0;i<length;i++){
        if(A[i] < mini)
            mini = A[i];
    }
    return mini;
}

int Array :: sum(){
    int sum = 0;
    for(int i=0;i<length;i++){
        sum += A[i];
    }
    return sum;
}

int Array :: avg(){
    return sum()/length;
}

int main()
{
    Array arr;
    arr.initialise();
    arr.display();
    cout<<"Element present at 3 index: "<<arr.get(3)<<endl;
    arr.set(3,50);
    cout<<"Max value is: "<<arr.max()<<endl;
    cout<<"Min value is: "<<arr.min()<<endl;
    cout<<"Sum value is: "<<arr.sum()<<endl;
    cout<<"Avg value is: "<<arr.avg()<<endl;
    
    return 0;
}
