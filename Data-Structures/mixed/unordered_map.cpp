#include <bits/stdc++.h>
using namespace std;

/* -------------------- Unordered Map (Hash Map) -------------------- */
/*
    An unordered_map is similar to a map, but it does not maintain
    its keys in sorted order.

    It is very efficient for inserting, accessing, and removing
    elements using a key. The average time complexity for these
    operations is O(1).

    unordered_map uses a hash table under the hood, which allows
    fast key-based access.

    It is especially useful in cases such as frequency counting,
    where we need to store a value associated with each key.
*/



int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    unordered_map<char, int> freq;
    string a = "Hello Friends!";
    for(char x: a){
        freq[x]++;
    }
    for(auto x: freq){
        cout << x.first << " : " << x.second;
        cout << '\n';
    }
    cout << "e occurred " << freq['e'] << " times";
    return 0;
}