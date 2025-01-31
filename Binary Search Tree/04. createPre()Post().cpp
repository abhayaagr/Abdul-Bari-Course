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
    void createPre(T pre[], int n);   // Time - O(n) | Space - O(log n)
    void createPost(T pre[], int n);  // Time - O(n) | Space - O(log n) 
    void inOrder();                   // Time - O(n) | Space - O(log n)
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
void BST<T> :: createPre(T pre[], int n){
    if (n == 0) return;
    stack<Node<T>*> s;
    int i = 0;
    root = new Node(pre[i++]);
    Node<T>* p = root;
    while(i<n){
        if(pre[i] < p->data){
            Node<T>* temp = new Node(pre[i++]);
            p->left = temp;
            s.push(p);
            p = temp;
        }
        else{
            if(s.empty() || pre[i] < s.top()->data){
                Node<T>* temp = new Node(pre[i++]);
                p->right = temp;
                p = temp;
            }
            else{
                p = s.top();
                s.pop();
            }
        }
    }
}

template<class T>
void BST<T> :: createPost(T post[], int n){
    if (n == 0) return;
    stack<Node<T>*> s;
    int i = n-1;
    root = new Node(post[i--]);
    Node<T>* p = root;
    while(i>=0){
        if(post[i] > p->data){
            Node<T>* temp = new Node(post[i--]);
            p->right = temp;
            s.push(p);
            p = temp;
        }
        else{
            if(s.empty() || post[i] > s.top()->data){
                Node<T>* temp = new Node(post[i--]);
                p->left = temp;
                p = temp;
            }
            else{
                p = s.top();
                s.pop();
            }
        }
    }
}

int main() {
    BST<int> t;
    int pre[] = {30,20,10,15,25,40,50,45};
    t.createPre(pre, 8);
    t.inOrder();
    
    BST<int> s;
    int post[] = {15,10,25,20,45,50,40,30};
    s.createPost(post, 8);
    s.inOrder();
    return 0;
}
