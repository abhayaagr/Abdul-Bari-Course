#include <iostream>
using namespace std;

template<class T>
class Node{
  public:
    T data;
    Node<T> *next;
};

template<class T>
class Queue{
    private:
        Node<T> *front;
        Node<T> *rear;
    public:
        Queue()                        // Time - O(1) | Space - O(1)
            {front=rear=NULL;}                    
        ~Queue();                      // Time - O(n) | Space - O(1)
        void enqueue(T x);             // Time - O(1) | Space - O(1)
        T dequeue();                   // Time - O(1) | Space - O(1)
        void display();                // Time - O(n) | Space - O(1)
        bool isEmpty();                // Time - O(1) | Space - O(1)
        bool isFull();                 // Time - O(1) | Space - O(1)
        T first();                     // Time - O(1) | Space - O(1)
        T last();                      // Time - O(1) | Space - O(1)
};

template<class T>
Queue<T> :: ~Queue(){
    Node<T> *p = front;
    while(front){
        front = front->next;
        delete p;
        p = front;
    }
    rear = NULL;
}

template<class T>
void Queue<T> :: enqueue(T x){
    Node<T> *temp = new Node<T>;
    if(temp==NULL)
        throw runtime_error("Queue Full");
    else{
        temp->data = x;
        temp->next = NULL;
        if(front==NULL)
            front=rear=temp;
        else{
            rear->next = temp;
            rear = temp;
        }
    }
}

template<class T>
T Queue<T> :: dequeue(){
    T x;
    if(front == NULL)
        throw runtime_error("Queue Empty");
    else{
        x = front->data;
        Node<T> *t = front;
        front = front->next;
        delete t;
    }
    return x;
}

template<class T>
void Queue<T> :: display(){
    cout<<"Displaying Queue: ";
    Node<T> *p = front;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

template<class T>
bool Queue<T> :: isEmpty(){
    return (front == NULL);
}

template<class T>
bool Queue<T> :: isFull(){
    Node<T> *temp = new Node<T>;
    if(temp!=NULL){
        delete temp;
        return 0;
    }
    return 1;
}

template<class T>
T Queue<T> :: first(){
    if(front == NULL)
        throw runtime_error("Queue Empty");
    else
        return front->data;
}

template<class T>
T Queue<T> :: last(){
    if(rear == NULL)
        throw runtime_error("Queue Empty");
    else
        return rear->data;
}

int main() {
    Queue<int> q;
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
