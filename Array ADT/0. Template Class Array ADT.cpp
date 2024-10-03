#include <iostream>
using namespace std;

template<class T>
class Array{
    private:
        T *A;
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
        T deleteIndex();                //Time - O(n) | Space - O(1)
        int linearSearch();             //Time - O(n) | Space - O(1)
        int binarySearch();        
        int Iterative_BS(int low, int high, T key);     //Time - O(log n) | Space - O(1)
        int Recursive_BS(int low, int high, T key);     //Time - O(log n) | Space - O(log n)
        T get();                        //Time - O(1) | Space - O(1)
        void set();                     //Time - O(1) | Space - O(1)
        T max();                        //Time - O(n) | Space - O(1)
        T min();                        //Time - O(n) | Space - O(1)
        T sum();                        //Time - O(n) | Space - O(1)
        T avg();                        //Time - O(n) | Space - O(1)
        void reverse();                 //Time - O(n) | Space - O(1)
        T leftShift();                  //Time - O(n) | Space - O(1)
        void leftRotate();              //Time - O(n) | Space - O(1)
        T rightShift();                 //Time - O(n) | Space - O(1)
        void rightRotate();             //Time - O(n) | Space - O(1)
        void insertInSorted();          //Time - O(n) | Space - O(1)
        bool isSorted();                //Time - O(n) | Space - O(1)
        void sortNegativePositive();    //Time - O(n) | Space - O(1)
};

template<class T>
Array<T> :: Array(){
    size = 10;
    length = 0;
    A = new T[size];
}

template<class T>
Array<T> :: Array(int sz){
    size = sz;
    length = 0;
    A = new T[size];
}

template<class T>
Array<T> :: ~Array(){
    delete []A;
}

template<class T>
void Array<T> :: initialise(){                            
        cout<<"Enter size of array: ";
        cin>>size;
        A = new T[size];
            
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

template<class T>
void Array<T> :: display(){
        cout<<"Displaying all the elements of array:"<<endl;
        for(int i = 0;i<length;i++){
           cout<<A[i]<<" ";
        }
        cout<<endl;
}

template<class T>
void Array<T> :: append(){
        cout<<"Enter value you wish to append: ";
        T x;
        cin>>x;
        if(!isFull()){
            A[length] = x;
            length++;
        }
}

template<class T>
bool Array<T> :: isValid(int index){
    if(index >= 0 && index < length){
        return 1;
    }
    cout<<"Error: Invalid index"<<endl;
    return 0;
}

template<class T>
bool Array<T> :: isFull(){
    if(length>=size){
        cout<<"Error: Size full"<<endl;
        return 1;
    }
    return 0;
}

template<class T>
void Array<T> :: insert(){
    int index;
    T x;
    cout<<"Enter index: ";
    cin>> index;
    cout<<"Enter the element to insert: ";
    cin>> x;
    if(isValid(index) && !isFull()){
        for(int i = length; i>index; i--)
            A[i] = A[i-1];
        A[index] = x;
        length++;
    }
}

template<class T>
T Array<T> :: deleteIndex(){
    cout<<"Enter the index to delete: ";
    int index;
    cin>>index;
    T element;
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

template<class T>
int Array<T> :: linearSearch(){         //Returns index of key;
    cout<<"Enter key to search: ";
    T key;
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

template<class T>
int Array<T> :: binarySearch(){
    int low = 0;
    int high = length-1;
    T key;
    cout<<"Enter element you want to search: ";
    cin>>key;

    int index = Iterative_BS(low, high, key);
    cout<<"(Iteratively) Element is present at index: "<<index<<endl;
    cout<<"(Recursively) Element is present at index: "<<Recursive_BS(low, high, key)<<endl;
    return index;
}

template<class T>
int Array<T> :: Iterative_BS(int low, int high, T key){
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

template<class T>
int Array<T> :: Recursive_BS(int low, int high, T key){
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

template<class T>
T Array<T> :: get(){
    int index;
    cout<<"Enter index of element: ";
    cin>>index;
    if(isValid(index)){
        cout<<"Element is: "<<A[index]<<endl;
        return A[index];
    }
    return -1;
}             

template<class T>
void Array<T> :: set(){
    int index;
    T x;
    cout<<"Enter index: ";
    cin>> index;
    cout<<"Enter the value to set: ";
    cin>> x;
    if(isValid(index)){
        A[index] = x;
    }
    return;
}

template<class T>
T Array<T> :: max(){
    T maxi = A[0];
    for(int i=0;i<length;i++){
        if(A[i] > maxi)
            maxi = A[i];
    }
    cout<<"Maximum value is: "<<maxi<<endl;
    return maxi;
}

template<class T>
T Array<T> :: min(){
    T mini = A[0];
    for(int i=0;i<length;i++){
        if(A[i] < mini)
            mini = A[i];
    }
    cout<<"Minimum value is: "<<mini<<endl;
    return mini;
}

template<class T>
T Array<T> :: sum(){                //Can be done recursively too with Time - O(n) and Space - O(n)
    T sum = 0;                   //sum(A,n) = 0, n<0
    for(int i=0;i<length;i++){     //         = sum(A,n-1) + A[n], n>=0
        sum += A[i];
    }
    cout<<"Sum of all elements is: "<<sum<<endl;
    return sum;
}

template<class T>
T Array<T> :: avg(){
    T sum = 0;                   
    for(int i=0;i<length;i++){     
        sum += A[i];
    }
    cout<<"Average of all elements is: "<<sum/length<<endl; 
    return sum/length;
}

template<class T>
void Array<T> :: reverse(){
    for(int i=0, j=length-1;i<j;i++,j--){
        swap(A[i], A[j]);
    }
}

template<class T>
T Array<T> :: leftShift(){
    T x = A[0];
    for(int i = 0;i<length-1;i++){
        A[i] = A[i+1];
    }
    A[length-1] = 0;
    return x;
}

template<class T>
void Array<T> :: leftRotate(){
    T temp = A[0];
    for(int i = 0;i<length-1;i++){
        A[i] = A[i+1];
    }
    A[length-1] = temp;
}

template<class T>
T Array<T> :: rightShift(){
    T x = A[length-1];
    for(int i = length-1;i>0;i--){
        A[i] = A[i-1];
    }
    A[0] = 0;
    return x;
}

template<class T>
void Array<T> :: rightRotate(){
    T temp = A[length-1];
    for(int i = length-1;i>0;i--){
        A[i] = A[i-1];
    }
    A[0] = temp;
}

template<class T>
void Array<T> :: insertInSorted(){
    T x;
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

template<class T>
bool Array<T> :: isSorted(){
    for(int i=0;i<length-1;i++){
        if(A[i] > A[i+1]){
            cout<<"Array is not sorted."<<endl;
            return false;
        }
    }
    cout<<"Array is sorted."<<endl;
    return true;
}

template<class T>
void Array<T> :: sortNegativePositive(){
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
    Array<int> arr;
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
