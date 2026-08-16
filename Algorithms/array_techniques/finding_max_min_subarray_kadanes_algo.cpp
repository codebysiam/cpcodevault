#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/** --------------------- Finding Max/Min Subarray (Kadane's Algorithm) ----------------------- */
/*
It is simple to find the max/min subarray in O(n^3) or O(n^2)
but we can use Kadane's Algorithm to find it in O(n) time complexity
I am also tracking and printing the max subarray items
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto&x : a){
        cin >> x;
    }
    ll mx = a[0];
    ll cur = a[0];
    int curL = 0;
    int bestL = 0;
    int bestR = 0;
    for(int i = 1; i<n; i++){
        if(cur < 0){
            cur = a[i];
            curL = i;
        }else{
            cur+=a[i];
        }

        if(cur > mx){
            mx = cur;
            bestL = curL;
            bestR = i;
        }
    }

    cout << mx;
    cout << '\n';
    for(int i = bestL; i<=bestR; i++){
        cout << a[i] << ' ';
    }
    return 0;
}
