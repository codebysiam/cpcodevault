#include <bits/stdc++.h>
using namespace std;

/* ------------------ Cycle Detection in Directed Graph Using Recursion O(V + E) ------------------ */
/*
  Cycle detection in directed graph is different from cycle detection in undirected graph.
  In undirected graph, if we visit a vertex that was already visited and it is not the parent
  of the current vertex, then there is a cycle.
  But this idea does not work in directed graph. Because in directed graph, we can visit a
  vertex that was visited before without creating a cycle.
  For example:
      0 -> 1 -> 3
      |         ^
      v         |
      2 --------+
  Suppose we first follow:
      0 -> 1 -> 3
  Then we finish 3, go back to 1, finish 1, and then go to 2.
  Now 2 has an edge to 3:
      2 -> 3
  Here, 3 was already visited. But there is no cycle.
  Why? Because the edges are directed toward 3. We can go from 0 to 1 to 3, and we can
  go from 2 to 3, but we cannot follow the directed edges from 3 back to 0.
  So, in a directed graph, we need to know two things:
    1. Has this vertex been visited before?
    2. Is this vertex still in the current DFS path?
  That's why we use 3 states instead of a simple visited array:
    0 -> not visited yet
    1 -> currently in the path
    2 -> completely processed; no longer in the path
  Now consider what happens when we are at some vertex and look at one of its outgoing edges.
  If the next vertex has state 0, we have never visited it, so we go there recursively.
  If the next vertex has state 2, it was visited and completely processed before. It is no
  longer in our current path, so there is no cycle just because we reached it again.
  But if the next vertex has state 1, that vertex is still in our current path.
  For example, suppose our current path is:
      0 -> 1 -> 3 -> 2
  and from 2 we have an edge back to 1:
      2 -> 1
  Vertex 1 has state 1 because it is still in the current path.
  So we already have a path:
      1 -> 3 -> 2
  and now we have:
      2 -> 1
  Therefore, we can go:
      1 -> 3 -> 2 -> 1
  which is a cycle.
  This is the main idea: if we reach a vertex that is still in the current DFS path,
  then we can go from that vertex to the current vertex and come back to that vertex.
  Therefore, a cycle exists.
  When we finish exploring a vertex completely, we change its state from 1 to 2. This is
  important because it tells us that the vertex is no longer part of the current path.
  We repeat DFS from every unvisited vertex because the graph can have multiple disconnected
  parts.
*/


bool current_path_has_cycle(int v, vector<vector<int>>& adj, vector<int>& state){
  state[v] = 1;

  for(const int &x: adj[v]){
    if(state[x] == 0){
      if(current_path_has_cycle(x, adj, state)) return true;
    }else if(state[x] == 1) return true;
  }

  state[v] = 2;
  return false;
}

bool has_cycle(vector<vector<int>>& adj){
  int n = adj.size();
  vector<int> state(n, 0);
  for(int i = 0; i<n; i++){
    if(state[i] != 0) continue;
    if(current_path_has_cycle(i, adj, state)) return true;
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
  }

  cout << (has_cycle(adj) ? "This graph has cycle" : "This graph doesn't have any cycle");
  return 0;
}