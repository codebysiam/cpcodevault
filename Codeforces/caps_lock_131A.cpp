#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  string s; cin >> s;
  for(int i = 1; i<s.size(); i++){
    if(s[i] - 'A' >= 32){
        cout << s; return 0;
    }
  }
  for(int i = 0; i<s.size(); i++){
    cout << char(s[i] - 'A' >= 32 ? toupper(s[i]) : tolower(s[i]));
  }
  return 0;
}