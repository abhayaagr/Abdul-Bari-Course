#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void insertSorted(Node* &head, int key){          
    Node *t = new Node(key);
    
    if(head == NULL)
        head = t;
    else{
        if(head->data > key){
            t->next = head;
            head = t;
        }
        else{
            Node* p = head;
            while(p->next && p->next->data < key)
                p = p->next;
            t->next = p->next;
            p->next = t;
        }
    }
}

int search(Node* p, int key){        
    while(p){                       
        if(key == p->data)
            return p->data;
        else if(key < p->data)
            return -1;
        else
            p = p->next;
    }
    return -1;
}

int hashFn(int key){
    return key%10;
}

void insert(Node* H[], int key){
    int index = hashFn(key);
    insertSorted(H[index], key);
}

int main() {
    Node* H[10];
    for(int i=0; i<10; i++)
        H[i] = NULL;
    insert(H, 5);
    insert(H, 15);
    insert(H, 52);
    insert(H, 23);
    insert(H, 2);
    int key = 2;
    cout<<search(H[hashFn(key)], key)<<endl;
    key = 52;
    cout<<search(H[hashFn(key)], key)<<endl;
    key = 3;
    cout<<search(H[hashFn(key)], key)<<endl;
    return 0;
}
