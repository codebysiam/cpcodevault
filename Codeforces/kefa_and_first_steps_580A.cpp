#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int prev = INT_MIN;
    int cnt = 0;
    int mx_cnt = 0;
    while(n--){
        int x;
        cin >> x;
        if(prev <= x){
            cnt++;
        }else{
            cnt = 1;
        }
        prev = x;
        mx_cnt = max(mx_cnt, cnt);
    }
    cout << mx_cnt;
    return 0;
}