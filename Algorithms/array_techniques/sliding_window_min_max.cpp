#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* -------------- Sliding Window: Min/Max ---------------*/
// Change comparison signs to convert between max and min

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &x: a){
        cin >> x;
    }
    deque<int> dq;
    for(int i = 0; i<n; i++){
        while(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }
        while(!dq.empty() && a[dq.back()] <= a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k-1){
            cout << a[dq.front()] << ' ';
        }
    }
    return 0;
}