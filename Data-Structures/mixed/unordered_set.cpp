#include <bits/stdc++.h>
using namespace std;

/* ---------------------- Unordered Set (Hash Set) ---------------------- */
/*
    An unordered_set stores unique elements without maintaining any
    particular order. It uses a hash table internally.

    Basic operations such as insertion, deletion, and searching takes
    O(1) time on average, but O(n) in the worst case.

    It is useful when:
    - We need to store only unique elements.
    - Sorted order is not required.
    - We want fast average-case insertion, deletion, and lookup.
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    // Creating an unordered_set.
    // Duplicate elements are automatically ignored.
    unordered_set<int> us = {1, 2, 3, 4, 1, 2};

    // Inserting elements.
    us.insert(5);
    us.insert(5); // Duplicate, so it will not be added.
    us.insert(6);

    // Iterating through the unordered_set.
    // The order of elements is not guaranteed.
    for (int x : us) {
        cout << x << ' ';
    }
    cout << '\n';

    // Removing an element.
    us.erase(6);

    // Iterating again after deletion.
    for (int x : us) {
        cout << x << ' ';
    }
    cout << '\n';

    // Getting the number of elements.
    cout << "Size of the hash set: " << us.size() << '\n';

    // Checking whether the set is empty.
    if (us.empty()) {
        cout << "The hash set is empty.";
    } else {
        cout << "The hash set is not empty.";
    }
    cout << '\n';

    // Checking whether an element exists using count().
    if (us.count(5)) {
        cout << "5 is present in the hash set.";
    } else {
        cout << "5 is not present in the hash set.";
    }
    cout << '\n';

    // Searching for an element using find().
    int x = 4;
    auto it = us.find(x);

    if (it != us.end()) {
        cout << "Found: " << *it;
    } else {
        cout << x << " not found!";
    }
    cout << '\n';

    // 
    return 0;
}