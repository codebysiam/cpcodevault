#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    getline(cin, s);
    set<char> distinct;
    for(int i = 1; i<s.size()-1; i++){
        char x = s[i];
        if(x != ',' && x!=' '){
            distinct.insert(x);
        }
    }
    cout << distinct.size();
    return 0;
}