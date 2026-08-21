#include <bits/stdc++.h>
using namespace std;

/* --------------------------- Cycle Detection in Undirected Graph O(V + E) --------------------------- */
/*
  A cycle in an undirected graph is a path that starts and ends at the same vertex
  without repeating any vertex or edge along the way.
  We can detect a cycle in an undirected graph using either DFS or BFS. Here, we use
  an iterative DFS with a stack.
  The key idea is to keep track of the parent of every vertex. When we visit an
  already-visited neighbor, there are two possibilities:
  1. The neighbor is the parent of the current vertex.
    This is expected in an undirected graph because every edge appears in both
    directions. Therefore, we ignore it.

  2. The neighbor is not the parent of the current vertex.
    This means there is another path to an already-visited vertex, which implies
    the existence of a cycle.

  For example:

           0
          / \
         1   2
          \ /
           3
           |
           4

  The graph contains the cycle:

            0 -> 1 -> 3 -> 2 -> 0

  Let's trace the DFS:
  - Start at vertex 0. Its unvisited neighbors are 1 and 2.
  - Visit 1. Its neighbors are 0 and 3. Vertex 0 is already visited, but it is
    the parent of 1, so we ignore it. We then visit 3.
  - At vertex 3, vertex 1 is already visited and is its parent, so we ignore it.
    Vertex 2 is unvisited, so we visit 2.
  - At vertex 2, both 0 and 3 are already visited. Vertex 3 is the parent of 2,
    so we ignore it. However, vertex 0 is not the parent of 2. Therefore, we have
    found a cycle.
  Since the graph may be disconnected, we start a DFS from every unvisited vertex.
  This ensures that cycles in all connected components are detected.

  Time Complexity:  O(V + E)
  Space Complexity: O(V + E)
*/

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for(int i = 0; i<m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bool has_cycle = false;
  vector<bool> visited(n, false);
  for(int i = 0; i<n; i++){
    if(visited[i]) continue;

    stack<pair<int, int>> s;
    s.push({i, -1});
    visited[i] = true;

    while(!s.empty()){
      auto [top, parent] = s.top();
      s.pop();

      for(const int &x: adj[top]){
        if(!visited[x]){
          s.push({x, top});
          visited[x] = true;
        }else if(x != parent){
          has_cycle = true;
          break;
        }
      }

      if(has_cycle) break;
    }

    if(has_cycle) break;
  }

  cout << (has_cycle ? "The graph has cycle" : "The graph doesn't have any cycle");
  return 0;
}