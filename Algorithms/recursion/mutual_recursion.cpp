#include <bits/stdc++.h>
using namespace std;

/* ---------------- Mutual Recursion ---------------- */
/*
  In simple recursion, a function calls itself.
  But in mutual recursion, two functions depend on
  each other and call each other when needed.

  In the code below, we use two functions to determine
  whether a number is even or odd.

  In isEven(), we first check if n is 0.
  Since 0 is even, we return true.

  If n is greater than 0, we call isOdd(n - 1).
  This is because if n - 1 is odd, then n must be even.

  Similarly, in isOdd(), we first check if n is 0.
  Since 0 is not odd, we return false.

  If n is greater than 0, we call isEven(n - 1).
  This is because if n - 1 is even, then n must be odd.

  Example:
      isEven(5)
      -> isOdd(4)
      -> isEven(3)
      -> isOdd(2)
      -> isEven(1)
      -> isOdd(0)
      -> false

  Therefore, 5 is odd.
*/


bool isEven(int n);
bool isOdd(int n);

bool isEven(int n){
    if(n == 0){
        return true;
    }
    return isOdd(n-1);
}

bool isOdd(int n){
    if(n == 0){
        return false;
    }
    return isEven(n-1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    cout << n << (isEven(n) ? " is even" : " is odd");
    return 0;
}