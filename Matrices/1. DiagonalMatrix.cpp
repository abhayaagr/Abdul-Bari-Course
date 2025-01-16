#include <iostream>
using namespace std;

class DiagonalMatrix{
  private:
    int *A;
    int n;
    
  public:
    DiagonalMatrix(){
        n = 2;
        A = new int[2];
    }
    DiagonalMatrix(int n){
        this->n = n;
        A = new int[n];
    }
    ~DiagonalMatrix(){
        delete []A;
    }
    void set(int i, int j, int x){
        if(i==j)
            A[i] = x;
    }
    int get(int i, int j){
        if(i == j){
            cout<<A[i]<<endl;
            return A[i];
        }
        return 0;
    }
    void display(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j)
                    cout<<A[i]<<" ";
                else
                    cout<<0<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    DiagonalMatrix m(5);
    m.set(0,0,1);
    m.set(1,1,2);
    m.set(2,2,3);
    m.set(3,3,4);
    m.set(4,4,5);
    m.get(3,3);
    m.display();
    return 0;
}
