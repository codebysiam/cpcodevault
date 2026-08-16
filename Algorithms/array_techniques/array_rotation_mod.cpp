/**
 * ######################### ARRAY ROTATION (LEFT AND RIGHT) ######################
 * -------------------------   {USING MODULAR ARITHMETIC}  --------------------------
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> rotate_right(vector<int>& a, int k){
    int n = a.size();
    vector<int> ans(n, 0);
    k%=n;
    for(int i = 0; i<n; i++){
        ans[(i+k)%n] = a[i];
    }
    return ans;
}
vector<int> rotate_left(vector<int>& a, int k){
    int n = a.size();
    vector<int> ans(n, 0);
    k%=n;
    for(int i = 0; i<n; i++){
        ans[(i-k+n)%n] = a[i];
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    vector<int> right_rotate = rotate_right(a, k);
    vector<int> left_rotate = rotate_left(a, k);

    cout << "Right Rotated: ";
    for(int x: right_rotate){
        cout << x << ' ';
    }
    cout << '\n';
    cout << "Left Rotated: ";
    for(int x: left_rotate){
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}