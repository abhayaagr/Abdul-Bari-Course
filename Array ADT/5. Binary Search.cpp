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

        void binarySearch();
        int Iter_BS(int low, int high, int key);    //Time - O(log n) | Space - O(1)
        int Rec_BS(int low, int high, int key);     //Time - O(log n) | Space - O(n)
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

void Array :: binarySearch(){
    int low = 0;
    int high = length-1;
    int key;
    cout<<"Enter element you want to search: ";
    cin>>key;
    
    cout<<"(Iteratively) Element is present at index: "<<Iter_BS(low, high, key)<<endl;
    cout<<"(Recursively) Element is present at index: "<<Rec_BS(low, high, key)<<endl;
}

int Array :: Iter_BS(int low, int high, int key){
    while(low<=high){
        int mid = (low+high)/2;
        if(A[mid] == key)
            return mid;
        else if(A[mid] < key)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

int Array :: Rec_BS(int low, int high, int key){
    if(low<=high){
        int mid = (low+high)/2;
        if(A[mid] == key)
            return mid;
        else if(A[mid] < key)
            return Rec_BS(mid+1, high, key);
        else 
            return Rec_BS(low, mid-1, key);
    }
    return -1;
}

int main()
{
    Array arr;
    arr.initialise();
    arr.display();
    arr.binarySearch();

    return 0;
}
