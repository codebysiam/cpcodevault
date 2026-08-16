#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> prefix(n+1, 0);
    for(int i = 1; i<n+1; i++){
        int x;
        cin >> x;
        prefix[i] = prefix[i-1] + x;
    }

    for(int i = 1; i<n+1; i++){
        cout << prefix[i] << ' ';
    }
    return 0;
}