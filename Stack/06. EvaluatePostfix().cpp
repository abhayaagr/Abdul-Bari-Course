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

int evaluatePostfix(string postfix){            // Time - O(n) | Space - O(n)
    stack<int> s;
    for(int i=0; postfix[i] != '\0'; i++){
        if(isOperand(postfix[i]))
            s.push(postfix[i] - '0');
        else{
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            int c;
            switch(postfix[i]){
                case '+' : c = a + b; break;
                case '-' : c = a - b; break;
                case '*' : c = a * b; break;
                case '/' : c = a / b; break;
                case '^' : c = a ^ b; break;
                default  : c = 0; break;
            }
            s.push(c);
        }
    }
    return s.top();
}

int main() {
    string s = "a*b+c/d-e";
    cout<<"Infix : "<<s<<endl;
    cout<<"Postfix : "<<infixToPostfix(s)<<endl<<endl;
    
    int a = 3, b = 5, c = 6, d = 2, e = 4;
    string s1 = "35*62/+4-";
    cout<<"Postfix : "<<s1<<endl;
    cout<<"Actual Value: "<<a*b+c/d-e<<endl;
    cout<<"Calculated Value: "<<evaluatePostfix(s1)<<endl;
    
    return 0;
}
