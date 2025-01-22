#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string &str){                              // Time - O(n) | Space - O(n)
    stack<char> s;
    for(int i=0;i<str.length();i++){
        if(str[i] == '(')   s.push(str[i]);
        else if(str[i] == ')'){
            if(s.empty())   return false;
            s.pop();
        }
    }
    if(s.empty())   return true;
    return false;
}

bool isBalancedExtended(string &str){                      // Time - O(n) | Space - O(n)
    stack<char> s;
    for(int i=0;i<str.length();i++){
        if(str[i] == '{' || str[i] == '(' || str[i] == '[')   
            s.push(str[i]);
        else if(str[i] == ']' || str[i] == ')' || str[i] == '}'){
            if(s.empty())   return false;
            if(str[i]<50 && str[i] == s.top()+1)   s.pop();
            else if(str[i] == s.top()+2)   s.pop();
            else return false;
        }
    }
    if(s.empty())   return true;
    return false;
}

int main() {
    string s = "((a+b)*(c-d))";
    cout<<"Is balance?? : "<<isBalanced(s);
    string s2 = "{([a+b]*[c-d])/e}";
    cout<<"Is balance?? : "<<isBalancedExtended(s2);
    
    return 0;
}
