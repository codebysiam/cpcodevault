#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        int tmp = x;
        int cnt = 0;
        while(tmp > 0){
            if(tmp%10 != 0) cnt++;
            tmp/=10;
        }

        int d = 1;
        while(d <= x/10){
            d*=10;
        }
        
        cout << cnt << '\n';
        while(d>0){
            int rnum = ((x/d)%10)*d;
            if(rnum) cout << rnum << ' ';
            d/=10;
        }
        cout << '\n';
    }
    return 0;
}