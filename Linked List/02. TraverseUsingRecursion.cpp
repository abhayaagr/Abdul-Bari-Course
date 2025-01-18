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

int main() {
    int arr[] = {1,2,3,4,5};
    create(arr, 5);
    Rdisplay(head);
    return 0;
}
