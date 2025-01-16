#include <iostream>
using namespace std;

class TriDiagonalMatrix{
  private:
    int *A;
    int n;
    
  public:
    TriDiagonalMatrix(){
        n = 2;
        A = new int[3*n - 2];
    }
    TriDiagonalMatrix(int n){
        this->n = n;
        A = new int[3*n - 2];
    }
    ~TriDiagonalMatrix(){
        delete []A;
    }
    void set(int i, int j, int x){
        if((i-j) == 1)
            A[i-1] = x;
        else if((i-j) == 0)
            A[n-1+i] = x;
        else if((i-j) == -1)
            A[2*n-1+i] = x;
    }
    int get(int i, int j){
        if((i-j) == 1)
            return A[i-1];
        else if((i-j) == 0)
            return A[n-1+i];
        else if((i-j) == -1)
            return A[2*n-1+i];
        return 0;
    }
    void display(){
        cout<<"Displaying the elements"<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }
    void input(){
        cout<<"Enter all elements"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                set(i,j,j+1);
            }
        }
    }
};

int main() {
    int n;
    cout<<"Enter Dimension: ";
    cin>>n;
    TriDiagonalMatrix m(n);
    m.input();
    m.display();
    return 0;
}
