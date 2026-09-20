#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m; cin >> n >> m;
  vector<int> f(m); for(int &x: f) cin >> x;
  sort(f.begin(), f.end());
  int mn = INT_MAX;
  for(int i = n-1; i<m; i++){
    mn = min(mn, f[i]-f[i-n+1]);
  }
  cout << mn;
  return 0;
}