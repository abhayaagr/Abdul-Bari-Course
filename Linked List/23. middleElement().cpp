#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*first = NULL;

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

void display(struct Node *p){       // Time - O(n) | Space - O(1)
    cout<<"Displaying LL: ";        
    while(p != NULL){               
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

struct Node* middleElement(struct Node* p){       // Time - O(n) | Space - O(1)
    struct Node *q = p;
    while(q){
        q = q->next;
        if(q)   q = q->next;
        if(q)   p = p->next;
    }
    return p;
}

int main() {
    vector<int> arr = {3,5,7,8,10,12};
    create(arr, arr.size());  
    display(first);
    
    cout<<middleElement(first)->data;
    return 0;
}
