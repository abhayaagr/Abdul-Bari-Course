#include <iostream>
using namespace std;

class LowerTriMatrix{
  private:
    int *A;
    int n;
    
  public:
    LowerTriMatrix(){
        n = 2;
        A = new int[3];
    }
    LowerTriMatrix(int n){
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~LowerTriMatrix(){
        delete []A;
    }
    void set(int i, int j, int x){
        if(i>=j)
            A[i*(i+1)/2 + j] = x;
    }
    int get(int i, int j){
        if(i >= j){
            cout<<A[i*(i+1)/2 + j]<<endl;
            return A[i*(i+1)/2 + j];
        }
        return 0;
    }
    void display(){
        cout<<"Displaying the elements"<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i >= j)
                    cout<<A[i*(i+1)/2 + j]<<" ";
                else
                    cout<<0<<" ";
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
    LowerTriMatrix m(n);
    m.input();
    m.display();
    return 0;
}
