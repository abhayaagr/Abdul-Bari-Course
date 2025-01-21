#include <iostream>
using namespace std;

template<class T>
class Node{
  public:
    T data;
    Node* next;
};

template<class T>
class Stack{
  private:
    Node<T> *top;
  public:
    Stack(){top = NULL;}                // Time - O(1) | Space - O(1)
    ~Stack();                           // Time - O(1) | Space - O(1)
    void display();                     // Time - O(n) | Space - O(1)
    void push(T x);                     // Time - O(1) | Space - O(1)
    T pop();                            // Time - O(1) | Space - O(1)
    T peek(int pos);                    // Time - O(n) | Space - O(1)
    T StackTop();                       // Time - O(1) | Space - O(1)
    bool isEmpty();                     // Time - O(1) | Space - O(1)
    bool isFull();                      // Time - O(1) | Space - O(1)
};

template<class T>
Stack<T> :: ~Stack() {
    Node<T> *p = top;
    while(top){
        top = top->next;
        delete p;
        p = top;
    }
}

template<class T>
void Stack<T> :: display(){
        if(top){
            cout<<"Displaying Stack: ";
            Node<T> *p = top;
            while(p){
                cout<<p->data<<" ";
                p = p->next;
            }
            cout<<endl;
        }
        else{
            cout<<"Stack Empty";
        }
}

template<class T>
void Stack<T> :: push(T x){
        Node<T> *p = new Node<T>;
        if(p){
            p->data = x;
            p->next = top;
            top = p;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
}

template<class T>
T Stack<T> :: pop(){
        if(top == NULL)
            throw runtime_error("Stack Underflow");
        
        T x = top->data;
        Node<T> *p = top;
        top = top->next;
        delete p;
        return x;
}

template<class T>
T Stack<T> :: peek(int pos){
        Node<T> *p = top;
        for(int i=0;p && i<pos-1;i++){
            p = p->next;
        }
        if (!p) throw out_of_range("Invalid position");
        return p->data;
}

template<class T>
T Stack<T> :: StackTop(){
        if (top == NULL) 
            throw runtime_error("Stack is empty");
        return top->data;
}

template<class T>
bool Stack<T> :: isEmpty(){
        return (top == NULL);
}

template<class T>
bool Stack<T> :: isFull(){
        Node<T> *temp = new Node<T>;
        if(temp){
            delete temp;
            return 0;
        }
        return 1;
}

int main() {
    Stack<int> s;
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
