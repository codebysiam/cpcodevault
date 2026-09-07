#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    priority_queue<int, vector<int>> pq;
    int sum = 0;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        sum+=x;
        pq.push(x);
    }

    int taken = 0;
    int ans = 0;
    while(!pq.empty()){
        int top = pq.top();
        pq.pop();
        taken+=top;
        sum-=top;
        ans++;
        if(taken > sum) break;
    }
    cout << ans;
    return 0;
}