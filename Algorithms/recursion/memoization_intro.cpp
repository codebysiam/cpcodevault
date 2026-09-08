#include <bits/stdc++.h>
using namespace std;

/* ------------------------ Memoization ------------------------ */
/*
  In recursive functions, we may end up solving the same
  subproblem many times, which can make the code inefficient.

  For example, in Fibonacci:

    fib(5)
    -> fib(4)
       -> fib(3)
       -> fib(2)
    -> fib(3)  <- fib(3) was already calculated


  Without memoization, fib(3) would be calculated again.

  Memoization solves this problem by storing the result of
  each subproblem after calculating it. When we need the
  same value again, we return the cached result instead of
  recalculating it.

  So, the basic idea is:
  1. Calculate a value.
  2. Store the result.
  3. If we need the same value again, use the stored result.
*/

unordered_map<int, long long> memo;
long long fib(int n){
  if(n <= 1) return n;
  if(memo.find(n) != memo.end()) return memo[n];
  memo[n] = fib(n-1) + fib(n-2);
  return memo[n];
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  cout << fib(n);
  return 0;
}