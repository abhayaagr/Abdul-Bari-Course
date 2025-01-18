#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*head = NULL, *tail = NULL;

void display(struct Node *p){       // Time - O(n) | Space - O(1)
    cout<<"Displaying LL: ";        
    while(p != NULL){               
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void insertAtLast(int x){          // Time - O(1) | Space - O(1)
    struct Node* t = new Node;
    t->data = x;
    t->next = NULL;
    if(head){
        tail->next = t;
        tail = t;
    }
    else
        head = tail = t;
    return;
}

int main() {
    
    for(int i=0;i<10;i++){
        insertAtLast(i);
        display(head);
    }
    return 0;
}
