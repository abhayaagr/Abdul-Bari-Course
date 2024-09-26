#include <iostream>
using namespace std;

class Array{
    private:
        int *A;
        int size;
        int length;
        
    public:
        void initialise();
        void display();
        void append(int x);
        void insert(int index, int x);  
};

void Array :: initialise(){                  //Time - O(n)
        cout<<"Enter size of array: ";       //Space - O(n)
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

void Array :: display(){                                            //Time - O(n)
        cout<<"Displaying all the elements of array:"<<endl;        //Space - O(1)
        for(int i = 0;i<length;i++){
           cout<<A[i]<<" ";
        }
        cout<<endl;
}

void Array :: append(int x){                              //Time - O(1)
        if(length<size){                                  //Space - O(1)
            A[length] = x;
            length++;
        }
        else{
            cout<<"Error: append("<<x<<"): Size full"<<endl;
        }
}

void Array :: insert(int index, int x){                   //Time - O(n)
    if(index<=length && length<size){                     //Space - O(1)
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
