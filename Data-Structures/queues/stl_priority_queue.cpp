#include <bits/stdc++.h>
using namespace std;

/* -------------------- Priority Queue -------------------- */
/*
    A priority queue is a data structure where the highest-priority
    element is always available at the top.

    By default, C++'s priority_queue is a max-heap, meaning the
    largest element is kept at the top. It can also be configured
    as a min-heap, where the smallest element stays at the top.

    Priority queues are useful when we repeatedly need quick access
    to the maximum or minimum element.

    The sliding window maximum problem below is implemented using
    a priority queue to demonstrate a practical use of it.

    Note: This is not the most optimal solution for the problem.
    A deque-based approach can solve it in O(n).
    go to ./k_size_sliding_window_max.cpp for more info.
    but the priority queue approach is useful for practicing 
    how heaps work.
*/

vector<int> sliding_window_max(const vector<int>& a, int k){
    int n = a.size();
    if(k <= 0 || k > n) throw invalid_argument("Sliding window size must be a valid positive integer less than or equal to n");
    priority_queue<pair<int, int>> pq;
    vector<int> ans;
    for(int i = 0; i<n; i++){
        while(!pq.empty() && pq.top().second <= i-k){
            pq.pop();
        }
        pq.push({a[i], i});
        if(i >= k-1){
            ans.push_back(pq.top().first);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> a = {2, 4, 0, 1, 5, 7, 6, 9};
    for(int x: sliding_window_max(a, 2)){
        cout << x << ' ';
    }
    cout << '\n';

    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    cout << pq.top() << ' '; // will print 30 because it is the largest item.
    pq.pop(); // removes the element at the top, so 30 is removed.
    cout << pq.top(); // 20, because after removing 30, it is the largest remaining item.
    cout << '\n';
    if(pq.empty()){
        cout << "The priority queue is empty.";
    }else{
        cout << "The priority queue is not empty.";
    }

    cout << '\n';

    priority_queue<int, vector<int>, greater<int>> pq_min;
    pq_min.push(30);
    pq_min.push(20);
    pq_min.push(10);
    cout << pq_min.top() << ' '; // will print 10 because it is the smallest item.
    pq_min.pop(); // removes the element at the top, so 10 is removed.
    cout << pq_min.top(); // 20, because after removing 10, it is the smallest remaining item.
    cout << '\n';
    if(pq_min.empty()){
        cout << "The min priority queue is empty.";
    }else{
        cout << "The min priority queue is not empty.";
    }
    return 0;
}