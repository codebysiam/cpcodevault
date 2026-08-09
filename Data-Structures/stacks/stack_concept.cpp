#include <bits/stdc++.h>
using namespace std;

/*
    ------------------------- Stacks -------------------------

    A stack is a LIFO (Last In, First Out) data structure.

    When we push an element into a stack, it is added
    to the top of the stack.

    When we pop an element from a stack, the element
    at the top is removed.

    Some real-life examples of stacks are:
    - A stack of books
    - A stack of plates
    - A stack of clothes
    - A stack of papers

    Stack = LIFO

    push(x)  -> add x
    pop()    -> remove top
    top()    -> access top
    empty()  -> check empty
    size()   -> number of elements

    All basic operations: O(1)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> nums;

    nums.push(10);
    nums.push(5);
    nums.push(15);
    nums.push(20);

    cout << "Size: " << nums.size() << '\n';

    if (!nums.empty()) {
        cout << "Top: " << nums.top() << '\n';

        // pop() does NOT return the removed value
        nums.pop();

        cout << "Top: " << nums.top() << '\n';
    }

    return 0;
}