#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(int n, vector<ll>& dp){
  if(n <= 1) return 1;
  if(dp[n] == -1) dp[n] = solve(n-1, dp) + solve(n-2, dp);
  return dp[n];
}

ll ways(int n){
  vector<ll> dp(n+1, -1);
  return solve(n, dp);
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  cout << ways(n);
  return 0;
}