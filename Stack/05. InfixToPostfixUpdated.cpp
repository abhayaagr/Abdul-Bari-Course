#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='(' || x==')' || x=='^')
        return 0;
    return 1;
}

// Outside Stack Precedence Table
int outPre(char x){
    if(x=='+' || x=='-')  return 1;
    else if(x=='*' || x=='/')  return 3;
    else if(x=='^')  return 6;
    else if(x=='(')  return 7;
    else if(x==')')  return 0;
    return -1;
}

// Inside Stack Precedence Table
int inPre(char x){
    if(x=='+' || x=='-')  return 2;
    else if(x=='*' || x=='/')  return 4;
    else if(x=='^')  return 5;
    else if(x=='(')  return 0;
    return -1;
}

string infixToPostfix(string infix){            // Time - O(n) | Space - O(n)
    stack<char> s;
    string postfix = "";  
    int i = 0;
    while(infix[i] != '\0'){
        if(isOperand(infix[i]))
            postfix += infix[i++];
        else{
            if(s.empty() || outPre(infix[i]) > inPre(s.top()))
                s.push(infix[i++]);
            else if(outPre(infix[i]) == inPre(s.top())){
                s.pop();
                i++;
            }
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
    string s = "((a+b)*c)-d^e^f";
    
    cout<<"Infix : "<<s<<endl;
    cout<<"Postfix : "<<infixToPostfix(s)<<endl;
    
    return 0;
}
