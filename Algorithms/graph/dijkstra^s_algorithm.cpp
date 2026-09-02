#include <bits/stdc++.h>
using namespace std;

/* ---------- Dijkstra's Algorithm (Shortest Path in a Weighted Graph) ---------- */
/*
    Dijkstra's algorithm finds the shortest path from a given source
    vertex to all other vertices in a weighted graph.

    It is a greedy algorithm that repeatedly selects the vertex with
    the smallest known distance and uses it to relax its neighboring
    vertices.

    In this implementation:

    - cost[v] stores the minimum cost currently known to reach vertex v.
    - parent[v] stores the previous vertex on the shortest path to v.
      This allows us to reconstruct the actual shortest path afterward.
    - A min-priority queue is used to always process the vertex with
      the smallest known cost.

    Initially, every vertex is considered unreachable, so we set:

        cost[v] = INT_MAX

    Why INT_MAX?

    We use INT_MAX to represent infinity. Since we do not know the
    shortest distance to any vertex at the beginning, every distance
    is initialized to a very large value.

    The source vertex has distance 0 because the cost of reaching the
    source from itself is zero:

        cost[start] = 0

    For every edge (u, v, w), we try to improve the shortest known
    distance to v using u:

        cost[u] + w < cost[v]

    If this condition is true, we have found a cheaper path to v.
    We update cost[v], push the new distance into the priority queue,
    and set parent[v] = u.

    Dijkstra's algorithm requires all edge weights to be non-negative.
*/

void print_shortest_path(int start, int end, vector<vector<pair<int, int>>>& adj){
  int n = adj.size();
  vector<int> cost(n, INT_MAX);
  vector<int> parent(n, -1);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  cost[start] = 0;
  pq.push({0, start});

  while(!pq.empty()){
    auto [current_cost, top] = pq.top();
    pq.pop();

    if(current_cost != cost[top]) continue;

    for(auto [v, w]: adj[top]){
      if(cost[top] + w < cost[v]){
        cost[v] = cost[top] + w;
        pq.push({cost[v], v});
        parent[v] = top;
      }
    }
  }

  if(cost[end] == INT_MAX){
    cout << "Not Reachable\n";
    return;
  }

  stack<int> st;
  for(int p = end; p!=-1; p=parent[p]){
    st.push(p);
  }
  while(!st.empty()){
    cout << st.top() << ' ';
    st.pop();
  }
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
    adj[v].push_back({u, w});
  }
  // start and end is guranteed to be valid
  int start, end;
  cin >> start >> end;
  print_shortest_path(start, end, adj);
  return 0;
}