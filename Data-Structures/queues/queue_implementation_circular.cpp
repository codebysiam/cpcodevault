#include <bits/stdc++.h>
using namespace std;

/* -------------------------------- Queue Implementation O(1) Using Circular Array -------------------------------- */
/*
    This is a queue implementation using a fixed-size array.
    
    A naive array-based queue can make pop() inefficient because after
    removing the front element, we may need to shift all remaining
    elements to the left. That makes pop() O(n).

    To make pop() O(1), we use a circular array.
    The idea is simple: instead of physically moving elements, we keep
    track of two positions in the array:

        left  -> points to the current front element.
        right -> points to the next free position where a new element
                 will be inserted.

    We also keep track of the current number of elements using currSize.

    When we push an element, we insert it at the 'right' position and
    then move 'right' forward by one. Since the array is circular, we
    use modulo to wrap around to the beginning when necessary:

        right = (right + 1) % sizeLim;

    For example, if the array size is 4:

        index:    0   1   2   3
                  ↑           ↑
                start        end

    After reaching index 3, the next position becomes index 0.

    pop() works similarly. Instead of shifting all elements, we simply
    move 'left' forward by one:

        left = (left + 1) % sizeLim;

    This is what makes pop() O(1).

    The currSize variable is important because left == right can happen
    in both of these situations:

        1. The queue is empty.
        2. The queue is completely full.

    By keeping track of currSize, we can distinguish between these two
    states.

    Therefore, with this circular-array technique, the basic queue
    operations push(), pop(), front(), and back() can all be performed
    in O(1) time.
*/

class MyQueue{
    public:
        int *arr;
        int sizeLim;
        int left = 0;
        int right = 0;
        int currSize = 0;
    MyQueue(int size){
        if(size < 1) throw invalid_argument("Queue size must be a positive integer.");
        sizeLim = size;
        arr = new int[size];
    }
    void push(int x){
        if(currSize >= sizeLim) throw overflow_error("Queue Overflow!");
        arr[right] = x;
        right = (right + 1) % sizeLim;
        currSize++;
    }
    void pop(){
        if(empty()) throw underflow_error("Queue Underflow!");
        left = (left + 1) % sizeLim;
        currSize--;
    }
    int front(){
        if(empty()) throw length_error("Queue is empty.");
        return arr[left];
    }
    int back(){
        if(empty()) throw length_error("Queue is empty.");
        return arr[(right-1+sizeLim) % sizeLim];
    }
    bool empty(){
        return currSize == 0;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    MyQueue q(4);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << "front of queue: " << q.front();
    cout << '\n';
    cout << "back of queue: " << q.back();
    cout << '\n';
    q.pop();
    q.push(50);
    cout << "front of queue after pop: " << q.front();
    cout << '\n';
    cout << "back of queue after pop & push: " << q.back();
    cout << '\n';
    if(q.empty()){
        cout << "Queue is empty.";
    }else{
        cout << "Queue is not empty.";
    }
    return 0;
}