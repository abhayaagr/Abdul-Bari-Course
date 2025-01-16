#include <iostream>
using namespace std;

class UpperTriMatrix{
  private:
    int *A;
    int n;
    
  public:
    UpperTriMatrix(){
        n = 2;
        A = new int[3];
    }
    UpperTriMatrix(int n){
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~UpperTriMatrix(){
        delete []A;
    }
    void set(int i, int j, int x){
        if(i<=j)
            A[j*(j+1)/2 + i] = x;
    }
    int get(int i, int j){
        if(i <= j){
            cout<<A[j*(j+1)/2 + i]<<endl;
            return A[j*(j+1)/2 + i];
        }
        return 0;
    }
    void display(){
        cout<<"Displaying the elements"<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i <= j)
                    cout<<A[j*(j+1)/2 + i]<<" ";
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
    UpperTriMatrix m(n);
    m.input();
    m.display();
    return 0;
}
