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

int deleteNode(struct Node *p, int index){    // Time - O(n) | Space - O(1)
    if(index < 1 || index > length(p))       
        return -1;
     
    if(index == 1){
        while(p->next != head)  p=p->next;
        p->next = head->next;
        p = head;
        int x = head->data;
        head = head->next;
        delete p;
    }
    else{
        for(int i=0; i<index-2; i++) 
            p = p->next;
        struct Node* q = p->next;
        int x = q->data;
        p->next = q->next;
        delete q;
    }
    return x;
}

int main() {
    vector<int> arr = {3,5,7,8,10};
    createCircular(arr, arr.size());  
    // display(head);
    deleteNode(head,5);
    display(head);
    
    return 0;
}
