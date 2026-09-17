#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int x, y, z;
  int mx = INT_MIN;
  int mn = INT_MAX;
  for(int i = 0; i<3; i++){
    int j; cin >> j;
    mx = max(mx, j);
    mn = min(mn, j);
  }
  cout << mx - mn;
  return 0;
}