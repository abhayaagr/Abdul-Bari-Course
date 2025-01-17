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
};

int main() {
    SparseMatrix s;
    s.input();
    s.display();
    return 0;
}
