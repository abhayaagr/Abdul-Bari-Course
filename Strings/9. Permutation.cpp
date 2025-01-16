#include <iostream>
using namespace std;

void permutation1(char A[]){          // Recursion -> BackTracking -> BruteForce
    static int count=0;               // Time - O(n!) | Space - O(n)
    static int k = 0;
    static bool available[10] = {0};
    static char res[10];
    if(A[k] == '\0'){
        res[k] = '\0';
        count++;
        cout<<count<<". "<<res<<endl;
        return;
    }
    for(int i=0;i<A[i]!='\0';i++){
        if(available[i] == 0){
            available[i] = 1;
            res[k++] = A[i];
            permutation1(A);
            available[i] = 0;
            k--;
        }
    }
}

void permutation2(char A[], int l, int h){      // Recursion -> Swapping -> BruteForce
    static int count = 0;                       // Time - O(n!) | Space - O(n)
    if(l == h){
        count++;
        cout<<count<<". "<<A<<endl;
        return;
    }
    else{
        for(int i=l; i<=h;i++){
            swap(A[i], A[l]);
            permutation2(A, l+1, h);
            swap(A[i], A[l]);
        }
    }
}

int main() {
    char A[] = "ABCDE";
    permutation1(A); 
    cout<<endl;
    permutation2(A,0,4);

    return 0;
}
