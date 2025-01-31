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
    Node<T>* insert(Node<T>* p, T key);
    Node<T>* search(Node<T>* p, T key);
    void inOrderTraversal(Node<T>* p);
    
  public:
    BST(){root = NULL;}
    void insert(T key);         // Time - O(nlog n) | Space - O(log n)
    void search(T key);         // Time - O(log n) | Space - O(log n)
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
Node<T>* BST<T> :: insert(Node<T>* p, T key){
    if(!p){
        Node<T>* temp = new Node<T>(key);
        return temp;
    }
    if(key < p->data)
        p->left = insert(p->left, key);
    else if(key > p->data)
        p->right = insert(p->right, key);
    return p;
}

template<class T>
void BST<T> :: insert(T key){
    root = insert(root, key);
}

template<class T>
Node<T>* BST<T> :: search(Node<T>* p, T key){
    if(!p)  return NULL;
    if(p->data == key)
        return p;
    else if(p->data > key)
        return search(p->left, key);
    else
        return search(p->right, key);
}

template<class T>
void BST<T> :: search(T key){
    Node<T>* temp = search(root, key);
    if(temp)
        cout<<temp->data<<" found"<<endl;
    else
        cout<<key<<" not found"<<endl;
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
