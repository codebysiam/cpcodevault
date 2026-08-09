#include <bits/stdc++.h>
using namespace std;

/* ----------------------------------- Valid Parentheses O(n) ----------------------------------- */
/*
    To determine whether a string contains balanced or valid pairs of parentheses, we traverse
    through the entire string. If we find a left bracket, we push it onto a stack. If we find a
    right bracket, we first check whether the stack is empty. If the stack is empty, it means
    there is no left bracket available to match with the current right bracket, so the string
    is invalid and we return false.

    If the stack is not empty, we get the top element of the stack. The top of the stack represents
    the latest left bracket, which should be the first one to be matched with the current right
    bracket. We then check whether the top element is the corresponding left bracket for the
    current right bracket. If it is, we pop it from the stack. If it is not, we return false because
    the brackets are not properly matched.

    After traversing the entire string, we check whether the stack is empty. Every valid pair of
    brackets should have been matched and removed from the stack by this point.

    If the stack is empty, it means all brackets were properly matched, so the parentheses are
    valid and we return true. If the stack is not empty, it means there are some left brackets
    that do not have corresponding right brackets, so we return false.
*/

bool is_valid_parentheses(const string& str){
    stack<char> s;
    for(char x: str){
        if(x == '(' || x == '{' || x == '['){
            s.push(x);
        }else if(x == ')' || x == '}' || x == ']'){
            if(s.empty()) return false;
            char top = s.top();
            if(
                x == ')' && top == '(' ||
                x == '}' && top == '{' ||
                x == ']' && top == '[' 
            ){
                s.pop();
            }else{
                return false;
            }
        }
    }
    return s.empty();
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string str;
    getline(cin, str);
    cout << (is_valid_parentheses(str) ? "valid parentheses" : "invalid parentheses!");
    return 0;
}