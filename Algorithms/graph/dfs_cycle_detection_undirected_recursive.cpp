#include <bits/stdc++.h>
using namespace std;

/* ---------------------- Cycle Detection in Undirected Graph O(V + E) ---------------------- */
/*
  This is the recursive DFS approach for detecting a cycle in an undirected graph.

  We start DFS from every unvisited vertex because the graph may be disconnected.
  During DFS, we keep track of the parent of each vertex.

  For every neighbor of the current vertex:
    1. If the neighbor has not been visited, we recursively run DFS on it and
       make the current vertex its parent.
    2. If the neighbor has already been visited and it is not the parent of the
       current vertex, then we have found a cycle.
  The parent check is necessary because, in an undirected graph, every edge
  appears in both directions. For example, if we move from A to B, then B's
  adjacency list will contain A. Seeing A again from B does not indicate a
  cycle because A is simply B's parent.

  However, if we encounter an already visited vertex that is not the parent,
  there is another connection to a previously visited part of the graph,
  which means a cycle exists.

  If any DFS traversal finds a cycle, we immediately return true. If all
  connected components are explored without finding one, we return false.

  Time Complexity:  O(V + E)
*/


bool has_cycle_sub(int v, int parent, const vector<vector<int>>& adj, vector<bool>& visited){
  visited[v] = true;

  for(const int &x: adj[v]){
    if(!visited[x]){
      if(has_cycle_sub(x, v, adj, visited)) return true;
    }else if(x != parent){
      return true;
    }
  }

  return false;
}

bool has_cycle(const vector<vector<int>>& adj){
  int n = adj.size();
  vector<bool> visited(n, false);

  for(int i = 0; i<n; i++){
    if(!visited[i] && has_cycle_sub(i, -1, adj, visited)) return true;
  }

  return false;
}

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

  cout << (has_cycle(adj) ? "The graph has cycle" : "The graph doesn't have any cycle");
  return 0;
}