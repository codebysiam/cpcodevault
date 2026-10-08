#include <bits/stdc++.h>
using namespace std;

int solve(int n, int cap, const vector<int>& prices, vector<vector<int>>& dp){
  if(n == 0 || cap == 0) return 0;
  if(dp[n][cap] != -1) return dp[n][cap];
  int val, wt; val = prices[n-1]; wt = n;
  if(wt <= cap) return dp[n][cap] = max(val+solve(n, cap-wt, prices, dp), solve(n-1, cap, prices, dp));
  return dp[n][cap] = solve(n-1, cap, prices, dp);
}

int rod_cutting(const vector<int>& prices){
  int n = prices.size();
  vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
  return solve(n, n, prices, dp);
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<int> a(n); for(int &x: a) cin >> x;
  cout << rod_cutting(a);
  return 0;
}