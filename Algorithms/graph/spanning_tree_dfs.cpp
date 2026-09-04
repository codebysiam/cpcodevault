#include <bits/stdc++.h>
using namespace std;

/* ------------ Spanning Tree using DFS ------------ */
/*
  We perform an iterative DFS starting from vertex 0.
  Whenever we discover an unvisited vertex, we add the
  corresponding edge to the tree.

  If the graph is connected, every vertex will be visited,
  and the collected edges form a spanning tree.

  If some vertices remain unvisited, the graph is disconnected,
  so a spanning tree does not exist and we return {}.
*/


vector<pair<int, int>> spanning_tree(vector<vector<int>>& adj){
  int n = adj.size();
  vector<bool> visited(n, false);
  stack<int> st;
  st.push(0);
  visited[0] = true;
  
  vector<pair<int, int>> tree;

  int vcount = 1;
  while(!st.empty()){
    int top = st.top();
    st.pop();

    for(int x: adj[top]){
      if(!visited[x]){
        st.push(x);
        visited[x] = true;
        tree.push_back({top, x});
        vcount++;
      }
    }
  }

  if(vcount != n){
    return {};
  }

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