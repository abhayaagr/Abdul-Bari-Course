#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*head = NULL;

void createCircular(vector<int> arr, int n){        // Time - O(n) | Space - O(n)
     struct Node *temp, *last;
     head = new Node;
     head->data = arr[0];
     head->next = head;
     last = head;
     for(int i=1;i<n;i++){
         temp = new Node;
         temp->data = arr[i];
         temp->next = head;
         last->next = temp;
         last = temp;
     }
}

void display(struct Node *p){       // Time - O(n) | Space - O(1)
    cout<<"Displaying Circular LL: ";        
    do{               
        cout<<p->data<<" ";
        p = p->next;
    }while(p != head);
    cout<<endl;
}

int length(struct Node* p){      // Time - O(n) | Space - O(1)
    int c = 0;                  
    do{
        c++;
        p = p->next;
    }while(p != head);
    return c;
}

void insert(struct Node *p, int index, int x){      // Time - O(n) | Space - O(1)
    if(index < 0 || index > length(p)){
        cout<<"ERROR: Invaild index for insertion"<<endl;
        return;
    }
    
    struct Node* temp = new Node;
    temp->data = x;
    
    if(!head){
        head = temp;
        head->next = head;
    }
    
    if(index == 0){
        temp->next = head;
        while(p->next != head)  p = p->next;
        p->next = temp;
        head = temp;
        return;
    }
    else{
        while(--index)  p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
    return;
}

int main() {
    vector<int> arr = {3,5,7,8,10};
    createCircular(arr, arr.size());  
    display(head);
    insert(head,0,0);
    display(head);
    
    return 0;
}
