#include <iostream>
using namespace std;

void checkAnagram1(char A[], char B[]){     //Time - O(n^2) | Space - O(1)
    bool b=1;
    for(int i=0;A[i]!='\0';i++){
        bool present = 0;
        int j;
        for(j=0;B[j]!='\0';j++){
            if(A[i] == B[j]){
                present = 1;
                break;
            }
        }
        if(present){
            B[j] = '0';
        }
        else{
            b = 0;
            cout<<"Not Anagram";
            break;
        }
    }
    if(b==1)
        cout<<"Anagram";
    return;
}

void checkAnagram2(char A[], char B[]){     //Time - O(n) | Space - O(1)
    int arr[26] = {0};
    bool b = 1;
    for(int i=0;A[i]!='\0';i++){
        arr[A[i]-'a']++;
    }
    for(int i=0;B[i]!='\0';i++){
        arr[B[i]-'a']--;

        if(arr[B[i]-'a'] < 0){
            cout<<"Not Anagram";
            b = 0;
            break;
        }
    }
    if(b == 1)
        for(int i=0;i<26;i++){
            if(arr[i] != 0){
                cout<<"Not Anagram";
                b = 0;
                break;
            }
        }
    if(b == 1)
        cout<<"Anagram";
        
    return;
}

int main() {
    char A[] = "silent";
    char B[] = "listen";
    checkAnagram2(A, B); 
    cout<<endl;
    checkAnagram1(A, B);    // Note: B is modified in this fn
    
    return 0;
}
