#include <bits/stdc++.h>
using namespace std;

/* ---------------------------- Recursive DFS ---------------------------- */
/*
  Recursive Depth-First Search (DFS):

  We start from a vertex, mark it as visited, and add it to the result.
  Then, we look at all of its neighbors one by one.

  If a neighbor has not been visited yet, we recursively call DFS on that
  neighbor. This means we keep going deeper into the graph before coming
  back and exploring the remaining neighbors.

  In simple terms:
    1. Visit the current vertex.
    2. Mark it as visited.
    3. Go to an unvisited neighbor.
    4. Repeat the same process recursively.
    5. Backtrack when there are no more unvisited neighbors.
*/

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int vertex, vector<int>& ans){
  visited[vertex] = true;
  ans.push_back(vertex);
  for(const int &x: adj[vertex]){
    if(!visited[x]){
      dfs(adj, visited, x, ans);
    }
  }
}

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
  vector<bool> visited(adj.size(), false);
  vector<int> ans;
  dfs(adj, visited, 0, ans);
  for(const int &x: ans){
    cout << x << ' ';
  }
  return 0;
}