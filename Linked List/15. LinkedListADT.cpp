#include <bits/stdc++.h>
using namespace std;

template<class T>
class Node{
    public:
        T data;
        Node<T> *next;
};

template<class T>
class LinkedList{
    private:
        Node<T> *head;
        Node<T> *tail;
    public:
        LinkedList(){head = tail = NULL;}       // Time - O(1) | Space - O(1)
        LinkedList(T arr[], int n);             // Time - O(n) | Space - O(n)
        ~LinkedList();                          // Time - O(n) | Space - O(1)
        
        void display();                         // Time - O(n) | Space - O(1)
        int length();                           // Time - O(n) | Space - O(1)
        T deleteNode(int index);                // Time - O(n) | Space - O(1)
        T sum();                                // Time - O(n) | Space - O(1)
        T maxi();                               // Time - O(n) | Space - O(1)
        T mini();                               // Time - O(n) | Space - O(1)
        Node<T>* search(T key);                 // Time - O(n) | Space - O(1)
        Node<T>* MoveToHeadsearch(T key);       // Time - O(n) | Space - O(1)
        void insert(int index, T x);            // Time - O(n) | Space - O(1)
        void insertAtLast(T x);                 // Time - O(1) | Space - O(1) If tail maintained
        void insertSorted(T x);                 // Time - O(n) | Space - O(1)
        bool isSorted();                        // Time - O(n) | Space - O(1)
        void removeDuplicates();                // Time - O(n) | Space - O(1)
        void reverseNodes();                    // Time - O(n) | Space - O(1)
        bool isLoop();                          // Time - O(n) | Space - O(1)
        void concat(LinkedList<T>* l2);         // Time - O(n) | Space - O(1)
        void mergeSorted(LinkedList<T>* l2);    // Time - O(m+n) | Space - O(1)
};

template<class T>
LinkedList<T> :: LinkedList(T arr[], int n){
     head = new Node<T>;
     head->data = arr[0];
     head->next = NULL;
     Node<T> *last = head;
     for(int i=1;i<n;i++){
         last->next = new Node<T>;
         last = last->next;
         last->data = arr[i];
         last->next = NULL;
     }
}

template<class T>
LinkedList<T> :: ~LinkedList(){
    Node<T> *p = head;
    while(head){
        head = head->next;
        delete p;
        p = head;
    }
}

template<class T>
void LinkedList<T> :: display(){       // Time - O(n) | Space - O(1)
    cout<<"Displaying LL: ";
    Node<T> *p = head;
    while(p){               
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

template<class T>
int LinkedList<T> :: length(){      // Time - O(n) | Space - O(1)
    int c = 0;                   
    Node<T> *p = head;
    while(p){
        c++;
        p = p->next;
    }
    return c;
}

template<class T>
T LinkedList<T> :: deleteNode(int index){    // Time - O(n) | Space - O(1)
    if(index < 1 || index > length())       
        return -1;
    
    Node<T> *p = head;
    if(index == 1){
        T x = head->data;
        head = head->next;
        delete p;
        return x;
    }
    else{
        for(int i=0; i<index-2; i++) 
            p = p->next;
        Node<T> *q = p->next;
        T x = q->data;
        p->next = q->next;
        delete q;
        return x;
    }
    return 0;
}

template<class T>
void LinkedList<T> :: insert(int index, T x){    // Time - O(n) | Space - O(1)
    if(index < 0 || index > length())   return;

    Node<T> *temp = new Node<T>;
    temp->data = x;
    
    if(index == 0){
        temp->next = head;
        head = temp;
        return;
    }
    else{
        Node<T> *p = head;
        while(--index)  p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
    return;
}

template<class T>
T LinkedList<T> :: sum(){        // Time - O(n) | Space - O(1)
    T s = 0;
    Node<T> *p = head;
    while(p){
        s += p->data;
        p = p->next;
    }
    return s;
}

template<class T>
T LinkedList<T> :: maxi(){        // Time - O(n) | Space - O(1)
    T m = head->data;
    Node<T> *p = head;
    while(p){
        m = max(m, p->data);
        p = p->next;
    }
    return m;
}

template<class T>
T LinkedList<T> :: mini(){        // Time - O(n) | Space - O(1)
    T m = head->data;
    Node<T> *p = head;
    while(p){
        m = min(m, p->data);
        p = p->next;
    }
    return m;
}

template<class T>
Node<T>* LinkedList<T> :: search(T key){        // Time - O(n) | Space - O(1)
    Node<T> *p = head;
    while(p){                       
        if(key == p->data)
            return p;
        p = p->next;
    }
    return 0;
}

template<class T>
Node<T>* LinkedList<T> :: MoveToHeadsearch(T key){        // Time - O(n) | Space - O(1)
    Node<T> *p = head;
    if(key == p->data)  return p;
    Node<T> *q = NULL;
    while(p){                       
        if(key == p->data){
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return 0;
}

template<class T>
void LinkedList<T> :: insertAtLast(T x){          // Time - O(1) | Space - O(1)
    // Node<T> *t = new Node<T>;
    // t->data = x;
    // t->next = NULL;
    // if(head){
    //     tail->next = t;
    //     tail = t;
    // }
    // else
    //     head = tail = t;
    // return;
    insert(length(),x);                          // Time - O(n) | Space - O(1)
}

template<class T>
void LinkedList<T> :: insertSorted(T x){          // Time - O(n) | Space - O(1)
    Node<T> *t = new Node<T>;
    t->data = x;
    t->next = NULL;
    
    if(head == NULL)
        head = t;
    else{
        if(head->data > x){
            t->next = head;
            head = t;
        }
        else{
            Node<T> *p = head;
            while(p->next && p->next->data < x)
                p = p->next;
            t->next = p->next;
            p->next = t;
        }
    }
}

template<class T>
bool LinkedList<T> :: isSorted(){       // Time - O(n) | Space - O(1)
    T x = head->data;
    Node<T> *p = head->next;
    while(p){
        if(p->data < x)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}

template<class T>
void LinkedList<T> :: removeDuplicates(){      // Time - O(n) | Space - O(1)
    Node<T> *p = head;
    while(p->next){
        if(p->data == p->next->data){
            Node<T> *q = p->next;
            p->next = q->next;
            delete q;
        }
        else
            p=p->next;
    }
    return;
}

template<class T>
void LinkedList<T> :: reverseNodes(){         // Time - O(n) | Space - O(1)
    Node<T> *p = head, *q = NULL, *r = NULL;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    head = q;
}

template<class T>
bool LinkedList<T> :: isLoop(){              // Time - O(n) | Space - O(1)
    Node<T> *p = head, *q = head;
    do{
        p = p->next;
        q = q->next;
        q = (q) ? q->next : NULL;
        if(p == q)  return true;
    }while(q);
    return false;
}

template<class T>
void LinkedList<T> :: concat(LinkedList<T>* l2){      // Time - O(n) | Space - O(1)
    Node<T> *p = head;
    while(p->next)  p=p->next;
    p->next = l2->head;
}

template<class T>
void LinkedList<T> :: mergeSorted(LinkedList<T>* l2){       // Time - O(m+n) | Space - O(1)
    Node<T> *p = this->head;
    Node<T> *s = l2->head;
    if(p->data >= s->data){
        head = s;
        s=s->next;
        head->next = p;
        p=head;
    }
    while(p->next && s){
        if(p->data <= s->data && p->next->data > s->data){
            Node<T> *temp = p->next;
            p->next = s;
            s=s->next;
            p=p->next;
            p->next = temp;
        }
        else{
            p=p->next;
        }
    }
    if(s) p->next = s;
}

int main() {
    int arr[] = {1,2,3,4,5};
    LinkedList<int> l(arr,5);
    
    l.display();
    
    cout<<"Length: "<<l.length()<<endl;
    
    cout<<"Data deleted: "<<l.deleteNode(0)<<endl;
    
    cout<<"Sum: "<<l.sum()<<endl;
    
    cout<<"Maximun: "<<l.maxi()<<endl;
    
    cout<<"Minimum: "<<l.mini()<<endl;
    
    cout<<"Search data: "<<l.search(4)->data<<endl;
    
    l.MoveToHeadsearch(3);
    cout<<"After moving to head: "; l.display();
    
    l.insert(5, 8);
    cout<<"After inserting: "; l.display();
    
    l.insertAtLast(10);
    cout<<"After inserting at last: "; l.display();
    
    l.insertSorted(5);
    cout<<"After inserting in sorted: "; l.display();
    
    cout<<"Is Sorted? "<<l.isSorted()<<endl;
    
    l.removeDuplicates();
    cout<<"After removing duplicates: "; l.display();
    
    l.reverseNodes();
    cout<<"After reversing: "; l.display();
    
    cout<<"Is Loop? "<<l.isLoop()<<endl;
    
    int arr2[] = {0,6,7,8,9};
    LinkedList<int>* l2 = new LinkedList<int>(arr2,5);
    l.concat(l2);
    cout<<"After Concatenating: "; l.display();
    
    if(l.isSorted()){
        l.mergeSorted(l2);
        cout<<"After merging sorted lists: "; l.display();
    }    
    
    return 0;
}
