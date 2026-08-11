#include <bits/stdc++.h>
using namespace std;

/* ------------------- STL Map ------------------- */

/*
    Map is a data structure where we can store data in
    key-value pairs.

    The values can be accessed using their keys.
    The key-value pairs are automatically sorted by key.

    Important properties of map:
    - Each key must be unique.
    - Keys are stored in sorted order.
    - We can access a value using its key.
    - Insertion, deletion, and searching take O(log n) time.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> ages;

    // Insert key-value pairs
    ages["Md. Siam"] = 18;
    ages["John"] = 20;
    ages["Elon"] = 58;
    ages["Mark"] = 40;

    // accessing value using key
    // cout << ages.at("xmen"); // will throw an error if "xmen" is not in the map
    // cout << ages["xmen"]; // A new key "xmen" will be created with a default value of 0.

    // cout << ages["Md. Siam"];

    /*
        Traversing the Map
        We can use a loop to access all the key-value pairs.

        x.first  -> key
        x.second -> value
    */
    for (auto x : ages) {
        cout << x.first << " is "
             << x.second << " years old";
        cout << '\n';
    }


    /* ------------------- find() ------------------- */

    /*
    find() is used to find a key in the map.

    If the key exists, it returns an iterator
    pointing to that key-value pair.

    If the key does not exist, it returns ages.end().
    */
    auto it = ages.find("John");

    if (it != ages.end()) {
        cout << it->first << ' ' << it->second;
        cout << '\n';
    }


    /* ------------------- count() ------------------- */

    /*
    count() can be used to check if a key exists.

    It returns:
    1 -> if the key exists
    0 -> if the key does not exist
    */
    if (ages.count("John")) {
        cout << ages["John"];
    }

    cout << '\n';


    /* ------------------- insert() ------------------- */

    /*
    insert() can also be used to add a key-value pair.

    If the key already exists, insert() does not
    change its value.
    */
    ages.insert({"Alice", 22});


    /* ------------------- erase() ------------------- */

    /*
    erase() is used to remove a key-value pair.

    We can erase an element by using its key.
    */
    ages.erase("Alice");


    /* ------------------- size() ------------------- */

    // size() returns the number of key-value pairs.
    cout << "Size of the map: " << ages.size();
    cout << '\n';


    /* ------------------- empty() ------------------- */

    /*
    empty() checks whether the map is empty.

    It returns:
    true  -> if the map is empty
    false -> if the map is not empty
    */
    if (!ages.empty()) {
        cout << "The map is not empty";
    }

    cout << '\n';


    /* ------------------- begin() and end() ------------------- */

    /*
    begin() points to the first element.
    end() points just after the last element.

    Since map is sorted by key, begin() gives us
    the element with the smallest key.
    */
    auto first = ages.begin();

    cout << "First key: " << first->first;
    cout << '\n';


    /* ------------------- lower_bound() ------------------- */

    /*
    lower_bound(key) returns an iterator pointing to
    the first key that is greater than or equal to
    the given key.

    Example:
    lower_bound("John") -> "John" if it exists.
    */
    auto lb = ages.lower_bound("John");

    if (lb != ages.end()) {
        cout << "Lower bound: "
             << lb->first << ' '
             << lb->second;
        cout << '\n';
    }


    /* ------------------- upper_bound() ------------------- */

    /*
    upper_bound(key) returns an iterator pointing to
    the first key that is strictly greater than
    the given key.

    Example:
    upper_bound("John") -> first key after "John".
    */
    auto ub = ages.upper_bound("John");

    if (ub != ages.end()) {
        cout << "Upper bound: "
             << ub->first << ' '
             << ub->second;
        cout << '\n';
    }


    /* ------------------- clear() ------------------- */

    /*
    clear() removes all key-value pairs from the map.
    */
    // ages.clear();

    // cout << ages.size();

    return 0;
}