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

  public:
    Tree(){root = NULL;}
    void create();          // Time - O(n) | Space - O(n)
    void preOrder();        // Time - O(n) | Space - O(log n) - O(n)
    void postOrder();       // Time - O(n) | Space - O(log n) - O(n)
    void inOrder();         // Time - O(n) | Space - O(log n) - O(n)
    void levelOrder();      // Time - O(n) | Space - O(log n) - O(n)
    void height();          // Time - O(n) | Space - O(log n) - O(n)
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
    stack<Node<T>*> s;
    while(p || !s.empty()){
        if(p){
            cout<<p->data<<" ";
            s.push(p);
            p = p->left;
        }
        else{
            p = s.top();
            s.pop();
            p = p->right;
        }
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
    stack<Node<T>*> s1,s2;
    s1.push(p);
    while(!s1.empty()){
        Node<T>* temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left)    s1.push(temp->left);
        if(temp->right)    s1.push(temp->right);
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
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
    stack<Node<T>*> s;
    while(p || !s.empty()){
        if(p){
            s.push(p);
            p = p->left;
        }
        else{
            p = s.top();
            s.pop();
            cout<<p->data<<" ";
            p = p->right;
        }
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

int main() {
    Tree<int> t;
    t.create();
    cout<<endl;
    t.preOrder();
    t.postOrder();
    t.inOrder();
    t.levelOrder();
    t.height();
    return 0;
}
