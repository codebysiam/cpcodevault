#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int q; cin >> q;
  while(q--){
    ll a, b, n, S; cin >> a >> b >> n >> S;
    if(a*n+b < S){
      cout << "NO\n"; continue;
    }
    cout << ((S%n <= b) ? "YES": "NO") << '\n';
  }
  cout << '\n';
  return 0;
}