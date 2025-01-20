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

void Rdisplay(struct Node *p){      // Time - O(n) | Space - O(n)
    static bool flag = 1;
    if(p != head || flag){
        flag = 0;
        cout<<p->data<<" ";
        Rdisplay(p=p->next);
    }
}

int main() {
    vector<int> arr = {3,5,7,8,10};
    createCircular(arr, arr.size());  
    display(head);
    cout<<"Displaying Circular LL Recursively: ";
    Rdisplay(head);
    
    return 0;
}
