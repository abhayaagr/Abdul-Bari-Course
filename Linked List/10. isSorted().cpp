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

bool isSorted(struct Node* p){
    int x = INT_MIN;
    while(p){
        if(p->data < x)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}

int main() {
    int arr[] = {1,2,3,4,5};
    create(arr, 5);
    display(head);
    
    cout<<"Is Sorted? : "<<isSorted(head)<<endl;
    return 0;
}
