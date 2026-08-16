#include <bits/stdc++.h>
using namespace std;

vector<int> merge(const vector<int>& a, const vector<int>& b){
    int n = a.size();
    int m = b.size();
    vector<int> ans;
    ans.reserve(n+m);

    int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] <= b[j]){
            ans.push_back(a[i++]);
        }else{
            ans.push_back(b[j++]);
        }
    }

    while(i < n){
        ans.push_back(a[i++]);
    }
    while(j < m){
        ans.push_back(b[j++]);
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(auto& x: a){
        cin >> x;
    }
    for(auto& x: b){
        cin >> x;
    }
    vector<int> merged = merge(a, b);
    for(int x: merged){
        cout << x << ' ';
    }
    return 0;
}