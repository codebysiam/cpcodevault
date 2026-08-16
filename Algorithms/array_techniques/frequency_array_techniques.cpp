#include <bits/stdc++.h>
using namespace std;

/* ------------------ Frequency Array: First Repeating Number (Positive) -------------------- */

/*
Frequency Array Technique:

In CP, the frequency array technique is a method where we use the indexes of an array
to store the frequency (occurrence count) of numbers from another array. It helps us
solve many problems efficiently, especially those involving counting, duplicates,
and frequency-based operations.
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = INT_MIN;
    for(auto&x: a){
        cin >> x;
        mx = max(x, mx);
    }
    vector<int> freq(mx+1);
    for(int x: a){
        freq[x]++;
    }
    for(int x: a){
        if(freq[x] > 1){
            cout << x << ' ';
            break;
        }
    }
    return 0;
}