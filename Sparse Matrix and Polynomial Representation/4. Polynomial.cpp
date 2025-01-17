#include <iostream>
using namespace std;

class Term{
    public:
        int coeff, exp;
};

class Polynomial{
    private:
        int n;
        Term *t;
    public:
        Polynomial(){
            n = 0;
            t = NULL;
        }
        Polynomial(int n){
            this->n = n;
            t = new Term[n];
        }
        ~Polynomial(){
            delete []t;
        }
        void input(){
            if(n == 0){
                cout<<"Enter number of terms: ";
                cin>>n;
                t = new Term[n];
            }
            cout<<"Enter coefficients and exponents:"<<endl;
            for(int i=0;i<n;i++){
                cin>>t[i].coeff>>t[i].exp;
            }
        }
        void display(){
            cout<<"Polynomial is : ";
            for(int i=0;i<n;i++){
                cout<<t[i].coeff<<"x"<<t[i].exp;
                if(i != n-1)    cout<<" + ";
            }
            cout<<endl;
        }
        friend Polynomial add(Polynomial &p1, Polynomial &p2);
};

Polynomial add(Polynomial &p1, Polynomial &p2){
    Polynomial ans(p1.n + p2.n);
    int i=0, j=0, k=0;
    while(i<p1.n && j<p2.n){
        if(p1.t[i].exp > p2.t[j].exp)
            ans.t[k++] = p1.t[i++];
        else if(p1.t[i].exp < p2.t[j].exp)
            ans.t[k++] = p2.t[j++];
        else{
            ans.t[k] = p1.t[i++];
            ans.t[k++].coeff += p2.t[j++].coeff;
        }
    }
    while(i<p1.n)
        ans.t[k++] = p1.t[i++];
    while(j<p2.n)
        ans.t[k++] = p2.t[j++];
    ans.n = k;
    return ans;
}

int main() {
    Polynomial p;
    p.input();
    p.display();
    
    Polynomial s;
    s.input();
    s.display();
    
    Polynomial q = add(s,p);
    q.display();
    return 0;
}
