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
    cout<<endl;
}

int count(struct Node* p){      // Time - O(n) | Space - O(1)
    int c = 0;                  // Using loops
    while(p){
        c++;
        p = p->next;
    }
    return c;
}

void insert(struct Node *p, int index, int x){
    if(index < 0 || index > count(p))   return;
                                        // Time - O(n) | Space - O(1)
    struct Node* temp = new Node;
    temp->data = x;
    
    if(index == 0){
        temp->next = head;
        head = temp;
        return;
    }
    else{
        struct Node* p = head;
        while(--index)  p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
    return;
}

int main() {
    int arr[] = {1,2,3,4,5};
    create(arr, 5);
    display(head);
    
    for(int i=0;i<6;i++){
        insert(head,2*i,(i+1)*3);
        display(head);
    }
    return 0;
}
