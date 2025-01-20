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

int length(struct Node* p){      // Time - O(n) | Space - O(1)
    int len = 0;                  
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

void insert(struct Node *p, int index, int x){      // Time - O(n) | Space - O(1)
    if(index < 0 || index > length(p))   return;
    
    struct Node* temp = new Node;
    temp->data = x;
    
    if(index == 0){
        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;
        head = temp;
    }
    else{
        while(--index)  p = p->next;
        temp->next = p->next;
        p->next = temp;
        temp->prev = p;
        if(temp->next)  temp->next->prev = temp;
    }
    return;
}

int main() {
    vector<int> arr = {3,5,7,8,10};
    createDoubly(arr, arr.size());  
    display(head);
    insert(head,5,0);
    display(head);

    return 0;
}
