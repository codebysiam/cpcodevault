#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t; cin >> t;
  while(t--){
    long long x; cin >> x;
    while(x%2==0) x/=2;
    cout << (x > 1 ? "YES" : "NO") << '\n';
  }
  return 0;
}