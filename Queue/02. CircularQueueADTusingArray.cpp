#include <iostream>
using namespace std;

template<class T>
class QueueCir{
    private:
        int size;
        int front;
        int rear;
        T *Q;
    public:
        QueueCir();                    // Time - O(1) | Space - O(1)
        QueueCir(int size);            // Time - O(1) | Space - O(n)
        ~QueueCir(){delete []Q;};      // Time - O(1) | Space - O(1)
        void enqueue(T x);             // Time - O(1) | Space - O(1)
        T dequeue();                   // Time - O(1) | Space - O(1)
        void display();                // Time - O(n) | Space - O(1)
        bool isEmpty();                // Time - O(1) | Space - O(1)
        bool isFull();                 // Time - O(1) | Space - O(1)
        T first();                     // Time - O(1) | Space - O(1)
        T last();                      // Time - O(1) | Space - O(1)
};

template<class T>
QueueCir<T> :: QueueCir(){
    size = 10;
    front = rear = 0;
    Q = new T[size];
}

template<class T>
QueueCir<T> :: QueueCir(int size){
    this->size = size;
    front = rear = 0;
    Q = new T[size];
}

template<class T>
void QueueCir<T> :: enqueue(T x){
    if((rear+1)%size == front)  
        throw runtime_error("Queue Full");
    else{
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}

template<class T>
T QueueCir<T> :: dequeue(){
    if(front == rear)
        throw runtime_error("Queue Empty");
    else{
        front = (front+1)%size;
        if(front == rear)   front = rear = 0;
        return Q[front];
    }
}

template<class T>
void QueueCir<T> :: display(){
    cout<<"Displaying Queue: ";
    for(int i=(front+1)%size;i!=(rear+1)%size;i=(i+1)%size){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}

template<class T>
bool QueueCir<T> :: isEmpty(){
    return (front == rear);
}

template<class T>
bool QueueCir<T> :: isFull(){
    return ((rear+1)%size == front);
}

template<class T>
T QueueCir<T> :: first(){
    if(front == rear)
        throw runtime_error("Queue Empty");
    else
        return Q[(front+1)%size];
}

template<class T>
T QueueCir<T> :: last(){
    if(front == rear)
        throw runtime_error("Queue Empty");
    else
        return Q[rear%size];
}

int main() {
    QueueCir<int> q(7);
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
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    
    cout<<"First element: "<<q.first()<<endl;
    cout<<"Last element: "<<q.last()<<endl;
    cout<<"Is Full?: "<<q.isFull()<<endl;
    cout<<"Is Empty?: "<<q.isEmpty()<<endl;
    
    return 0;
}
