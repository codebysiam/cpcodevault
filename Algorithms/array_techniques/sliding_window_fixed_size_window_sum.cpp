#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* -------------- Sliding Window: Fixed Size Window Sum ---------------*/

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &x: a){
        cin >> x;
    }
    ll currSum = 0;
    for(int i = 0; i<k; i++){
        currSum+=a[i];
    }
    ll mx = currSum;
    for(int i = k; i<n; i++){
        currSum+=a[i];
        currSum-=a[i-k];
        mx = max(currSum, mx); // replace max with min for minimum sum
    }
    cout << mx << ' ';
    return 0;
}