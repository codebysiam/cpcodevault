#include <bits/stdc++.h>
using namespace std;

int solve(int startIndex, const vector<int>& a, vector<int> &dp){
    if(dp[startIndex] != -1) return dp[startIndex];
    int maxi = 0;
    for(int index = startIndex + 1; index<a.size(); index++){
        if(a[index] > a[startIndex]){
            maxi = max(maxi, 1+solve(index, a, dp));
        }
    }
    dp[startIndex] = maxi;
    return maxi;
}

int lis(const vector<int>& a){
    vector<int> dp(a.size(), -1);
    int maxi = 0;
    for(int i = 0; i<a.size(); i++){
        maxi = max(maxi, 1+solve(i, a, dp));
    }
    return maxi;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n); for(int &x: a) cin >> x;
    cout << lis(a);
    return 0;
}