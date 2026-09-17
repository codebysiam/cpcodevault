#include <bits/stdc++.h>
using namespace std;

/*
  After thinking about the problem for a while, I realized that I don't
  have to scan the whole array to find the number with different parity.

  I can keep track of how many even and odd numbers I have seen. Once
  both counts are greater than 0 and become different, one parity has
  already become the majority. Since the problem guarantees that there
  is exactly one number with different parity, I now know what parity
  the different number must have.

  Another important observation I made is that the different number must
  be among the last three elements. Therefore, I only need to scan that
  small window to find its index.

  I spent about an hour looking at the problem and eventually discovered
  this approach myself. @codebysiam
*/

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<int> a;
  vector<int> cnt(2);
  for(int i = 0; i<n; i++){
    int x; cin >> x;
    a.push_back(x);
    cnt[x%2==0]++;
    if(cnt[0] > 0 && cnt[1] > 0 && cnt[0] != cnt[1]) break;
  }

  int st = cnt[0] < cnt[1] ? 1 : 0;
  for(int i = a.size()-3; i<a.size(); i++){
    if(a[i]%2==st){
      cout << i+1; break;
    }
  }
  return 0;
}