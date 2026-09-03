#include <bits/stdc++.h>
using namespace std;

/* ---------- Bellman-Ford (Shortest Path with Negative Edges) ---------- */
/*
  Imagine that we are trying to spread the shortest-path cost
  from the start node to every other node.

  At first, we only know the cost of the start:
      start = 0
      everything else = INF

  We then go through every edge and try to push a known cost
  forward:

      u --w--> v

  If we already know a way to reach u, then we can reach v by
  paying:

      cost[u] + w

  If this is cheaper than the current cost[v], we update v.

  Now v has a better cost, and that better cost can be used to
  reach other vertices through v.

  So every iteration is:
  
        known shortest costs
              ↓
        push them through edges
              ↓
        discover better costs
              ↓
        push those costs further
              ↓
            repeat

  In the worst case, the useful information moves only one edge
  farther along the shortest path in each iteration.

  A shortest path does not need to repeat a vertex unless there
  is a negative cycle, so it contains at most n-1 edges.

  Therefore, n-1 iterations are enough to propagate the shortest
  cost through any possible shortest path.

  If we can still improve a cost after those n-1 iterations,
  the improvement must come from going around a negative cycle.

  That's the whole idea:
      "Keep pushing the cheapest known costs forward until
       every shortest path has had enough chances to propagate."
*/

void bellman_ford(int start, int end, vector<vector<pair<int, int>>>& adj){
  int n = adj.size();
  vector<int> cost(n, INT_MAX);
  vector<int> parent(n, -1);
  cost[start] = 0;

  for(int i = 0; i<n-1; i++){
    bool chng = false;

    for(int u = 0; u<n; u++){
      for(auto [v, w]: adj[u]){
        if(cost[u] != INT_MAX && cost[u]+w < cost[v]){
          cost[v] = cost[u]+w;
          parent[v] = u;
          chng = true;
        }
      }
    }

    if(!chng) break;
  }

  for(int u = 0; u<n; u++){
    for(auto [v, w]: adj[u]){
      if(cost[u] != INT_MAX && cost[u]+w < cost[v]){
        cout << "This graph has negative cycle\n";
        return;
      }
    }
  }

  if(cost[end] == INT_MAX){
    cout << "node " << end << " is not reachable from node " << start << '\n';
    return;
  }

  stack<int> st;
  for(int p = end; p!=-1; p=parent[p]){
    st.push(p);
  }

  cout << "The shortest path from node " << start << " to node " << end << " is:\n";
  while(!st.empty()){
    cout << st.top() << ' ';
    st.pop();
  }
  cout << "\ncost: " << cost[end];
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  for(int i = 0; i<m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  int start, end;
  cin >> start >> end;
  bellman_ford(start, end, adj);
  return 0;
}