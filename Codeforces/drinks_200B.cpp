#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  double orange = 0;
  for(int i = 0; i<n; i++){
    double x;
    cin >> x;
    orange+=(x/100);
  }
  cout << (orange/n)*100;
  return 0;
}