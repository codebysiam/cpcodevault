#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<int> host(n);
  unordered_map<int, int> guest;
  for(int &x: host){
    int gst;
    cin >> x >> gst;
    guest[gst]++;
  }

  int ans = 0;
  for(int x: host){
    ans+=guest[x];
  }

  cout << ans;
  return 0;
}