#include <bits/stdc++.h>
using namespace std;

/* ------------------------------- Queues O(1) ------------------------------- */
/*
    A queue is a container that follows the FIFO (First In, First Out)
    principle.

    When we push an element into a queue, it is added to the back.
    When we pop an element, the element at the front is removed.

    C++ provides an STL implementation of a queue using `queue<T>`.

    Some commonly used queue operations are:
        - push()  : adds an element to the back of the queue.
        - pop()   : removes the element from the front of the queue.
        - front() : returns the element at the front.
        - back()  : returns the element at the back.
        - empty() : checks whether the queue is empty.
        - size()  : returns the number of elements in the queue.

    Note:
    Before using front(), back(), or pop(), we should make sure that
    the queue is not empty. Calling these operations on an empty queue
    results in undefined behavior.
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    queue<int> q;
    q.push(10);
    q.push(4);
    q.push(20);
    q.push(2);
    cout << "Current front of queue is: " << q.front();
    cout << '\n';
    q.pop();
    cout << "Front of queue after pop: " << q.front();
    cout << '\n';
    cout << "Back of queue is: " << q.back();
    cout << '\n';
    if(q.empty()){
        cout << "Queue is empty.";
    }else{
        cout << "Queue is not empty.";
    }
    cout << '\n';
    cout << "Current queue size is: " << q.size();
    return 0;
}