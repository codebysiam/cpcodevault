#include <bits/stdc++.h>
using namespace std;

void rotate_right(vector<int>& a, int k){
    int n = a.size();
    if(!n) return;
    k%=n;
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());
}

void rotate_left(vector<int>& a, int k){
    int n = a.size();
    if(!n) return;
    k%=n;
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin() + (n-k));
    reverse(a.begin() + (n-k), a.end());
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    rotate_left(a, k);
    rotate_right(a, k);
    for(int x : a){
        cout << x << ' ';
    }
    // will print the same array because at first rotating left by k, then right by k. (intentional)
    return 0;
}


/* Example */
// a = {1, 2, 3, 4, 5, 6}; n = 6; k = 2

// Right Rotation
// Reverse(a) => {6, 5, 4, 3, 2, 1}
// Reverse(first k) => {5, 6, 4, 3, 2, 1}
// Reverse(last n-k) => {5, 6, 1, 2, 3, 4}
// -> {5, 4, 1, 2, 3, 4} Thats actually the answer


// Left Rotation
// Reverse(a) => {6, 5, 4, 3, 2, 1}
// Reverse(first n-k) => {3, 4, 5, 6, 2, 1}
// Reverse(last k) => {3, 4, 5, 6, 1, 2}
// -> {3, 4, 5, 6, 1, 2} Thats actullay the answer