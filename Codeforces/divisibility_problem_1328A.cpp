#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll nextMultiple = ((a+b-1)/b)*b;
        cout << (nextMultiple - a) << '\n';
    }
    return 0;
}