#include <iostream>
using namespace std;

class Array{
    private:
        int *A;
        int size;
        int length;
        
    public:
        Array();
        Array(int sz);
        ~Array();
        void initialise();              //Time - O(n) | Space - O(n)
        void display();                 //Time - O(n) | Space - O(1)
        bool isValid(int index);        //Time - O(1) | Space - O(1)
        bool isFull();                  //Time - O(1) | Space - O(1)
        void append();                  //Time - O(1) | Space - O(1)
        void insert();                  //Time - O(n) | Space - O(1)
        int deleteIndex();              //Time - O(n) | Space - O(1)
        int linearSearch();             //Time - O(n) | Space - O(1)
        int binarySearch();        
        int Iterative_BS(int low, int high, int key);     //Time - O(log n) | Space - O(1)
        int Recursive_BS(int low, int high, int key);     //Time - O(log n) | Space - O(log n)
        int get();                      //Time - O(1) | Space - O(1)
        void set();                     //Time - O(1) | Space - O(1)
        int max();                      //Time - O(n) | Space - O(1)
        int min();                      //Time - O(n) | Space - O(1)
        int sum();                      //Time - O(n) | Space - O(1)
        int avg();                      //Time - O(n) | Space - O(1)
        void reverse();                 //Time - O(n) | Space - O(1)
        int leftShift();                //Time - O(n) | Space - O(1)
        void leftRotate();              //Time - O(n) | Space - O(1)
        int rightShift();               //Time - O(n) | Space - O(1)
        void rightRotate();             //Time - O(n) | Space - O(1)
        void insertInSorted();          //Time - O(n) | Space - O(1)
        bool isSorted();                //Time - O(n) | Space - O(1)
        void sortNegativePositive();    //Time - O(n) | Space - O(1)
};

Array :: Array(){
    size = 10;
    length = 0;
    A = new int[size];
}

Array :: Array(int sz){
    size = sz;
    length = 0;
    A = new int[size];
}

Array :: ~Array(){
    delete []A;
}

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

void Array :: append(){
        cout<<"Enter value you wish to append: ";
        int x;
        cin>>x;
        if(!isFull()){
            A[length] = x;
            length++;
        }
}

bool Array :: isValid(int index){
    if(index >= 0 && index < length){
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

void Array :: insert(){
    int index, x;
    cout<<"Enter index: ";
    cin>> index;
    cout<<"Enter the value to insert: ";
    cin>> x;
    if(isValid(index) && !isFull()){
        for(int i = length; i>index; i--)
            A[i] = A[i-1];
        A[index] = x;
        length++;
    }
}

int Array :: deleteIndex(){
    cout<<"Enter the index to delete: ";
    int index;
    cin>>index;
    int element;
    if(isValid(index)){
        element = A[index];
        for(int i = index; i<length-1; i++){
            A[i] = A[i+1];
        }
        length--;
        cout<<"Element deleted is: "<<element<<endl;
        return element;
    }
    return -1;
}

int Array :: linearSearch(){         //Returns index of key;
    cout<<"Enter key to search: ";
    int key;
    cin>>key;
    for(int i=0;i<length;i++){
        if(key == A[i]){
            // swap(A[0], A[i]);            //Move-to-head - Enhances efficiency if key is searched again
            // if(i>0) swap(A[i-1], A[i]);  //Transposition - Arranges array as per # of times key is searched
            cout<<"Element is present at index: "<<i<<endl;
            return i;                       //Return updated index of key if used optimization i.e 0 or i-1
        }
    }
    cout<<"Element is not present."<<endl;
    return -1;
}

int Array :: binarySearch(){
    int low = 0;
    int high = length-1;
    int key;
    cout<<"Enter element you want to search: ";
    cin>>key;

    int index = Iterative_BS(low, high, key);
    cout<<"(Iteratively) Element is present at index: "<<index<<endl;
    cout<<"(Recursively) Element is present at index: "<<Recursive_BS(low, high, key)<<endl;
    return index;
}

int Array :: Iterative_BS(int low, int high, int key){
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

int Array :: Recursive_BS(int low, int high, int key){
    if(low<=high){
        int mid = (low+high)/2;
        if(A[mid] == key)
            return mid;
        else if(A[mid] < key)
            return Recursive_BS(mid+1, high, key);
        else 
            return Recursive_BS(low, mid-1, key);
    }
    return -1;
}

int Array :: get(){
    int index;
    cout<<"Enter index of element: ";
    cin>>index;
    if(isValid(index)){
        cout<<"Element is: "<<A[index]<<endl;
        return A[index];
    }
    return -1;
}             

void Array :: set(){
    int index, x;
    cout<<"Enter index: ";
    cin>> index;
    cout<<"Enter the value to set: ";
    cin>> x;
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
    cout<<"Maximum value is: "<<maxi<<endl;
    return maxi;
}

int Array :: min(){
    int mini = A[0];
    for(int i=0;i<length;i++){
        if(A[i] < mini)
            mini = A[i];
    }
    cout<<"Minimum value is: "<<mini<<endl;
    return mini;
}

int Array :: sum(){                //Can be done recursively too with Time - O(n) and Space - O(n)
    int sum = 0;                   //sum(A,n) = 0, n<0
    for(int i=0;i<length;i++){     //         = sum(A,n-1) + A[n], n>=0
        sum += A[i];
    }
    cout<<"Sum of all elements is: "<<sum<<endl;
    return sum;
}

int Array :: avg(){
    int sum = 0;                   
    for(int i=0;i<length;i++){     
        sum += A[i];
    }
    cout<<"Average of all elements is: "<<sum/length<<endl; 
    return sum/length;
}

void Array :: reverse(){
    for(int i=0, j=length-1;i<j;i++,j--){
        swap(A[i], A[j]);
    }
}

int Array :: leftShift(){
    int x = A[0];
    for(int i = 0;i<length-1;i++){
        A[i] = A[i+1];
    }
    A[length-1] = 0;
    return x;
}

void Array :: leftRotate(){
    int temp = A[0];
    for(int i = 0;i<length-1;i++){
        A[i] = A[i+1];
    }
    A[length-1] = temp;
}

int Array :: rightShift(){
    int x = A[length-1];
    for(int i = length-1;i>0;i--){
        A[i] = A[i-1];
    }
    A[0] = 0;
    return x;
}

void Array :: rightRotate(){
    int temp = A[length-1];
    for(int i = length-1;i>0;i--){
        A[i] = A[i-1];
    }
    A[0] = temp;
}

void Array :: insertInSorted(){
    int x;
    cout<<"Enter element to insert: ";
    cin>>x;
    
    int i = length-1;
    while(i>=0 && A[i] > x){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;
}

bool Array :: isSorted(){
    for(int i=0;i<length-1;i++){
        if(A[i] > A[i+1]){
            cout<<"Array is not sorted."<<endl;
            return false;
        }
    }
    cout<<"Array is sorted."<<endl;
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
    cout<<"Welcome to Array ADT"<<endl;
    Array arr;
    int n;
    do{
        cout<<endl;
        cout<<"List of functions -->"<<endl;
        cout<<"1. Initialise an array"<<endl;
        cout<<"2. Display the array"<<endl;
        cout<<"3. Append in the array"<<endl;
        cout<<"4. Insert at a given index in the array"<<endl;
        cout<<"5. Delete an element of a given index"<<endl;
        cout<<"6. Perform linear search for a key"<<endl;
        cout<<"7. Perform binary search for a key"<<endl;
        cout<<"8. Get an element of given index"<<endl;
        cout<<"9. Set an element at a given index"<<endl;
        cout<<"10. Find maximum element of array"<<endl;
        cout<<"11. Find minimum element of array"<<endl;
        cout<<"12. Find sum of all elements of array"<<endl;
        cout<<"13. Find average of all elements of array"<<endl;
        cout<<"14. Reverse the array"<<endl;
        cout<<"15. Left shift array"<<endl;
        cout<<"16. Right shift array"<<endl;
        cout<<"17. Left rotate array"<<endl;
        cout<<"18. Right rotate array"<<endl;
        cout<<"19. Check if array is sorted"<<endl;
        cout<<"20. Insert an element in a sorted array"<<endl;
        cout<<"21. Arrange negative and positive elements"<<endl;
        cout<<endl<<"Enter 0 to exit."<<endl;
        cout<<"Enter the choice you want to perform: ";
        cin>>n;
        cout<<endl;
        switch(n){
            case 0: break;
            case 1: arr.initialise(); break;
            case 2: arr.display(); break;
            case 3: arr.append(); break;
            case 4: arr.insert(); break;
            case 5: arr.deleteIndex(); break;
            case 6: arr.linearSearch(); break;
            case 7: arr.binarySearch(); break;
            case 8: arr.get(); break;
            case 9: arr.set(); break;
            case 10: arr.max(); break;
            case 11: arr.min(); break;
            case 12: arr.sum(); break;
            case 13: arr.avg(); break;
            case 14: arr.reverse(); break;
            case 15: arr.leftShift(); break;
            case 16: arr.rightShift(); break;
            case 17: arr.leftRotate(); break;
            case 18: arr.rightRotate(); break;
            case 19: arr.isSorted(); break;
            case 20: arr.insertInSorted();  break;
            case 21: arr.sortNegativePositive(); break;
            
            default:cout<<"Enter valid choice."<<endl;
        }
    }while(n!=0);
    cout<<endl<<"ThankYou for using the program !!!"<<endl;
    return 0;
}
