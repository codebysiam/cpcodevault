#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Prim's Algorithm (Minimum Spanning Tree) ------------------------------ */
/*
  A spanning tree is a subgraph that connects all vertices and has exactly n - 1 edges.
  A minimum spanning tree (MST) is a spanning tree with the minimum possible total edge weight.

  In this code, we use Prim's algorithm to find the MST of a weighted, undirected graph.

  The algorithm is simple and intuitive. Its implementation is similar to Dijkstra's algorithm
  because both use a priority queue, but their purposes are different. Dijkstra finds shortest
  paths, while Prim builds a minimum spanning tree.

  We represent a candidate edge as <weight, vertex, parent>, where:
  weight  = weight of the edge from parent to vertex
  vertex  = the vertex we want to add to the MST
  parent  = the vertex through which we connect it to the MST

  We start from vertex 0 and mark it as visited. Then we look at its neighbours and add edges
  leading to unvisited vertices to the priority queue.

  The priority queue always gives us the smallest-weight available edge. Therefore, we repeatedly
  take the cheapest edge that connects the current MST to an unvisited vertex.

  We do not mark a vertex as visited when we insert it into the priority queue. We mark it visited
  only when we actually pop it from the priority queue. This is important because the same vertex
  can be inserted multiple times through different edges.

  For example, a vertex may enter the priority queue with weights 10, 7, and 3. The entry with
  weight 3 will be popped first. We add that vertex to the MST using the weight-3 edge. Later,
  when the entries with weights 7 and 10 are popped, we see that the vertex is already visited
  and simply skip them.

  Therefore, whenever we visit a vertex for the first time, the edge through which we reached it
  is the minimum-weight edge that can currently connect that vertex to the MST. We store this
  edge in the 'mst' vector.

  The MST contains exactly n - 1 edges when all n vertices are connected. If some vertices remain
  unvisited after the algorithm finishes, the graph is disconnected and therefore does not have
  a spanning tree (and consequently does not have an MST).

  The 'mst' vector stores <weight, vertex, parent> for every selected edge, so it can later be
  used to reconstruct the minimum spanning tree.
*/


vector<tuple<int, int, int>> prim_mst(vector<vector<pair<int, int>>>& adj){
  int n = adj.size();
  vector<bool> visited(n, false);
  // tuple <weight, current vertex, parent vertex>
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
  pq.push({0, 0, -1});

  vector<tuple<int, int, int>> mst;
  while(!pq.empty()){
    auto [weight, cvertex, pvertex] = pq.top();
    pq.pop();

    if(visited[cvertex]) continue;
    visited[cvertex] = true;
    if(pvertex != -1) mst.push_back({weight, cvertex, pvertex});

    for(auto [nvertex, nweight]: adj[cvertex]){
      if(!visited[nvertex]){
        pq.push({nweight, nvertex, cvertex});
      }
    }
  }

  for(int i = 0; i<n; i++){
    if(!visited[i]){
      cout << "This graph doesn't have a MST";
      return {};
    }
  }

  return mst;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  for(int i = 0; i<m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  vector<tuple<int, int, int>> mst = prim_mst(adj);
  for(int i = 0; i<mst.size(); i++){
    auto [w, v, u] = mst[i];
    cout << u << " ---(" << w << ")--- " << v << '\n';
  }
}