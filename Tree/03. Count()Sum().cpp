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
class Tree{
  private:
    Node<T> *root;
    void preOrderTraversal(Node<T>* p);
    void postOrderTraversal(Node<T>* p);
    void inOrderTraversal(Node<T>* p);
    int height(Node<T>* p);
    int countNodes(Node<T>* p);
    int sumNodes(Node<T>* p);

  public:
    Tree(){root = NULL;}
    void create();          // Time - O(n) | Space - O(n)
    void preOrder();        // Time - O(n) | Space - O(log n) - O(n)
    void postOrder();       // Time - O(n) | Space - O(log n) - O(n)
    void inOrder();         // Time - O(n) | Space - O(log n) - O(n)
    void levelOrder();      // Time - O(n) | Space - O(log n) - O(n)
    void height();          // Time - O(n) | Space - O(log n) - O(n)
    void countNodes();      // Time - O(n) | Space - O(log n) - O(n)
    void sumNodes();        // Time - O(n) | Space - O(log n) - O(n)
};

template<class T>
void Tree<T> :: create(){
    queue<Node<T>*> q;
    Node<T> *curr, *next;
    T x;
    cout<<"Enter root value: ";
    cin>>x;
    root = new Node<T>(x);
    q.push(root);
    while(!q.empty()){
        curr = q.front();
        q.pop();
        cout<<"Enter left child of "<<curr->data<<": ";
        cin>>x;
        if(x!=-1){
            next = new Node<T>(x);
            curr->left = next;
            q.push(next);
        }
        cout<<"Enter right child of "<<curr->data<<": ";
        cin>>x;
        if(x!=-1){
            next = new Node<T>(x);
            curr->right = next;
            q.push(next);
        }
    }
}

template<class T>
void Tree<T> :: preOrderTraversal(Node<T>* p){
    if(p){
        cout<<p->data<<" ";
        preOrderTraversal(p->left);
        preOrderTraversal(p->right);
    }
}

template<class T>
void Tree<T> :: preOrder(){
    if(!root)   throw runtime_error("Tree Empty");
    cout<<"Pre-Order Traversal: ";
    preOrderTraversal(root);
    cout<<endl;
}

template<class T>
void Tree<T> :: postOrderTraversal(Node<T>* p){
    if(p){
        postOrderTraversal(p->left);
        postOrderTraversal(p->right);
        cout<<p->data<<" ";
    }
}

template<class T>
void Tree<T> :: postOrder(){
    if(!root)   throw runtime_error("Tree Empty");
    cout<<"Post-Order Traversal: ";
    postOrderTraversal(root);
    cout<<endl;
}

template<class T>
void Tree<T> :: inOrderTraversal(Node<T>* p){
    if(p){
        inOrderTraversal(p->left);
        cout<<p->data<<" ";
        inOrderTraversal(p->right);
    }
}

template<class T>
void Tree<T> :: inOrder(){
    if(!root)   throw runtime_error("Tree Empty");
    cout<<"In-Order Traversal: ";
    inOrderTraversal(root);
    cout<<endl;
}

template<class T>
void Tree<T> :: levelOrder(){
    if(!root)   throw runtime_error("Tree Empty");
    cout<<"Level-Order Traversal: ";
    Node<T> *curr;
    queue<Node<T>*> q;
    q.push(root);
    cout<<root->data<<" ";
    while(!q.empty()){
        curr = q.front();
        q.pop();
        if(curr->left){
            cout<<curr->left->data<<" ";
            q.push(curr->left);
        }
        if(curr->right){
            cout<<curr->right->data<<" ";
            q.push(curr->right);
        }
    }
    cout<<endl;
}

template<class T>
int Tree<T> :: height(Node<T>* p){
    int x = 0, y = 0;
    if(!p)  return 0;
    x = height(p->left);
    y = height(p->right);
    return (x>y) ? x+1 : y+1;
}

template<class T>
void Tree<T> :: height(){
    cout<<"Height of Tree: "<<height(root)<<endl;
}

template<class T>
int Tree<T> :: countNodes(Node<T>* p){
    int x, y;
    if(!p)  return 0;
    x = countNodes(p->left);
    y = countNodes(p->right);
    return x+y+1;
}

template<class T>
void Tree<T> :: countNodes(){
    cout<<"Number of Nodes in Tree: "<<countNodes(root)<<endl;
}

template<class T>
int Tree<T> :: sumNodes(Node<T>* p){
    int x, y;
    if(!p)  return 0;
    x = sumNodes(p->left);
    y = sumNodes(p->right);
    return x+y+p->data;
}

template<class T>
void Tree<T> :: sumNodes(){
    cout<<"Sum of Nodes in Tree: "<<sumNodes(root)<<endl;
}

int main() {
    Tree<int> t;
    t.create();
    cout<<endl;
    t.preOrder();
    t.postOrder();
    t.inOrder();
    t.levelOrder();
    t.height();
    t.countNodes();
    t.sumNodes();
    return 0;
}
