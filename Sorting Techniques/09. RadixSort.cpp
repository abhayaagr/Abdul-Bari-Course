#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int x){
        this->data = x;
        next = NULL;
    }
};

int findMax(int A[], int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        if(A[i] > maxi)
            maxi = A[i];
    }
    return maxi;
}

void insert(Node*& p, int ele){
    if(p == NULL){
        p = new Node(ele);
    }
    else{
        Node* temp = p;
        while(temp->next)
            temp = temp->next;
        temp->next = new Node(ele);
    }
}

int deleteNode(Node*& p){
    int x = p->data;
    Node* temp = p;
    p = p->next;  
    delete temp;  
    return x;
}

void radixSort(int A[], int n){          // Time - O(n) | Space - O(n)
    int max = findMax(A,n);
    Node* bins[10];
    int j = 1;
    while(max/j > 0){
        for(int i=0; i<10; i++){
            bins[i] = NULL;
        }
        for(int i=0; i<n; i++){
            int digit = (A[i]/j)%10;
            insert(bins[digit], A[i]);
        }
        int p = 0;
        for(int i=0; i<10; i++){
            while(bins[i] != NULL){
                A[p++] = deleteNode(bins[i]);
            } 
        }
        j *= 10;
    }
}

int main() {
    int A[] = {5,7,9,5,1,52,14,52,2,8};
    radixSort(A, 10);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";

    return 0;
}
