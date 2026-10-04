#include <bits/stdc++.h>
using namespace std;

int solve(int n, int cap, const vector<pair<int, int>>& items, vector<vector<int>>& dp){
  if(cap == 0 || n == 0) return 0;
  if(dp[n][cap] != -1) return dp[n][cap];
  auto [val, wt] = items[n-1];
  if(wt <= cap) return dp[n][cap] = max(val+solve(n, cap-wt, items, dp), solve(n-1, cap, items, dp));
  return dp[n][cap] = solve(n-1, cap, items, dp);
}

int knapsack(int cap, const vector<pair<int, int>>& items){
  int n = items.size();
  vector<vector<int>> dp(n+1, vector<int>(cap+1, -1));
  return solve(n, cap, items, dp);
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, t; cin >> n >> t;
  vector<pair<int, int>> items(n); for(auto &x: items) cin >> x.first >> x.second;
  cout << knapsack(t, items);
  return 0;
}