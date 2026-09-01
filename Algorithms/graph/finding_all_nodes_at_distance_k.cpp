#include <bits/stdc++.h>
using namespace std;

/* ----------------- Finding all nodes at distance K (BFS) ----------------- */
/*
  This code finds all nodes at distance k from the source in a graph.
  Let's say we have a graph

          A
         / \
        B   C
       / \
      D   E

  If the source is A and K = 1, the nodes at distance k from the source
  are B and C.

  We use BFS to solve this problem because BFS traverses the graph
  level by level, so it visits nodes in increasing order of distance
  from the source.

  Once we reach a node at distance k, we add it to the answer and
  don't visit its neighbors, since they would be at distance k + 1.
*/

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> adj(n);
  vector<int> dist(n, -1);
  for(int i = 0; i<m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int source;
  cin >> source;

  queue<int> q;
  q.push(source);
  dist[source] = 0;

  vector<int> ans;
  while(!q.empty()){
    int front = q.front();
    q.pop();

    if(dist[front] == k){
      ans.push_back(front);
      continue;
    }

    for(const int &x: adj[front]){
      if(dist[x] == -1){
        q.push(x);
        dist[x] = dist[front]+1;
      }
    }
  }

  for(const int &x: ans){
    cout << x << ' ';
  }
  return 0;
}