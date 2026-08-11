#include <bits/stdc++.h>
using namespace std;

/* ---------------------- K-Size Sliding Window Max ---------------------- */
/*
    To get the array of k-sized sliding window max, we use a deque
    because we can pop or push elements from both sides. Each item
    in the dq represents the index of the item.

    We traverse through the whole array. For each iteration, we remove
    all out-of-scope indices from the front of the dq, and then we remove
    the indices of all items smaller than or equal to the current item from
    the back of the deque. Then we push our current item into the deque.

    So, for every iteration, dq.front() is the index of the maximum item
    of the current window. So, we check if the first window is complete.
    If the first window is formed, then we start preserving the item at
    dq.front() index in the 'ans' array.
*/

vector<int> sliding_window_max(const vector<int>& a, int k){
    if (k <= 0 || k > a.size()) throw invalid_argument("Window size k must be a positive integer such that 0 < k <= n");
    deque<int> dq;
    vector<int> ans;
    for(int i = 0; i<a.size(); i++){
        while(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }
        while(!dq.empty() && a[dq.back()] <= a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k-1){
            ans.push_back(a[dq.front()]);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto& x: a){
        cin >> x;
    }
    for(int x: sliding_window_max(a, k)){
        cout << x << ' ';
    }
    return 0;
}