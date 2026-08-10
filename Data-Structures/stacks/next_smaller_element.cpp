#include <bits/stdc++.h>
using namespace std;

/* ----------------------- Next Smaller Element O(n) ----------------------- */
/*
    We find the next smaller element using the exact same technique as the next 
    greater element, using a stack.
    
    For each element, we pop elements from the stack until the top is strictly 
    smaller than the current element. For details about this technique, 
    go to: './next_greater_element.cpp'
*/

vector<int> next_smaller_element(vector<int> a){
    stack<int> s;
    for(int i = a.size() - 1; i >= 0; i--){
        int curr = a[i];
        while(!s.empty() && s.top() >= curr){
            s.pop();
        }
        a[i] = s.empty() ? -1 : s.top();
        s.push(curr);
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a){
        cin >> x;
    }
    for(int x: next_smaller_element(a)){
        cout << x << ' ';
    }
    return 0;
}