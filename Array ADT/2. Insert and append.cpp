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
        if(length<size){                                  
            A[length] = x;
            length++;
        }
        else{
            cout<<"Error: append("<<x<<"): Size full"<<endl;
        }
}

void Array :: insert(int index, int x){                   
    if(index<=length && length<size){                     
        for(int i = length; i>index; i--)
            A[i] = A[i-1];
        A[index] = x;
        length++;
    }
    else if(index>length)
        cout<<"Error: insert("<<index<<", "<<x<<"): index > length"<<endl;
    else
        cout<<"Error: insert("<<index<<", "<<x<<"): Size full"<<endl;
}

int main()
{
    Array arr;
    arr.initialise();
    arr.display();
    arr.append(15);
    arr.insert(4,20);
    arr.display();
    
    return 0;
}
