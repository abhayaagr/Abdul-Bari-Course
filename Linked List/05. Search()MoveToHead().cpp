#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*head = NULL;

void create(int arr[], int n){
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
}

struct Node* search(struct Node* p, int key){        
    while(p){                       // Time - O(n) | Space - O(1)
        if(key == p->data)
            return p;
        p = p->next;
    }
    return 0;
}

struct Node* Rsearch(struct Node* p, int key){       
    if(p == NULL)                   // Time - O(n) | Space - O(n)
        return 0;
    if(key == p->data)
        return p;
    return Rsearch(p->next, key);
}

struct Node* MoveToHeadsearch(struct Node* p, int key){        
    if(key == p->data)  return p;
    Node* q = NULL;
    while(p){                       // Time - O(n) | Space - O(1)
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

int main() {
    int arr[] = {1,2,3,4,5};
    create(arr, 5);
    display(head);
    cout<<endl;
    Node* temp = search(head, 3);
    if(temp){
        cout<<temp->data<<" found"<<endl;
    }
    else
        cout<<"Not found"<<endl;
    
    temp = Rsearch(head, 5);
    if(temp){
        cout<<temp->data<<" found"<<endl;
    }
    else
        cout<<"Not found"<<endl;
        
    temp = MoveToHeadsearch(head, 4);
    temp = MoveToHeadsearch(head, 2);
    if(temp){
        cout<<temp->data<<" found"<<endl;
    }
    else
        cout<<"Not found"<<endl;
    display(head);
    return 0;
}
