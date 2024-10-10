#include <bits/stdc++.h>
using namespace std;

void toUpper(string s){
    int i;
    for(i=0;s[i]!='\0';i++){
        // s[i] -= 32;
        s[i] += 'A' - 'a';
    }
    cout<<s<<endl;
}

void toLower(string s){
    int i;
    for(i=0;s[i]!='\0';i++){
        // s[i] += 32;
        s[i] -= 'A' - 'a';
    }
    cout<<s<<endl;
}

void toggle(string s){
    int i;
    for(i=0;s[i]!='\0';i++){
        if(s[i]>='a' && s[i]<='z')
            s[i] += 'A' - 'a';
        else
            s[i] -= 'A' - 'a';
    }
    cout<<s<<endl;
}

int main() {
    string s = "welcome";
    toUpper(s);
    string a = "WELCOME";
    toLower(a);
    string str = "WELcome";
    toggle(str);
    return 0;
}
