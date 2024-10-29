#include <iostream>
using namespace std;

int main() {
    string s = "John12?3";
    int i;
    bool valid=1;
    for(i=0;s[i]!='\0';i++){
        if(!(s[i]>='a' && s[i]<='z') && 
           !(s[i]>='A' && s[i]<='Z') && 
           !(s[i]>='0' && s[i]<='9')){
            valid = 0;
            break;
        }
    }
    if(valid)
        cout<<"Valid";
    else
        cout<<"Not Valid";
    return 0;
}
