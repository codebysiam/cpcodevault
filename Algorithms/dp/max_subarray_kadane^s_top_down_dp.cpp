#include <bits/stdc++.h>
using namespace std;

int max_subarray_at(int i, const vector<int>& a, vector<int>& dp){
  if(dp[i] != INT_MIN) return dp[i];
  dp[i] = max(a[i], max_subarray_at(i-1, a, dp)+a[i]);
  return dp[i];
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<int> a(n); for(int &x: a) cin >> x;
  vector<int> dp(n, INT_MIN);

  dp[0] = a[0];
  max_subarray_at(n-1, a, dp);

  int mx = INT_MIN;
  for(int x: dp){
    mx = max(mx, x);
  }
  cout << mx;
  return 0;
}