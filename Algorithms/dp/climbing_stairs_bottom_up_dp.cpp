#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<ll> dp = {1, 1};
  while(n--){
    ll x = dp[0] + dp[1];
    dp[0] = dp[1];
    dp[1] = x;
  }
  cout << dp[0];
  return 0;
}