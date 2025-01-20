#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*head = NULL;

void create(vector<int> arr, int n){
     struct Node *temp, *last;
     head = new Node;
     head->data = arr[0];
     head->next = NULL;
     last = head;
     for(int i=1;i<n;i++){
         temp = new Node;
         temp->data = arr[i];
         temp->next = NULL;
         last->next = temp;
         last = temp;
     }
}

void display(struct Node *p){       // Time - O(n) | Space - O(1)
    cout<<"Displaying LL: ";        
    while(p != NULL){               
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void reverseArr(struct Node* p){      // Time - O(n) | Space - O(n)
    vector<int> arr;
    while(p){
        arr.push_back(p->data);
        p=p->next;
    }
    int i = arr.size()-1;
    p = head;
    while(p){
        p->data = arr[i--];
        p=p->next;
    }
    return;
}

void reverseNodes(Node* p){         // Time - O(n) | Space - O(1)
    Node* q = NULL, *r = NULL;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    head = q;
}

void Rreverse(Node* p, Node* q=NULL){   // Time - O(n) | Space - O(n)
    if(p){
        Rreverse(p->next, p);
        p->next = q;
    }
    else{
        head = q;
    }
}

int main() {
    vector<int> arr = {3,5,7,8,10};
    create(arr, arr.size());
    display(head);
    
    reverseArr(head);
    display(head);
    
    reverseNodes(head);
    display(head);
    
    Rreverse(head);
    display(head);
    return 0;
}
