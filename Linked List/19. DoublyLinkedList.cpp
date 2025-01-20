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

int main() {
    vector<int> arr = {3,5,7,8,10};
    createDoubly(arr, arr.size());  
    display(head);
    cout<<"Length of LL: "<<length(head);

    return 0;
}
