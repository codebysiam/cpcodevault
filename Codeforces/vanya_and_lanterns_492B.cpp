#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; ll l; cin >> n >> l;
  vector<ll> a(n); for(ll &x: a) cin >> x;
  sort(a.begin(), a.end());

  ll max_gap = 0;
  for(int i = 1; i<n; i++){
    max_gap = max(max_gap, a[i]-a[i-1]);
  }

  double ans = max({(double)a[0], max_gap/2.0, (double)(l-a[n-1])});
  cout << fixed << setprecision(10) << ans;
  return 0;
}