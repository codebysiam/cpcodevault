#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<int> a(n); for(int &x: a) cin >> x;
  vector<int> dp(n);
  dp[0] = a[0];
  int mx = dp[0];
  for(int i = 1; i<n; i++){
    dp[i] = max(a[i], dp[i-1]+a[i]);
    mx = max(mx, dp[i]);
  }
  cout << mx;
  return 0;
}