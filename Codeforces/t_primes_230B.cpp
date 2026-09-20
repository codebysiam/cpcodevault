#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool tprime(ll x){
  ll r = sqrtl(x);
  while((r+1)*(r+1) <= x) r--;
  while(r*r > x) r--;
  if(r*r != x) return false;

  if(r <= 1) return false;
  for(int i = 2; i<=r/i; i++){
    if(r%i == 0) return false;
  }

  return true;
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  while(n--){
    ll x; cin >> x;
    cout << (tprime(x) ? "YES\n" : "NO\n");
  }
  return 0;
}