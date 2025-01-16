#include <iostream>
using namespace std;

class ToeplitzMatrix{
  private:
    int *A;
    int n;
    
  public:
    ToeplitzMatrix(){
        n = 2;
        A = new int[2*n - 1];
    }
    ToeplitzMatrix(int n){
        this->n = n;
        A = new int[2*n - 1];
    }
    ~ToeplitzMatrix(){
        delete []A;
    }
    void set(int i, int j, int x){
        if(i<=j)
            A[j-i] = x;
        else
            A[n+i-j-1] = x;
    }
    int get(int i, int j){
        if(i<=j)
            return A[j-i];
        else
            return A[n+i-j-1];
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
                set(i,j,x);
            }
        }
    }
};

int main() {
    int n;
    cout<<"Enter Dimension: ";
    cin>>n;
    ToeplitzMatrix m(n);
    m.input();
    m.display();
    return 0;
}
