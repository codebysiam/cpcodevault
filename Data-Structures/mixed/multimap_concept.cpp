#include <bits/stdc++.h>
using namespace std;

/* -------------------------- STL Multimap -------------------------- */
/*
    A multimap stores key-value pairs where duplicate keys are allowed,
    unlike map, where every key must be unique. The elements are stored
    in sorted order according to their keys, and elements with the same
    key are kept together. It does not provide direct access by index
    and does not support the [] operator. Common operations include
    insert(), emplace(), find(), count(), and equal_range().

    The equal_range(key) function returns a pair of iterators representing
    the range of all elements with the given key. The first iterator
    points to the first matching element, while the second points just
    past the last matching element. This makes it convenient to iterate
    over all values associated with a particular key.
*/


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multimap<string, string> company;

    company.emplace("Google", "Alice");
    company.emplace("Google", "Bob");
    company.emplace("Meta", "David");
    company.emplace("Google", "John");
    company.emplace("Meta", "Larry");

    // Get all employees working at Google
    auto google_range = company.equal_range("Google");

    cout << "Google group: ";
    for (auto itr = google_range.first; itr != google_range.second; ++itr) {
        cout << itr->second << ' ';
    }
    cout << '\n';

    // Get all employees working at Meta
    auto meta_range = company.equal_range("Meta");

    cout << "Meta group: ";
    for (auto itr = meta_range.first; itr != meta_range.second; ++itr) {
        cout << itr->second << ' ';
    }
    cout << '\n';

    // Count the number of employees in each company
    cout << "Number of Google employees: "
         << company.count("Google") << '\n';

    cout << "Number of Meta employees: "
         << company.count("Meta") << '\n';

    return 0;
}