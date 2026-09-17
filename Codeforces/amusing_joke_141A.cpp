#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string guest, host, pile;
    cin >> guest >> host >> pile;
    vector<int> db(26);
    for(char x: pile) db[x - 'A']++;
    for(char x: guest) db[x - 'A']--;
    for(char x: host) db[x - 'A']--;
    for(int x: db){
        if(x != 0){
            cout << "NO\n"; return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
