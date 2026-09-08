#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> info(4);
    for(int &x: info) cin >> x;
    int d;
    cin >> d;
    vector<int> damaged(d+1, false);
    
    for(int x: info){
        if(x == 1) {
            cout << d;
            return 0;
        }
        for(int m = x; m<=d; m+=x){
            if(!damaged[m]) damaged[m] = true;
        }
    }
    int not_damaged = 0;
    for(int i = 1; i<=d; i++){
        if(!damaged[i]) not_damaged++;
    }
    cout << d-not_damaged;
    return 0;
}