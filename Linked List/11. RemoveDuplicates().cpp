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

void removeDuplicates(struct Node* p){      // Time - O(n) | Space - O(1)
    while(p->next){
        if(p->data == p->next->data){
            struct Node* q = p->next;
            p->next = q->next;
            delete q;
        }
        else
            p=p->next;
    }
    return;
}

int main() {
    vector<int> arr = {3,5,5,8,8,8,10,10,10,10};
    create(arr, arr.size());
    display(head);
    
    removeDuplicates(head);
    display(head);
    return 0;
}
