#include <iostream>
using namespace std;

template<class T>
class Stack{
  private:
    int size;
    int top;
    T* arr;
  public:
    Stack(){size = 0;top = -1;}         // Time - O(1) | Space - O(1)
    Stack(int size);                    // Time - O(1) | Space - O(n)
    ~Stack(){delete[] arr;}             // Time - O(1) | Space - O(1)
    void display();                     // Time - O(n) | Space - O(1)
    void push(T x);                     // Time - O(1) | Space - O(1)
    T pop();                            // Time - O(1) | Space - O(1)
    T peek(int pos);                    // Time - O(1) | Space - O(1)
    T StackTop();                       // Time - O(1) | Space - O(1)
    bool isEmpty();                     // Time - O(1) | Space - O(1)
    bool isFull();                      // Time - O(1) | Space - O(1)
};

template<class T>
Stack<T> :: Stack(int size){
        this->size = size;
        top = -1;
        arr = new T[size];
}

template<class T>
void Stack<T> :: display(){
        if(top == -1)
            cout<<"Stack Empty";
        else{
            cout<<"Displaying Stack: ";
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
}

template<class T>
void Stack<T> :: push(T x){
        if(top == size-1)
            cout<<"Stack Overflow"<<endl;
        else{
            top++;
            arr[top] = x;
        }
}

template<class T>
T Stack<T> :: pop(){
        T x = -1;
        if(top == -1)
            cout<<"Stack Underflow"<<endl;
        else{
            x = arr[top];
            top--;
        }
        return x;
}

template<class T>
T Stack<T> :: peek(int pos){
        int index = top - pos + 1;
        T x = -1;
        if(index<0 || index>top)
            cout<<"Invalid position"<<endl;
        else
            x = arr[index];
        return x;
}

template<class T>
T Stack<T> :: StackTop(){
        return (top == -1) ? -1 : arr[top];
}

template<class T>
bool Stack<T> :: isEmpty(){
        return (top == -1);
}

template<class T>
bool Stack<T> :: isFull(){
        return (top == size-1);
}

int main() {
    Stack<int> s(5);
    cout<<s.isEmpty()<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    cout<<s.peek(2)<<endl;
    cout<<s.StackTop()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.isFull()<<endl;
    
    return 0;
}
