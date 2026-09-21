#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, k; cin >> n >> k;
  int r = 240-k;
  int x = 0;
  int i = 1;
  while(x+(5*i) <= r){
    x+=(5*i); i++;
  }
  cout << min(n, i-1);
  return 0;
}