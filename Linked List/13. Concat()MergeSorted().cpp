#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*first = NULL, *second = NULL, *third = NULL;

void create(vector<int> arr, int n){
     struct Node *temp, *last;
     first = new Node;
     first->data = arr[0];
     first->next = NULL;
     last = first;
     for(int i=1;i<n;i++){
         temp = new Node;
         temp->data = arr[i];
         temp->next = NULL;
         last->next = temp;
         last = temp;
     }
}

void create2(vector<int> arr, int n){
     struct Node *temp, *last;
     second = new Node;
     second->data = arr[0];
     second->next = NULL;
     last = second;
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

void concat(Node* p, Node* q){      // Time - O(n) | Space - O(1)
    third = p;
    while(p->next)  p=p->next;
    p->next = q;
}

void merge(Node* p, Node* q){       // Time - O(m+n) | Space - O(1)
    Node* last = NULL;
    if(p->data < q->data){
        last = third = p;
        p = p->next;
        last->next = NULL;
    }
    else{
        last = third = q;
        q = q->next;
        last->next = NULL;
    }
    while(p && q){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p)   last->next = p;
    if(q)   last->next = q;
}

int main() {
    vector<int> arr = {3,5,7,8,10};
    create(arr, arr.size());
    vector<int> arr2 = {1,2,3,12,15,18,20};
    create2(arr2, arr2.size());
    
    display(first);
    display(second);
    
    // concat(first,second);
    // display(third);
    
    merge(first,second);
    display(third);
    
    return 0;
}
