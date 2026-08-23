#include <bits/stdc++.h>
using namespace std;

/* ------------------------- Check if a graph is bipartite O(V + E) ------------------------- */
/*
  A graph is bipartite if its vertices can be split into two groups in a way that
  every edge connects a vertex from one group to a vertex from the other group,
  but no edge connects two vertices from the same group.

  To check if a graph is bipartite, we use 2-coloring. Let's say we have red and
  green. We start with a vertex and color it green. Then we visit its neighbors.
  If a neighbor is not visited yet, we color it with the opposite color, red.

  If a neighbor is already visited, we check if its color is the same as the
  current vertex. If they have the same color, then the graph cannot be bipartite.

  We repeat this for every unvisited vertex because the graph can have multiple
  disconnected components.
*/

bool bipartite_single(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& color){
  visited[v] = true;
  for(const int &x: adj[v]){
    if(!visited[x]){
      color[x] = !color[v];
      if(!bipartite_single(x, adj, visited, color)) return false;
    }else if(color[x] == color[v]) return false;
  }
  return true;
}

bool bipartite(vector<vector<int>>& adj){
  int n = adj.size();
  vector<bool> visited(n, false);
  vector<bool> color(n, false);
  for(int i = 0; i<n; i++){
    if(visited[i]) continue;
    if(!bipartite_single(i, adj, visited, color)) return false;
  }
  return true;
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
  cout << (bipartite(adj) ? "This graph is bipartite" : "This graph is not bipartite");
  return 0;
}