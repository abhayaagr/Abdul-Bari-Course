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
        void append(int x);             //Time - O(1) | Space - O(1)
        void insert(int index, int x);  //Time - O(n) | Space - O(1)
        bool isValid(int index);        //Time - O(1) | Space - O(1)
        bool isFull();                  //Time - O(1) | Space - O(1)
        void deleteIndex(int index);    //Time - O(n) | Space - O(1)
        int linearSearch(int key);      //Time - O(n) | Space - O(1)
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

void Array :: append(int x){
        if(!isFull()){
            A[length] = x;
            length++;
        }
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

void Array :: insert(int index, int x){
    if(isValid(index) && !isFull()){
        for(int i = length; i>index; i--)
            A[i] = A[i-1];
        A[index] = x;
        length++;
    }
}

void Array :: deleteIndex(int index){
    if(isValid(index)){
        for(int i = index; i<length-1; i++){
            A[i] = A[i+1];
        }
        length--;
    }
}

int Array :: linearSearch(int key){         //Returns index of key;
    for(int i=0;i<length;i++){
        if(key == A[i]){
            // swap(A[0], A[i]);            //Move-to-head - Enhances efficiency if key is searched again
            // if(i>0) swap(A[i-1], A[i]);  //Transposition - Arranges array as per # of times key is searched
            return i;                       //Return updated index of key if used optimization i.e 0 or i-1
        }
    }
    return -1;
}

int main()
{
    Array arr;
    arr.initialise();
    arr.display();
    arr.append(15);
    arr.insert(4,20);
    arr.display();
    arr.deleteIndex(6);
    arr.display();
    cout<<"Linear Search for key '5' at index: "<<arr.linearSearch(5)<<endl;
    arr.display();
    
    return 0;
}
