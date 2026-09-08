#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    cin >> s;
    for(char &x: s){
        cin >> x;
        if(x == 'H' || x == 'Q' || x == '9'){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}