#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    int mxi;
    int mni;
    int mx = INT_MIN;
    int mn = INT_MAX;
    int i = 0;
    for(int &x: arr){
        cin >> x;
        if(x > mx){
            mx = x;
            mxi = i;
        }
        if(x <= mn){
            mn = x;
            mni = i;
        }
        i++;
    }

    int swaps = n - mni - 1 + mxi;
    if(mni < mxi) swaps--;

    cout << swaps;
    return 0;
}