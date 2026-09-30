#include <bits/stdc++.h>
using namespace std;

int solve(int n, int lim, const vector<pair<int, int>>& items, vector<vector<int>>& dp){
  if(lim == 0 || n == 0) return 0;
  if(dp[n][lim] != -1) return dp[n][lim];
  auto [val, wt] = items[n-1];
  if(wt <= lim) return dp[n][lim] = max(val+solve(n-1, lim-wt, items, dp), solve(n-1, lim, items, dp));
  return dp[n][lim] = solve(n-1, lim, items, dp);
}

int knapsack(const vector<pair<int, int>>& items, int lim){
  int n = items.size();
  vector<vector<int>> dp(n+1, vector<int>(lim+1, -1));
  return solve(n, lim, items, dp);
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, lim; cin >> n >> lim;
  vector<pair<int, int>> items(n); for(auto &x: items) cin >> x.first >> x.second;
  cout << knapsack(items, lim);
  return 0;
}