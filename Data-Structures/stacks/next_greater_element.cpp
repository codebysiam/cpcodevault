#include <bits/stdc++.h>
using namespace std;

/* ------------------------- Next Greater Element O(n) ------------------------- */
/*
    We can find the Next Greater Element efficiently using a stack. First, we
    create a stack and start traversing the array from right to left. Every time
    we traverse, we store the current element in the current variable.

    Then, we check if there are any elements in the stack that are less than or
    equal to current. If there are, we pop them because they are useless. They
    cannot be the Next Greater Element of current or of any element further to
    the left, because current is already greater than or equal to them.

    After popping all such elements, we check if the stack is empty. If the stack
    is empty, that means there is no element to the right that is greater than
    current, so we set the Next Greater Element of current to -1.

    If the stack is not empty, that means there is an element in the stack that
    is greater than current. So, we set the Next Greater Element of current
    to s.top(). Since we are traversing from right to left and have already
    removed all useless elements, s.top() is the nearest greater element to
    the right of current.

    Finally, we push current onto the stack. If the next element we process is
    greater than current, current will be popped because it cannot be the
    Next Greater Element of that larger element. If the next element is smaller
    than current, current can potentially be its Next Greater Element.

    Each element is pushed onto the stack once and popped at most once, so the
    overall time complexity is O(n), while the space complexity is O(n).
*/

vector<int> next_greater_element(vector<int> a){
    stack<int> s;
    int n = a.size();
    for(int i = n-1; i>=0; i--){
        int current = a[i];

        // Remove elements that cannot be the answer.
        while(!s.empty() && s.top() <= current){
            s.pop();
        }

         // The nearest greater element to the right.
        a[i] = s.empty() ? -1 : s.top();

        // Current element may be useful for elements to its left.
        s.push(current);
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
    for(int x: next_greater_element(a)){
        cout << x << ' ';
    }
    return 0;
}