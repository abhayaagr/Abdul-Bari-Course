#include <iostream>
#include <stack>
using namespace std;

template<class T>
class Queue{
    private:
        stack<T> s1;
        stack<T> s2;
    public:
        void push(T x);                 // Time - O(1) | Space - O(1)
        T pop();                        // Time - O(n) | Space - O(1)
        bool isEmpty();                 // Time - O(1) | Space - O(1)
};

template<class T>
void Queue<T> :: push(T x){
    s1.push(x);
}

template<class T>
T Queue<T> :: pop(){
    if(s2.empty()){
        if(s1.empty())
            throw runtime_error("Queue Empty");
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    T x = s2.top();
    s2.pop();
    return x;
}

template<class T>
bool Queue<T> :: isEmpty(){
    return (s2.empty() && s1.empty());
}

int main() {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<"Pop value: "<<q.pop()<<endl;
    cout<<"Pop value: "<<q.pop()<<endl;
    cout<<"Pop value: "<<q.pop()<<endl;
    q.push(4);
    q.push(5);
    q.push(6);
    cout<<"Pop value: "<<q.pop()<<endl;
    cout<<"Pop value: "<<q.pop()<<endl;
    cout<<"Pop value: "<<q.pop()<<endl;

    cout<<"Is Empty?: "<<q.isEmpty()<<endl;
    
    return 0;
}
