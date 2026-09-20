#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, f; cin >> n >> f; n--;
  int mn, mx; mn = mx = f;
  int ans = 0;
  while(n--){
    int x; cin >> x;
    if(x < mn){
      ans++; mn = x;
    }
    if(x > mx){
      ans++; mx = x;
    }
  }
  return 0;
}