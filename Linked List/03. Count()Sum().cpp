#include <iostream>
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

void display(struct Node *p){       //Traversal using Loop
    while(p != NULL){               // Time - O(n) | Space - O(1)
        cout<<p->data<<" ";
        p = p->next;
    }
}

void Rdisplay(struct Node *p){      //Traversal using Recursion
    if(p != NULL){                  // Time - O(n) | Space - O(n)
        // cout<<p->data<<" ";     //Prints forward
        Rdisplay(p->next);
        cout<<p->data<<" ";     //Prints backward
    }
}

int count(struct Node* p){      // Time - O(n) | Space - O(1)
    int c = 0;                  // Using loops
    while(p){
        c++;
        p = p->next;
    }
    return c;
}

int Rcount(struct Node* p){     // Time - O(n) | Space - O(n)
    if(p == 0)                  // Using Recursion
        return 0;
    return Rcount(p->next) + 1;
}

int sum(struct Node* p){        // Time - O(n) | Space - O(1)
    int s = 0;                  // Using loops
    while(p){
        s += p->data;
        p = p->next;
    }
    return s;
}

int Rsum(struct Node* p){       // Time - O(n) | Space - O(n)
    if(p == 0)                  // Using Recursion
        return 0;
    return Rsum(p->next) + p->data;
}

int main() {
    int arr[] = {1,2,3,4,5};
    create(arr, 5);
    Rdisplay(head);
    cout<<endl;
    cout<<"Count of elements: "<<count(head)<<endl;
    cout<<"Count of elements: "<<Rcount(head)<<endl;
    cout<<"Sum of elements: "<<sum(head)<<endl;
    cout<<"Sum of elements: "<<Rsum(head)<<endl;
    return 0;
}
