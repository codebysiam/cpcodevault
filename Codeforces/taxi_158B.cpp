#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> freq(5);
  for(int i = 0; i<n; i++){
    int x; cin >> x;
    freq[x]++;
  }
  int taxis = 0;
  taxis+=freq[4];

  int x = min(freq[1], freq[3]);
  taxis+=x;
  freq[1]-=x; freq[3]-=x;
  taxis+=freq[3];

  taxis+=freq[2]/2;
  freq[2]%=2;

  if(freq[2]){
    taxis++;
    freq[1] = max(0, freq[1]-2);
  }

  taxis+=(freq[1]+3)/4;

  cout << taxis;
  return 0;
}