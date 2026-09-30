#include <bits/stdc++.h>
using namespace std;

int knapsack(const vector<pair<int, int>>& items, int lim, int n){
  if(lim == 0 || n == 0) return 0;
  auto [val, wt] = items[n-1];
  if(wt <= lim) return max(val+knapsack(items, lim-wt, n-1), knapsack(items, lim, n-1));
  return knapsack(items, lim, n-1);
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, lim; cin >> n >> lim;
  vector<pair<int, int>> items(n);
  for(auto &x: items) cin >> x.first >> x.second;
  cout << knapsack(items, lim, n);
  return 0;
}