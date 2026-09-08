#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n;
    cin >> n;
    int bills = 0;
    vector<int> dn = {100, 20, 10, 5, 1};
    for(int i = 0; i<5; i++){
        long long x = n/dn[i];
        bills+=x;
        n-=(x*dn[i]);
    }
    cout << bills;
    return 0;
}