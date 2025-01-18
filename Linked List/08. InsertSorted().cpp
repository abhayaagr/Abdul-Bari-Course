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

void insertSorted(int x){          // Time - O(n) | Space - O(1)
    struct Node *t = new Node;
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
            struct Node* p = head;
            while(p->next && p->next->data < x)
                p = p->next;
            t->next = p->next;
            p->next = t;
        }
    }
}

int main() {
    int arr[] = {3,7,9,15,20};
    create(arr, 5);
    display(head);
    
    insertSorted(18);
    insertSorted(0);
    insertSorted(5);
    insertSorted(7);
    insertSorted(20);
    display(head);
    
    return 0;
}
