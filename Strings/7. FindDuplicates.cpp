#include <iostream>
using namespace std;

void findDuplicates1(char A[]){     //Time - O(n^2) | Space - O(1)
    bool b=1;
    for(int i=0;A[i]!='\0';i++){
        for(int j=i+1;A[j]!='\0';j++){
            if(A[i] == A[j]){
                b = 0;
                cout<<A[i]<<" is repeated"<<endl;
                break;
            }
        }
    }
    if(b==1)
        cout<<"No duplicates";
}

void findDuplicates2(char A[]){     //Time - O(n) | Space - O(1)
    int arr[128] = {0};
    bool b=1;
    for(int i=0;A[i]!='\0';i++){
        arr[A[i]]++;
    }
    for(int i=0;i<128;i++){
        if(arr[i]>1){
            char c = i;
            cout<<c<<" is repeated"<<endl;
            b=0;
        }
    }
    if(b==1)
        cout<<"No duplicates";
}

// void findDuplicates3(char A[]){     //Time - O(n) | Space - O(1)
//     long long int H=0,x=0;
//     for(int i=0;A[i]!='\0';i++){
//         x=1;
//         x=x<<(A[i]-97);
//         if(x&H>0)
//             cout<<A[i]<<" is repeated"<<endl;
//         else
//             H = x|H;
//     }
// }

int main() {
    char A[] = "finding";
    findDuplicates1(A); 
    cout<<endl;
    findDuplicates2(A); 
    cout<<endl;
    // findDuplicates3(A); 
    
    return 0;
}
