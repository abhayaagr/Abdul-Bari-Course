#include <iostream>
using namespace std;

template<class T>
class Node{
  public:
    T data;
    Node<T> *next;
};

template<class T>
class DeQueue{
    private:
        Node<T> *front;
        Node<T> *rear;
    public:
        DeQueue()                      // Time - O(1) | Space - O(1)
            {front=rear=NULL;}                    
        ~DeQueue();                    // Time - O(1) | Space - O(1)
        void push_back(T x);           // Time - O(1) | Space - O(1)
        void push_front(T x);          // Time - O(1) | Space - O(1)
        T pop_front();                 // Time - O(1) | Space - O(1)
        T pop_back();                  // Time - O(n) | Space - O(1)
        void display();                // Time - O(n) | Space - O(1)
        bool isEmpty();                // Time - O(1) | Space - O(1)
        bool isFull();                 // Time - O(1) | Space - O(1)
        T first();                     // Time - O(1) | Space - O(1)
        T last();                      // Time - O(1) | Space - O(1)
};

template<class T>
DeQueue<T> :: ~DeQueue(){
    Node<T> *p = front;
    while(front){
        front = front->next;
        delete p;
        p = front;
    }
    rear = NULL;
}

template<class T>
void DeQueue<T> :: push_back(T x){
    Node<T> *temp = new Node<T>;
    if(temp==NULL)
        throw runtime_error("DeQueue Full");
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
void DeQueue<T> :: push_front(T x){
    Node<T> *temp = new Node<T>;
    if(temp==NULL)
        throw runtime_error("DeQueue Full");
    else{
        temp->data = x;
        temp->next = NULL;
        if(front==NULL)
            front=rear=temp;
        else{
            temp->next = front;
            front = temp;
        }
    }
}

template<class T>
T DeQueue<T> :: pop_front(){
    T x;
    if(front == NULL)
        throw runtime_error("DeQueue Empty");
    else{
        x = front->data;
        Node<T> *t = front;
        front = front->next;
        delete t;
    }
    return x;
}

template<class T>
T DeQueue<T> :: pop_back(){
    T x;
    if(front == NULL)
        throw runtime_error("DeQueue Empty");
    else if(front == rear){
        x = rear->data;
        delete front;
        front = rear = NULL;
    }
    else{
        Node<T> *t = front;
        while(t->next != rear)
            t = t->next;
        delete rear;
        t->next = NULL;
        rear = t;
    }
    return x;
}

template<class T>
void DeQueue<T> :: display(){
    cout<<"Displaying DeQueue: ";
    Node<T> *p = front;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

template<class T>
bool DeQueue<T> :: isEmpty(){
    return (front == NULL);
}

template<class T>
bool DeQueue<T> :: isFull(){
    Node<T> *temp = new Node<T>;
    if(temp!=NULL){
        delete temp;
        return 0;
    }
    return 1;
}

template<class T>
T DeQueue<T> :: first(){
    if(front == NULL)
        throw runtime_error("DeQueue Empty");
    else
        return front->data;
}

template<class T>
T DeQueue<T> :: last(){
    if(rear == NULL)
        throw runtime_error("DeQueue Empty");
    else
        return rear->data;
}

int main() {
    DeQueue<int> q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    q.push_back(6);
    q.display();
    cout<<"First element: "<<q.first()<<endl;
    cout<<"Last element: "<<q.last()<<endl;
    q.pop_front();
    q.pop_front();
    q.display();
    q.push_front(5);
    q.pop_back();
    q.display();
    
    cout<<"First element: "<<q.first()<<endl;
    cout<<"Last element: "<<q.last()<<endl;
    cout<<"Is Full?: "<<q.isFull()<<endl;
    cout<<"Is Empty?: "<<q.isEmpty()<<endl;
    
    return 0;
}
