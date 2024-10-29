#include <iostream>
using namespace std;

void reverse1(char s[]){    // Uses extra space
    int i;
    for(i=0;s[i]!='\0';i++){}
    char A[i];
    i--;
    for(int j=0;i>=0;i--,j++){
        A[j] = s[i];
    }
    cout<<A;
}

void reverse2(char s[]){    // Two point approach
    int i;
    for(i=0;s[i]!='\0';i++){}
    i--;
    for(int j=0;j<i;i--,j++){
        swap(s[j],s[i]);
    }
    cout<<s;
}

int main() {
    char A[] = "python";
    reverse1(A);
    cout<<endl;
    reverse2(A);
    return 0;
}
