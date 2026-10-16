#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dss(ll n){
  ll d = 1;
  ll sm = 0;
  while(n/d > 0) {
    int x = (n/d)%10;
    sm+=(x*x);
    d*=10;
  }
  return sm;
}

int find_index(ll n, const vector<int>& a){
  for(int i = 0; i<a.size(); i++){
    if(a[i] == n) return i;
  }
  return -1;
}

int sig(ll x){
  vector<int> loop = {4, 16, 37, 58, 89, 145, 42, 20};
  for(int i = 0; i<100; i++){
    int k = find_index(x, loop);
    if(k != -1) return ((k-i)%8+8)%8;
    x = dss(x);
  }
  return 8;
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> freq(9, 0);
    while(n--){
      ll x; cin >> x;
      freq[sig(x)]++;
    }
    int sm = 0;
    for(int x: freq) sm+=((x*(x-1))/2);
    cout << sm << '\n';
  }
  return 0;
}