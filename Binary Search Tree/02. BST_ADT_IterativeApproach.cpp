#include <bits/stdc++.h>
using namespace std;

template<class T>
class Node{
  public:
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T x){
        this->data = x;
        left = NULL;
        right = NULL;
    }
};

template<class T>
class BST{
  private:
    Node<T>* root;
    void inOrderTraversal(Node<T>* p);
    
  public:
    BST(){root = NULL;}
    void insert(T key);         // Time - O(nlog n) | Space - O(n)
    void search(T key);         // Time - O(log n) | Space - O(1)
    void inOrder();             // Time - O(n) | Space - O(log n) - O(n)
};

template<class T>
void BST<T> :: inOrderTraversal(Node<T>* p){
    if(p){
        inOrderTraversal(p->left);
        cout<<p->data<<" ";
        inOrderTraversal(p->right);
    }
}

template<class T>
void BST<T> :: inOrder(){
    if(!root)   throw runtime_error("BST Empty");
    cout<<"In-Order Traversal: ";
    inOrderTraversal(root);
    cout<<endl;
}

template<class T>
void BST<T> :: insert(T key){
    Node<T>* p = root;
    Node<T>* temp;
    if(root == NULL){
        root = new Node<T>(key);
        return;
    }
    while(p){
        temp = p;
        if(p->data == key)
            return;
        else if(p->data < key)
            p = p->right;
        else
            p = p->left;
    }
    p = new Node<T>(key);
    if(temp->data > key)
        temp->left = p;
    else
        temp->right = p;
}

template<class T>
void BST<T> :: search(T key){
    Node<T>* p = root;
    while(p){
        if(p->data == key)
            break;
        else if(p->data < key)
            p = p->right;
        else
            p = p->left;
    }
    if(p)
        cout<<p->data<<" found"<<endl;
    else
        cout<<key<<" not found"<<endl;
    return;
}

int main() {
    BST<int> t;
    t.search(20);
    t.insert(30);
    t.insert(20);
    t.insert(40);
    t.insert(10);
    t.insert(25);
    t.insert(35);
    t.insert(50);
    t.inOrder();
    t.search(21);
    t.search(20);
    return 0;
}
