#include <iostream>
using namespace std;

template<class T>
class Queue{
    private:
        int size;
        int front;
        int rear;
        T *Q;
    public:
        Queue();                    // Time - O(1) | Space - O(1)
        Queue(int size);            // Time - O(1) | Space - O(n)
        ~Queue(){delete []Q;};      // Time - O(1) | Space - O(1)
        void enqueue(T x);          // Time - O(1) | Space - O(1)
        T dequeue();                // Time - O(1) | Space - O(1)
        void display();             // Time - O(n) | Space - O(1)
        bool isEmpty();             // Time - O(1) | Space - O(1)
        bool isFull();              // Time - O(1) | Space - O(1)
        T first();                  // Time - O(1) | Space - O(1)
        T last();                   // Time - O(1) | Space - O(1)
};

template<class T>
Queue<T> :: Queue(){
    size = 10;
    front = rear = -1;
    Q = new T[size];
}

template<class T>
Queue<T> :: Queue(int size){
    this->size = size;
    front = rear = -1;
    Q = new T[size];
}

template<class T>
void Queue<T> :: enqueue(T x){
    if(rear == size-1)  
        throw runtime_error("Queue Full");
    else
        Q[++rear] = x;
}

template<class T>
T Queue<T> :: dequeue(){
    if(front == rear)
        throw runtime_error("Queue Empty");
    else
        return Q[++front];
}

template<class T>
void Queue<T> :: display(){
    cout<<"Displaying Queue: ";
    for(int i=front+1;i<=rear;i++){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}

template<class T>
bool Queue<T> :: isEmpty(){
    return (front == rear);
}

template<class T>
bool Queue<T> :: isFull(){
    return (rear == size-1);
}

template<class T>
T Queue<T> :: first(){
    if(front == rear)
        throw runtime_error("Queue Empty");
    else
        return Q[front+1];
}

template<class T>
T Queue<T> :: last(){
    if(front == rear)
        throw runtime_error("Queue Empty");
    else
        return Q[rear];
}

int main() {
    Queue<int> q(10);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    cout<<"First element: "<<q.first()<<endl;
    cout<<"Last element: "<<q.last()<<endl;
    q.dequeue();
    q.dequeue();
    q.display();
    cout<<"First element: "<<q.first()<<endl;
    cout<<"Last element: "<<q.last()<<endl;
    cout<<"Is Full?: "<<q.isFull()<<endl;
    cout<<"Is Empty?: "<<q.isEmpty()<<endl;
    
    return 0;
}
