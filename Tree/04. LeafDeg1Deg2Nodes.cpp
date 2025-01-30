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
    int countNodes(Node<T>* p);
    int countLeafNodes(Node<T>* p);
    int countNonLeafNodes(Node<T>* p);
    int countDeg1Nodes(Node<T>* p);
    int countDeg2Nodes(Node<T>* p);

  public:
    Tree(){root = NULL;}
    void create();              // Time - O(n) | Space - O(n)
    void countNodes();          // Time - O(n) | Space - O(log n) - O(n)
    void countLeafNodes();      // Time - O(n) | Space - O(log n) - O(n)
    void countNonLeafNodes();   // Time - O(n) | Space - O(log n) - O(n)
    void countDeg1Nodes();      // Time - O(n) | Space - O(log n) - O(n)
    void countDeg2Nodes();      // Time - O(n) | Space - O(log n) - O(n)
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
int Tree<T> :: countLeafNodes(Node<T>* p){
    int x, y;
    if(!p)  return 0;
    x = countLeafNodes(p->left);
    y = countLeafNodes(p->right);
    if(!p->left && !p->right)    
        return x+y+1;
    return x+y;
}

template<class T>
void Tree<T> :: countLeafNodes(){
    cout<<"Number of Leaf Nodes in Tree: "<<countLeafNodes(root)<<endl;
}

template<class T>
int Tree<T> :: countNonLeafNodes(Node<T>* p){
    int x, y;
    if(!p)  return 0;
    x = countNonLeafNodes(p->left);
    y = countNonLeafNodes(p->right);
    if(p->left || p->right)    
        return x+y+1;
    return x+y;
}

template<class T>
void Tree<T> :: countNonLeafNodes(){
    cout<<"Number of Non-Leaf Nodes in Tree: "<<countNonLeafNodes(root)<<endl;
}

template<class T>
int Tree<T> :: countDeg1Nodes(Node<T>* p){
    int x, y;
    if(!p)  return 0;
    x = countDeg1Nodes(p->left);
    y = countDeg1Nodes(p->right);
    if((!p->left && p->right) || (p->left && !p->right))
    // L'R + LR' = L^R = if(p->left ^ p->right)
        return x+y+1;
    return x+y;
}

template<class T>
void Tree<T> :: countDeg1Nodes(){
    cout<<"Number of Deg1 Nodes in Tree: "<<countDeg1Nodes(root)<<endl;
}

template<class T>
int Tree<T> :: countDeg2Nodes(Node<T>* p){
    int x, y;
    if(!p)  return 0;
    x = countDeg2Nodes(p->left);
    y = countDeg2Nodes(p->right);
    if(p->left && p->right)
        return x+y+1;
    return x+y;
}

template<class T>
void Tree<T> :: countDeg2Nodes(){
    cout<<"Number of Deg2 Nodes in Tree: "<<countDeg2Nodes(root)<<endl;
}

int main() {
    Tree<int> t;
    t.create();
    cout<<endl;
    t.countNodes();
    t.countLeafNodes();
    t.countNonLeafNodes();
    t.countDeg1Nodes();
    t.countDeg2Nodes();
    return 0;
}
