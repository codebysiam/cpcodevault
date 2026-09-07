#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n, k;
    cin >> n >> k;
    long long mid = n/2;
    if(n%2 != 0) mid++;
    if(k <= mid){
        cout << 2*(k-1)+1;
    }else{
        k-=mid;
        cout << 2*(k-1)+2;
    }
    return 0;
}