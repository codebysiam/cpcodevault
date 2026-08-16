#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> prefix(m+1, vector<int>(n+1, 0));
    for(int i = 1; i<m+1; i++){
        for(int j = 1; j<n+1; j++){
            int x;
            cin >> x;
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + x;
        }
    }
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << prefix[r2+1][c2+1] + prefix[r1][c1] - prefix[r1][c2+1] - prefix[r2+1][c1];
    return 0;
}