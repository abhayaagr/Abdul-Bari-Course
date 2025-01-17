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
        SparseMatrix(){}
        SparseMatrix(int m, int n, int num){
            this->m = m;
            this->n = n;
            this->num = num;
            e = new Elements[num];
        }
        ~SparseMatrix(){
            delete[] e;
        }
        
        SparseMatrix operator+(SparseMatrix &s);
        friend istream & operator>>(istream &is, SparseMatrix &s);
        friend ostream & operator<<(ostream &os, SparseMatrix &s);
};

istream & operator>>(istream &is, SparseMatrix &s){
    cout<<"Enter dimensions: ";
    cin>>s.m>>s.n;
    cout<<"Enter no. of non-zero elements: ";
    cin>>s.num;
    s.e = new Elements[s.num];
    cout<<"Enter i, j, x: "<<endl;
    for(int k=0;k<s.num;k++){
        cin>>s.e[k].i>>s.e[k].j>>s.e[k].x;
    }
    return is;
}

ostream & operator<<(ostream &os, SparseMatrix &s){
    cout<<"Displaying the elements: "<<endl;
    int k = 0;
    for(int i=0;i<s.m;i++){
        for(int j=0;j<s.n;j++){
            if(i == s.e[k].i && j == s.e[k].j){
                cout<<s.e[k].x<<" ";
                k++;
            }
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    return os;
}


SparseMatrix SparseMatrix::operator+(SparseMatrix &s){
    if(m != s.m || n != s.n){
        cout<<"ERROR: Sum not possible"<<endl;
        SparseMatrix null(0,0,0);
        return null;
    }
    SparseMatrix *sum;
    sum = new SparseMatrix(m, n, num+s.num);
    int i=0, j=0, k=0;
    while(i<num && j<s.num){
        if(e[i].i < s.e[j].i){
            sum->e[k++] = e[i++];
        }
        else if(e[i].i > s.e[j].i){
            sum->e[k++] = s.e[j++];
        }
        else{
            if(e[i].j < s.e[j].j){
                sum->e[k++] = e[i++];
            }
            else if(e[i].j > s.e[j].j){
                sum->e[k++] = s.e[j++];
            }
            else{
                sum->e[k] = e[i++];
                sum->e[k++].x += s.e[j++].x;
            }
        }
    }
    while(i<num){
        sum->e[k++] = e[i++];
    }
    while(j<s.num){
        sum->e[k++] = s.e[j++];
    }
    sum->num = k;
    return *sum;
}

int main() {
    SparseMatrix s;
    cin>>s;
    cout<<s;
    
    SparseMatrix p;
    cin>>p;
    cout<<p;
    
    SparseMatrix q = s+p;
    cout<<"Sum of s and p: "<<endl<<q;
    return 0;
}
