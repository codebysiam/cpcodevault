#include <bits/stdc++.h>
using namespace std;

int solve(int i, int n, const vector<int>& a, vector<int>& dp){
  if(i >= n-1) return 0;
  if(dp[i] != -1) return dp[i];
  int ans = INT_MAX;
  for(int j = 1; j<=a[i] && i+j<n; j++){
    int sub = solve(i+j, n, a, dp);
    if(sub != INT_MAX) ans = min(ans, 1+sub);
  }
  return dp[i] = ans;
}

int min_jumps(const vector<int>& a){
  int n = a.size();
  vector<int> dp(n, -1);
  int ans = solve(0, n, a, dp);
  if(ans == INT_MAX) return -1;
  return ans;
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<int> a(n); for(int &x: a) cin >> x;
  cout << min_jumps(a);
  return 0;
}