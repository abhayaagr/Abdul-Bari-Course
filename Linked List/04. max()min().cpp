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

int maxi(struct Node* p){        // Time - O(n) | Space - O(1)
    int m = INT_MIN;
    while(p){
        m = max(m, p->data);
        p = p->next;
    }
    return m;
}

int Rmaxi(struct Node* p){       // Time - O(n) | Space - O(n)
    int x = 0;                   // Using Recursion
    if(p == 0)                  
        return INT_MIN;
    x = Rmaxi(p->next);
    return x>p->data ? x:p->data;
}

int mini(struct Node* p){        // Time - O(n) | Space - O(1)
    int m = INT_MAX;
    while(p){
        m = min(m, p->data);
        p = p->next;
    }
    return m;
}

int Rmini(struct Node* p){       // Time - O(n) | Space - O(n)
    int x = 0;                   // Using Recursion
    if(p == 0)                  
        return INT_MAX;
    x = Rmini(p->next);
    return x<p->data ? x:p->data;
}

int main() {
    int arr[] = {1,2,3,4,5};
    create(arr, 5);
    display(head);
    cout<<endl;
    cout<<"Max of elements: "<<maxi(head)<<endl;
    cout<<"Max of elements: "<<Rmaxi(head)<<endl;
    cout<<"Min of elements: "<<mini(head)<<endl;
    cout<<"Min of elements: "<<Rmini(head)<<endl;
    return 0;
}
