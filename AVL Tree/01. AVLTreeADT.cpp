#include <bits/stdc++.h>
using namespace std;

template<class T>
class Node{
  public:
    T data;
    Node<T> *left;
    Node<T> *right;
    int height;
    Node(T x){
        this->data = x;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

template<class T>
class AVLTree{
  private:
    Node<T> *root;
    Node<T>* insert(Node<T>* p, T key);
    int height(Node<T>* p);
    int balanceFactor(Node<T>* p);
    Node<T>* LLRotation(Node<T>* p);
    Node<T>* LRRotation(Node<T>* p);
    Node<T>* RRRotation(Node<T>* p);
    Node<T>* RLRotation(Node<T>* p);
    void inOrderTraversal(Node<T>* p);

  public:
    AVLTree(){root = NULL;}
    void insert(T key);         
    void inOrder();             
};

template<class T>
void AVLTree<T> :: inOrderTraversal(Node<T>* p){
    if(p){
        inOrderTraversal(p->left);
        cout<<p->data<<" ";
        inOrderTraversal(p->right);
    }
}

template<class T>
void AVLTree<T> :: inOrder(){
    if(!root)   throw runtime_error("BST Empty");
    cout<<"In-Order Traversal: ";
    inOrderTraversal(root);
    cout<<endl;
}

template<class T>
int AVLTree<T> :: height(Node<T>* p){
    int hl, hr;
    hl = (p && p->left) ? p->left->height : 0;
    hr = (p && p->right) ? p->right->height : 0;
    return (hl>hr) ? hl+1 : hr+1;
}

template<class T>
int AVLTree<T> :: balanceFactor(Node<T>* p){
    int hl, hr;
    hl = (p && p->left) ? p->left->height : 0;
    hr = (p && p->right) ? p->right->height : 0;
    return hl-hr;
}

template<class T>
Node<T>* AVLTree<T> :: LLRotation(Node<T>* p){
    Node<T>* pl = p->left;
    Node<T>* plr = pl->right;
    pl->right = p;
    p->left = plr;
    p->height = height(p);
    pl->height = height(pl);
    if(root == p)
        root = pl;
    return pl;
}

template<class T>
Node<T>* AVLTree<T> :: LRRotation(Node<T>* p){
    Node<T>* pl = p->left;
    Node<T>* plr = pl->right;
    pl->right = plr->left;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;
    p->height = height(p);
    pl->height = height(pl);
    plr->height = height(plr);
    if(root == p)
        root = plr;
    return plr;
}

template<class T>
Node<T>* AVLTree<T> :: RRRotation(Node<T>* p){
    Node<T>* pr = p->right;
    Node<T>* prl = pr->left;
    pr->left = p;
    p->right = prl;
    p->height = height(p);
    pr->height = height(pr);
    if(root == p)
        root = pr;
    return pr;
}

template<class T>
Node<T>* AVLTree<T> :: RLRotation(Node<T>* p){
    Node<T>* pr = p->right;
    Node<T>* prl = pr->left;
    pr->left = prl->right;
    p->right = prl->left;
    prl->left = p;
    prl->right = pr;
    p->height = height(p);
    pr->height = height(pr);
    prl->height = height(prl);
    if(root == p)
        root = prl;
    return prl;
}

template<class T>
Node<T>* AVLTree<T> :: insert(Node<T>* p, T key){
    if(!p){
        Node<T>* temp = new Node<T>(key);
        return temp;
    }
    if(key < p->data)
        p->left = insert(p->left, key);
    else if(key > p->data)
        p->right = insert(p->right, key);
    p->height = height(p);
    
    if(balanceFactor(p) == 2 && balanceFactor(p->left) == 1)
        return LLRotation(p);
    else if(balanceFactor(p) == 2 && balanceFactor(p->left) == -1)
        return LRRotation(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->right) == -1)
        return RRRotation(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->right) == 1)
        return RLRotation(p);
    return p;
}

template<class T>
void AVLTree<T> :: insert(T key){
    root = insert(root, key);
}

int main() {
    AVLTree<int> t;
    t.insert(50);
    t.insert(10);
    t.insert(20);
    
    t.inOrder();
    return 0;
}
