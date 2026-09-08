#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, vector<int>& temp, int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;

    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }
    
    while(i <= mid){
        temp[k++] = arr[i++];
    }

    while(j <= high){
        temp[k++] = arr[j++];
    }

    for(int i = low; i<=high; i++){
        arr[i] = temp[i];
    }
}

void mergeSort(vector<int>& arr, vector<int>& temp, int low, int high){
    if(low >= high) return;
    int mid = low + (high - low) / 2;

    mergeSort(arr, temp, low, mid);
    mergeSort(arr, temp, mid+1, high);

    if(arr[mid] <= arr[mid+1]) return;

    merge(arr, temp, low, mid, high);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x: arr){
        cin >> x;
    }
    vector<int> temp(n);
    mergeSort(arr, temp, 0, n-1);
    for(int x: arr){
        cout << x << ' ';
    }
    return 0;
}