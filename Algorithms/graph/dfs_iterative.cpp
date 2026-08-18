#include <bits/stdc++.h>
using namespace std;

/* --------------------- Iterative DFS: O(V + E) --------------------- */
/*
  Iterative implementation of Depth-First Search (DFS) for an
  undirected graph.

  A stack is used to keep track of vertices that need to be visited.
  Each vertex is marked as visited when it is pushed onto the stack,
  ensuring that no vertex is pushed more than once.

  Time Complexity:  O(V + E)
  See ../../Data-Structures/graph/dfs_concept.cpp for the DFS concept.
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
    int v = s.top();
    cout << v << ' ';
    s.pop();

    for(const int &x: adj[v]){
      if(!visited[x]){
        s.push(x);
        visited[x] = true;
      };
    };
  }
  return 0;
}