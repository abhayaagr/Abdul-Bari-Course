#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}*head = NULL;

void createDoubly(vector<int> arr, int n){        // Time - O(n) | Space - O(n)
     struct Node *temp, *last;
     head = new Node;
     head->data = arr[0];
     head->prev = NULL;
     head->next = NULL;
     last = head;
     for(int i=1;i<n;i++){
         temp = new Node;
         temp->data = arr[i];
         temp->prev = last;
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

void reverseNodes(Node* p){         // Time - O(n) | Space - O(1)
    Node* temp;
    while(p){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p=p->prev;
        if(p && p->next ==NULL)  head = p;
    }
}

int main() {
    vector<int> arr = {3,5,7,8,10};
    createDoubly(arr, arr.size());  
    display(head);
    reverseNodes(head);
    display(head);

    return 0;
}
