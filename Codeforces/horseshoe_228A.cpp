#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<long long> colors;
    for(int i = 0; i<4; i++){
        long long color;
        cin >> color;
        colors.push_back(color);
    }
    set<long long> duplicateRemoved(colors.begin(), colors.end());
    cout << (colors.size() - duplicateRemoved.size());
    return 0;
}