#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x){
    return (x=='+' || x=='-' || x=='*' || x=='/') ? 0 : 1;
}

// Precedence Table
int pre(char x){
    if(x=='+' || x=='-')  return 1;
    else if(x=='*' || x=='/')  return 2;
    return 0;
}

string infixToPostfix(string infix){            // Time - O(n) | Space - O(n)
    stack<char> s;
    string postfix = "";
    int i = 0;
    while(infix[i] != '\0'){
        if(isOperand(infix[i]))
            postfix += infix[i++];
        else{
            if(s.empty() || pre(infix[i]) > pre(s.top()))
                s.push(infix[i++]);
            else{
                postfix += s.top();
                s.pop();
            }
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main() {
    string s = "a+b*c-d/e";
    
    cout<<"Infix : "<<s<<endl;
    cout<<"Postfix : "<<infixToPostfix(s)<<endl;
    
    return 0;
}
