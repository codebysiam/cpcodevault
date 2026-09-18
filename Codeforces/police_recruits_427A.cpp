#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  int cur = 0; int ans = 0;
  while(n--){
    int x; cin >> x;
    cur+=x;
    if(cur < 0){
      ans++; cur = 0;
    }
  }
  cout << ans;
  return 0;
}