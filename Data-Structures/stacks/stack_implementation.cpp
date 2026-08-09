#include <bits/stdc++.h>
using namespace std;

/* ------------------ Stack Implementation ------------------ */
/*
    In the code below, we implement a Stack using an array
    to understand how a Stack works under the hood.
*/

class Stack{
    public:
        int *arr;
        int size;
        int i = -1;
    Stack (int size){
        this->size = size;
        arr = new int[size];
    }
    ~Stack(){
        delete[] arr;
    }
    void push(int x){
        if(size - 1 > i){
            arr[++i] = x;
        }else{
            throw overflow_error("Stack Overflow!");
        }
    }
    void pop(){
        if(i >= 0){
            i--;
        }else{
            throw underflow_error("Stack Underflow!");
        }
    }
    int top(){
        if(i >= 0){
            return arr[i];
        }else{
            throw length_error("Stack Empty!");
        }
    }
    bool empty(){
        return i < 0;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Stack s(4);
    s.push(2);
    s.push(5);
    s.push(4);
    s.push(8);
    s.pop();
    s.pop();
    s.pop();
    cout << s.top();
    cout << '\n';
    if(s.empty()){
        cout << "Stack is empty";
    }else{
        cout << "Stack is not empty";
    }
    return 0;
}