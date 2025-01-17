#include <iostream>
using namespace std;

class Elements{
    public:
        int i, j, x;
};

class SparseMatrix{
    private:
        int m, n, num;
        Elements *e;
    public:
        SparseMatrix(){
            cout<<"Enter dimensions: ";
            cin>>m>>n;
            cout<<"Enter no. of non-zero elements: ";
            cin>>num;
            e = new Elements[num];
        }
        SparseMatrix(int m, int n, int num){
            this->m = m;
            this->n = n;
            this->num = num;
            e = new Elements[num];
        }
        ~SparseMatrix(){
            delete[] e;
        }
        void input(){
            cout<<"Enter i, j, x: "<<endl;
            for(int k=0;k<num;k++){
                cin>>e[k].i>>e[k].j>>e[k].x;
            }
        }
        void display(){
            cout<<"Displaying the elements: "<<endl;
            int k = 0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i == e[k].i && j == e[k].j){
                        cout<<e[k].x<<" ";
                        k++;
                    }
                    else
                        cout<<"0 ";
                }
                cout<<endl;
            }
        }
        friend SparseMatrix* add(SparseMatrix &s1, SparseMatrix &s2);
};

SparseMatrix* add(SparseMatrix &s1, SparseMatrix &s2){
    SparseMatrix *sum;
    if(s1.m != s2.m || s1.n != s2.n){
        cout<<"ERROR: Sum not possible"<<endl;
        return NULL;
    }
    sum = new SparseMatrix(s1.m, s1.n, s1.num+s2.num);
    int i=0, j=0, k=0;
    while(i<s1.num && j<s2.num){
        if(s1.e[i].i < s2.e[j].i){
            sum->e[k++] = s1.e[i++];
        }
        else if(s1.e[i].i > s2.e[j].i){
            sum->e[k++] = s2.e[j++];
        }
        else{
            if(s1.e[i].j < s2.e[j].j){
                sum->e[k++] = s1.e[i++];
            }
            else if(s1.e[i].j > s2.e[j].j){
                sum->e[k++] = s2.e[j++];
            }
            else{
                sum->e[k] = s1.e[i++];
                sum->e[k++].x += s2.e[j++].x;
            }
        }
    }
    while(i<s1.num){
        sum->e[k++] = s1.e[i++];
    }
    while(j<s2.num){
        sum->e[k++] = s2.e[j++];
    }
    sum->num = k;
    return sum;
}

int main() {
    SparseMatrix s;
    s.input();
    s.display();
    SparseMatrix p;
    p.input();
    p.display();
    SparseMatrix *q = add(s,p);
    if(q!=NULL){
        cout<<"Sum of matrices: "<<endl;
        q->display();
    }  
    return 0;
}
