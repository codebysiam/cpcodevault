#include <bits/stdc++.h>
using namespace std;

/* ------------------------------- (Difference Array Technique) ------------------------------------ */
/* Range Update Query*/

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    vector<int> diff(n);
    while(k--){
        int l, r, d;
        cin >> l >> r >> d;
        diff[l]+=d;
        if(r+1 < n){
            diff[r+1]-=d;
        }
    }

    for(int i = 1; i<n; i++){
        diff[i]+=diff[i-1];
    }

    for(int i = 0; i<n; i++){
        a[i]+=diff[i];
    }

    for(int x: a){
        cout << x << ' ';
    }
    return 0;
}