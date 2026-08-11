#include <bits/stdc++.h>
using namespace std;
/* ------------------------- STL Linked List ------------------------- */
/*
    A linked list is a linear data structure made of nodes.

    Each node contains:
        1. Data
        2. A pointer/reference to another node.

    Singly Linked List:

        [10 | *] -> [20 | *] -> [30 | NULL]

    Doubly Linked List:

        NULL <- [10] <-> [20] <-> [30] -> NULL

    std::list in C++ is a doubly linked list.

    Unlike array/vector, linked-list elements are stored in
    non-contiguous memory.


    Method              Time       Explanation
    --------------------------------------------------------------
    push_back(x)        O(1)       Add x at the end.
    push_front(x)       O(1)       Add x at the beginning.
    pop_back()          O(1)       Remove the last element.
    pop_front()         O(1)       Remove the first element.
    front()             O(1)       Access the first element.
    back()              O(1)       Access the last element.

    insert(it, x)       O(1)*      Insert x before iterator it.
    emplace(it, x)      O(1)*      Construct element directly at it.
    erase(it)           O(1)*      Remove element pointed by it.

    remove(x)           O(n)       Remove all elements equal to x.
    remove_if(fn)       O(n)       Remove elements matching a condition.

    sort()              O(n log n) Sort the list.
    reverse()           O(n)       Reverse the order of elements.
    unique()            O(n)       Remove consecutive duplicates.
    merge(other)        O(n + m)   Merge two sorted lists.
    splice()            O(1)**     Transfer elements from another list.

    size()              O(1)       Return number of elements.
    empty()             O(1)       Check whether the list is empty.
    clear()             O(n)       Remove all elements.
    resize(n)           O(n)       Change the number of elements.
    swap(other)         O(1)       Exchange contents of two lists.

    begin()             O(1)       Iterator to the first element.
    end()               O(1)       Iterator past the last element.
    rbegin()            O(1)       Reverse iterator to the last element.
    rend()              O(1)       Reverse iterator past the first element.

    O(1) when the iterator is already available.
    O(1) for transferring the whole list/single element.

    Note:
    std::list does NOT support random access.
    ll[index] and ll.at(index) are not supported.
    Use iterators to reach a particular position.
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    list<int> ll = {10, 20};

    // Add elements.
    ll.push_back(40);                  // O(1) -> Add at the end.
    ll.push_front(5);                  // O(1) -> Add at the beginning.

    // Move iterator to index 2.
    auto it = ll.begin();
    advance(it, 2);                    // O(n) -> Move iterator forward.

    // Insert multiple elements before iterator.
    ll.insert(it, 4, 15);              // O(1)* -> Insert four 15s.

    // Access first and last elements.
    cout << "Front: " << ll.front() << '\n'; // O(1)
    cout << "Back : " << ll.back() << '\n';  // O(1)

    // Remove first and last elements.
    ll.pop_front();                    // O(1) -> Remove first.
    ll.pop_back();                     // O(1) -> Remove last.

    // Erase an element using an iterator.
    ll.erase(ll.begin());              // O(1) -> Remove first element.

    // Add duplicate values.
    ll.push_back(20);                  // O(1)
    ll.push_back(20);                  // O(1)

    // Remove all occurrences of a value.
    ll.remove(20);                     // O(n) -> Remove all 20s.

    // Add some values.
    ll.push_back(2);                   // O(1)
    ll.push_back(3);                   // O(1)
    ll.push_back(4);                   // O(1)

    // Remove elements based on a condition.
    ll.remove_if([](int x){            // O(n) -> Remove even numbers.
        return x % 2 == 0;
    });

    // Sort the list.
    ll.sort();                         // O(n log n) -> Ascending order.

    // Reverse the list.
    ll.reverse();                      // O(n) -> Reverse the order.

    // Remove consecutive duplicates.
    ll.unique();                       // O(n) -> Deletes Consecutive Duplicates

    // Get the number of elements.
    cout << "Size: " << ll.size() << '\n'; // O(1)

    // Check whether the list is empty.
    cout << "Empty: " << boolalpha
         << ll.empty() << '\n';        // O(1)

    // Traverse the list.
    cout << "List: ";
    for(int x: ll){                     // O(n) -> Visit every element.
        cout << x << ' ';
    }
    cout << '\n';

    // Remove all elements.
    ll.clear();                         // O(n) -> Empty the list.

    return 0;
}