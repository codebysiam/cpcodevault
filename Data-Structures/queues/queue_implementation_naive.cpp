#include <bits/stdc++.h>
using namespace std;

/* ------------------------ Queue Implementation Using Array (Naive) ------------------------ */
/*
    This is a simple queue implementation using an array. We are doing this to better
    understand how queues work. This is not the most efficient implementation of a queue,
    but it demonstrates how a queue works under the hood.

    First, we initialize an integer array with a given size. When we push something,
    we check if the array is full or not. If it is full, we log a message. Otherwise,
    we push the element at the back by increasing the index k.

    When we pop, we check if the queue has elements to pop. If it does, we simply shift
    all the remaining elements one position to the left and decrease k by 1 to make
    room for another element.

    All operations here except pop() take O(1) time. pop() takes O(n) time because
    we have to shift the remaining elements to the left.
*/

class Queue{
    public:
        int *arr;
        int size;
        int k = -1;
    Queue(int size){
        this->size = size;
        this->arr = new int[size];
    }
    ~Queue(){
        delete[] arr;
    }
    void push(int x){
        if(k < size-1){
            arr[++k] = x;
        }else{
            cout << "Queue Overflow";
            cout << '\n';
        }
    }
    void pop(){
        if(k >= 0){
            for(int i = 1; i<=k; i++){
                arr[i-1] = arr[i];
            }
            k--;
        }else{
            cout << "Queue Underflow";
            cout << '\n';

        }
    }
    int front(){
        return arr[0];
    }
    int back(){
        return arr[k];
    }
    bool empty(){
        return k < 0;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Queue q(4);

    q.push(10);
    q.push(4);
    q.push(20);
    q.push(40);

    cout << "Front: " << q.front();
    cout << '\n';
    q.pop();
    q.pop();
    cout << "Front after pop: " << q.front();
    cout << '\n';
    cout << "Back after pop: " << q.back();
    cout << '\n';
    if(q.empty()){
        cout << "Queue is empty.";
    }else{
        cout << "Queue is not empty.";
    }

    return 0;
}