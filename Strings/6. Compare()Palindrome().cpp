#include <iostream>
using namespace std;

void compare(char A[], char B[]){
    int i=0;
    bool b=0;
    while(A[i] != '\0' && B[i] != '\0'){
        if(A[i] == B[i])    i++;
        else if(A[i] < B[i]){
            cout<<"Smaller";    //Based on ASCII values
            b=1;
            break;
        }
        else{
            cout<<"Greater";    //Based on ASCII values
            b=1;
            break;
        }
    }
    if(A[i] == '\0' && B[i] != '\0')
        cout<<"Smaller";        //Based on length
    else if(A[i] != '\0' && B[i] == '\0')
        cout<<"Greater";        //Based on lenght
    else if(b==0)
        cout<<"Equal";
    return;
}

void checkPalindrome(char A[]){
    int i = 0;
    while(A[i] != '\0') i++;
    i--;
    int j=0;
    bool b=1;
    while(j<i){
        if(A[i] == A[j]){
            j++;
            i--;
        }
        else{
            cout<<"Not palindrome";
            b=0;
            break;
        }
    }
    if(b==1)    cout<<"Palindrome";
    return;
}

int main() {
    char A[] = "Painting";
    char B[] = "Painter";
    compare(A,B);
    cout<<endl;
    char C[] = "abcddcba";
    checkPalindrome(C);
    return 0;
}
