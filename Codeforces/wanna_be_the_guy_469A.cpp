#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    set<int> lvl;
    int p;
    cin >> p;
    while(p--){
        int x;
        cin >> x;
        lvl.insert(x);
    }    
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        lvl.insert(x);
    }

    cout << (lvl.size() == n ? "I become the guy." : "Oh, my keyboard!");
    return 0;
}