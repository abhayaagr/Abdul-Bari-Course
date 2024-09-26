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
    cout<<"Linear Search for key '5' at index: "<<arr.linearSearch(5)<<endl;
    
    return 0;
}
