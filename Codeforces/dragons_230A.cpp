#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  long long s, n; cin >> s >> n;
  vector<pair<int, int>> dragons;
  while(n--){
    int p, b; cin >> p >> b;
    dragons.push_back({p, b});
  }
  sort(dragons.begin(), dragons.end());
  for(auto [p, b]: dragons){
    if(s > p){
      s+=b;
    }else{
      cout << "NO\n"; return 0;
    }
  }
  cout << "YES\n";
  return 0;
}