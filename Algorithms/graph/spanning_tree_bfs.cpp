#include <bits/stdc++.h>
using namespace std;

/* ------------ Spanning Tree using BFS ------------ */
/*
  We perform an iterative BFS starting from vertex 0.
  Whenever we discover an unvisited vertex, we add the
  corresponding edge to the tree.

  If the graph is connected, every vertex will be visited,
  and the collected edges form a spanning tree.

  If some vertices remain unvisited, the graph is disconnected,
  so a spanning tree does not exist and we return {}.
*/


vector<pair<int, int>> spanning_tree(const vector<vector<int>>& adj){
  int n = adj.size();
  vector<bool> visited(n, false);
  queue<int> q;
  q.push(0);
  visited[0] = true;

  vector<pair<int, int>> tree;

  int vcount = 1;
  while(!q.empty()){
    int front = q.front();
    q.pop();

    for(int x: adj[front]){
      if(!visited[x]){
        q.push(x);
        visited[x] = true;
        vcount++;
        tree.push_back({front, x});
      }
    }
  }

  if(vcount != n) return {};

  return tree;
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

  vector<pair<int, int>> tree = spanning_tree(adj);
  for(auto [u, v]: tree){
    cout << u << ' ' << v << '\n';
  }
  return 0;
}