#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    string s = "";
    int x = 0;
    while(n--){
        if(!x){
            s+="I hate";
            x=1;
        }else{
            s+="I love";
            x=0;
        }
        if(n > 0) s+= " that ";
    }
    s+= " it";
    cout << s;
    return 0;
}