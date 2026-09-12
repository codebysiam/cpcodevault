#include <bits/stdc++.h>
using namespace std;

void perm(int idx, string s){
  int n = s.size();
  if(idx == n){
    cout << s << '\n';
    return;
  }
  for(int i = idx; i<n; i++){
    swap(s[i], s[idx]);
    perm(idx+1, s);
    swap(s[i], s[idx]);
  }
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  string s;
  cin >> s;
  perm(0, s);
  return 0;
}