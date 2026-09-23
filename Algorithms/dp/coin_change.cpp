#include <bits/stdc++.h>
using namespace std;

/* ---------------------------- Coin Change (Dynamic Programming) ---------------------------- */
/*
  Coin change is a very popular and easy dp problem.
  Let's say I give you an array of coins a = {1, 2, 6, 7} and ask you to make the number 12
  using these coins. you can use each coin infinitely many times. then what is the
  minimum number of coins you need to make the number 12?
  You can do:
    7 + 2 + 2 + 1 = 12 (4 coins)
    6 + 6 = 12 (2 coins)
  so, 2 will be the answer.

  To be precise, this problem can be solved by using recursion. Let's say the number
  we want to make is tgt = 12. in each recursion call, we will try to subtract a[i]
  coin and see if it becomes 0, if it becomes 0, then it means we found a valid
  combination to make the number tgt. we return 0 because we don't need any more
  coins to make the target.
  if it becomes negative, then it means this recursion path can't make the number tgt.
  so we return INT_MAX to represent an impossible path.

  Now, why are we returning 0 and INT_MAX? The answer is simple, we want to find out
  the minimum number of coins we need to make tgt. so each time I make a function call
  inside the function, if it eventually returns 0, that means we have a valid path.
  so we add 1 with it and compare it with the minimum number we have seen so far.
  We are adding 1 because we used one coin, and the more coins a recursion path takes,
  the bigger 1 + ans becomes. so if we want the minimum number of coins, we take the
  minimum among all valid paths. If a subpath returns INT_MAX, it means that path is
  impossible, so we ignore it.

  What is the use of dp here? we know we can make a recursion efficient using dp. if there are
  overlapping subproblems and optimal substructure in the recursion, we can make it
  very very efficient using dp. we keep track of the answer for each call. and if we
  have already processed an answer, we will never process it again. so it avoids
  calculating the same subproblem multiple times and makes the time complexity O(n * k),
  where n is the number of coins and k is the target.
*/


int solve(int tgt, vector<int>& a, vector<int>& dp){
  if(tgt == 0) return 0;
  if(tgt < 0) return INT_MAX;

  if(dp[tgt] != -1) return dp[tgt];
  int mini = INT_MAX;
  for(int x: a){
    int ans = solve(tgt-x, a, dp);
    if(ans != INT_MAX){
      mini = min(mini, 1+ans);
    }
  }
  dp[tgt] = mini;
  return mini;
}

int coins(int tgt, vector<int>& a){
  vector<int> dp(tgt+1, -1);
  int ans = solve(tgt, a, dp);
  if(ans == INT_MAX) return -1;
  return ans;
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, k; cin >> n >> k;
  vector<int> a(n); for(int &x: a) cin >> x;
  cout << coins(k, a);
  return 0;
}