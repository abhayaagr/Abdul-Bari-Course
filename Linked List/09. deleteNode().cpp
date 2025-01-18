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

int deleteNode(struct Node *p, int index){    // Time - O(n) | Space - O(1)
    if(index < 1 || index > count(p))       
        return -1;
                                        
    if(index == 1){
        int x = head->data;
        head = head->next;
        delete p;
        return x;
    }
    else{
        for(int i=0; i<index-2; i++) 
            p = p->next;
        struct Node* q = p->next;
        int x = q->data;
        p->next = p->next->next;
        delete q;
        return x;
    }
    return 0;
}

int main() {
    int arr[] = {8,3,9,7,6};
    create(arr, 5);
    display(head);
    
    cout<<"Deleted element: "<<deleteNode(head, 4)<<endl;
    display(head);
    return 0;
}
