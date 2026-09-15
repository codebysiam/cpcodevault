#include <bits/stdc++.h>
using namespace std;

void merge_and_count(vector<int>& a, vector<int>& temp, long long& inv, int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;

    while(i<=mid && j<=high){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            inv+=(mid-i+1);
            temp[k++] = a[j++];
        }
    }

    while(i<=mid){
        temp[k++] = a[i++];
    }

    while(j<=high){
        temp[k++] = a[j++];
    }

    for(int x = low; x<=high; x++){
        a[x] = temp[x];
    }
}

void count_inversion(vector<int>& a, vector<int>& temp, long long& inv, int low, int high){
    if(low >= high) return;
    int mid = low + (high - low) / 2;
    count_inversion(a, temp, inv, low, mid);
    count_inversion(a, temp, inv, mid+1, high);
    if(a[mid] <= a[mid+1]) return;
    merge_and_count(a, temp, inv, low, mid, high);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a){
        cin >> x;
    }
    vector<int> temp(n);
    long long inv = 0;
    count_inversion(a, temp, inv, 0, n-1);
    cout << inv;
    return 0;
}