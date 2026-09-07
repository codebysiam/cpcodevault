#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> frnds(n, 0);
  for(int i = 1; i<=n; i++){
    int x;
    cin >> x;
    frnds[x-1] = i;
  }
  for(int x: frnds){
    cout << x << ' ';
  }
  return 0;
}