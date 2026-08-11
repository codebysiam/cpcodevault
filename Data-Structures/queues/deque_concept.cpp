#include <bits/stdc++.h>
using namespace std;

/* ----------------- Deque (Double-Ended Queue) ----------------------*/
/*
    A deque is a type of queue where we can insert and remove elements
    from both the front and back of the queue. It also supports accessing
    elements using an index.

    Unlike std::queue, std::deque is a regular container, so it supports
    iterators and can be traversed using a range-based for loop.

    Some commonly used deque methods:
        push_back()   -> inserts an element at the back
        push_front()  -> inserts an element at the front
        pop_back()    -> removes an element from the back
        pop_front()   -> removes an element from the front
        front()       -> returns the first element
        back()        -> returns the last element
        at(i)         -> accesses the element at index i
        size()        -> returns the number of elements
        empty()       -> checks whether the deque is empty
        clear()       -> removes all elements

    A deque also provides begin() and end(), so we can iterate through
    its elements using iterators or a range-based for loop.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> dq;

    // Insert elements from both ends
    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);

    cout << "Deque: ";
    for (int x : dq) {
        cout << x << ' ';
    }
    cout << '\n';

    // Access the first and last elements
    cout << "Front: " << dq.front() << '\n';
    cout << "Back: " << dq.back() << '\n';

    // Remove from the front and insert at the back
    dq.pop_front();
    dq.push_back(40);

    cout << "After operations: ";
    for (int x : dq) {
        cout << x << ' ';
    }
    cout << '\n';

    // Access an element using its index
    cout << "Item at index 1: " << dq[1] << '\n';

    // at() also accesses an element using its index
    cout << "Item at index 0: " << dq.at(0) << '\n';

    // Remove the last element
    dq.pop_back();

    // Check whether the deque is empty
    if (dq.empty()) {
        cout << "Deque is empty.\n";
    } else {
        cout << "Deque is not empty.\n";
    }

    // Get the number of elements
    cout << "Size of the deque: " << dq.size() << '\n';

    // Remove all elements
    dq.clear();

    cout << "Size after clear(): " << dq.size() << '\n';

    return 0;
}