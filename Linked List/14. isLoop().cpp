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

bool isLoop(Node* p){              // Time - O(n) | Space - O(1)
    Node* q = p;
    do{
        p = p->next;
        q = q->next;
        q = (q) ? q->next : NULL;
        if(p == q)  return true;
    }while(q);
    return false;
}

int main() {
    vector<int> arr = {3,5,7,8,10};
    create(arr, arr.size());  
    first->next->next->next->next->next = first;
    // display(first);
    
    cout<<isLoop(first);
    return 0;
}
