#include <bits/stdc++.h>
using namespace std;
void subset(int i, vector<int>& arr, vector<int>& current, vector<vector<int>>& ans){
    int n = arr.size();
    if(i == n){
        ans.push_back(current);
        return;
    }

    current.push_back(arr[i]);
    subset(i+1, arr, current, ans);

    current.pop_back();
    subset(i+1, arr, current, ans);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x: arr){
        cin >> x;
    }
    vector<int> current;
    vector<vector<int>> subsets;
    subset(0, arr, current, subsets);
    sort(subsets.begin(), subsets.end(), [](vector<int> a, vector<int> b){
        if(a.size() != b.size()){
            return a.size() < b.size();
        }
        return a < b;
    });
    for(int i = 0; i<subsets.size(); i++){
        cout << '{';
        for(int j = 0; j<subsets[i].size(); j++){
            cout << subsets[i][j];
            if(j < subsets[i].size()-1) cout << ", ";
        }
        cout << "}\n";
    }
    return 0;
}