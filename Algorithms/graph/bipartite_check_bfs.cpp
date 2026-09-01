#include <bits/stdc++.h>
using namespace std;

/* ------------------------- Bipartite Check Using BFS -------------------------*/
/*
  In this code, we use BFS to check if a graph is bipartite.

  A graph is bipartite if we can divide its nodes into two groups such that
  nodes in the same group are not connected to each other. In other words,
  every edge should connect nodes from different groups.

  To check this, we use two colors. We start from a node and give it a color.
  Then we give the opposite color to all of its neighbors.

  The algorithm is:
    -> Start from an unvisited node.
    -> Check all of its neighbors.
    -> If a neighbor is not visited:
       -> push it into the queue and mark it visited
       -> give it the opposite color of the current node
    -> If a neighbor is already visited:
       -> check if it has the same color as the current node
       -> if both have the same color, the graph is not bipartite
          so return false

  We repeat this for every unvisited node because the graph can be disconnected.

  In this code, we use separate `visited` and `color` arrays.
  We could also use 3 states in a single array:
    0 -> not visited
    1 -> first color
    2 -> second color

  But using separate arrays makes the logic more intuitive and easier to follow.
*/


bool bipartite(vector<vector<int>>& adj){
  int n = adj.size();
  vector<bool> visited(n, false);
  vector<bool> color(n, false);
  queue<int> q;
  for(int i = 0; i<n; i++){
    if(visited[i]) continue;
    q.push(i);
    visited[i] = true;

    while(!q.empty()){
      int front = q.front();
      q.pop();
      
      for(const int &x: adj[front]){
        if(!visited[x]){
          q.push(x);
          visited[x] = true;
          color[x] = !color[front];
        }else if(color[front] == color[x]) return false;
      }
    }
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
  cout << (bipartite(adj) ? "The graph is bipartite" : "The graph is not bipartite");
  return 0;
}