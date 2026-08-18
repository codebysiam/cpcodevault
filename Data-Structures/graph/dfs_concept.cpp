#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ DFS Concept ------------------------------ */
/*
    DFS (Depth-First Search) is one of the most famous graph traversal
    algorithms. In DFS, we start from a vertex and try to explore as deeply
    as possible before going back to explore other vertices.

    We can implement DFS iteratively using a stack. Since a stack follows
    the LIFO (Last In, First Out) principle, the most recently added vertex
    is processed first.

    First, we push the starting vertex into the stack and mark it as visited.
    Then we keep running a loop while the stack is not empty.

    In each iteration, we take the top vertex from the stack, store it in
    'top', print/process it, and then pop it from the stack.

    Next, we look at all the neighbors of 'top'. If a neighbor has not been
    visited yet, we push it into the stack and immediately mark it as visited.
    Marking a vertex as visited when we push it prevents the same vertex from
    being pushed multiple times.

    We continue this process until the stack becomes empty. When the stack is
    empty, there are no more unvisited vertices reachable from the starting
    vertex, so the DFS traversal is complete.
*/


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<vector<int>> adj = {
        {1, 2},       // 0
        {0, 3, 4},    // 1
        {0, 4},       // 2
        {1, 5},       // 3
        {1, 2, 5},    // 4
        {3, 4}        // 5
    };

    stack<int> s;
    vector<bool> visited(adj.size(), false);
    s.push(0);
    visited[0] = true;

    while(!s.empty()){
        int top = s.top();
        cout << top << ' ';
        s.pop();

        for(const int &x: adj[top]){
            if(!visited[x]){
                s.push(x);
                visited[x] = true;
            }
        }
    }
    return 0;
}