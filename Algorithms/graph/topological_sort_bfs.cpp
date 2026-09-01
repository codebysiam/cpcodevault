#include <bits/stdc++.h>
using namespace std;

/* --------------- Topological Sort Using BFS (Kahn's Algorithm) --------------- */
/*
  Topological sort is a technique where we arrange all vertices of a Directed
  Acyclic Graph (DAG) in an array such that for every edge u -> v, u comes
  before v.

  For example:

          A
         / \
        v   v
        B<- C

  Where A -> B, A -> C, C -> B

  A valid topological order is: A C B
  Why? A has no dependencies, so nothing needs to come before it. C depends on A,
  so A must come before C. B depends on both A and C, so both A and C must come 
  before B.

  We implemented topological sort in previous files using DFS. In the code
  below, we implement it using a queue-based approach called Kahn's Algorithm.

  In this algorithm, we use an in-degree array where we store the number of
  incoming edges of every vertex.

  First, we find all vertices with an in-degree of 0 and push them into the
  queue. Then, we process the queue.

  For every vertex we process, we decrease the in-degree of all its adjacent
  vertices by 1. If the in-degree of a vertex becomes 0, we push it into the
  queue and continue the same process until the queue becomes empty.

  If the graph contains a cycle, the algorithm will stop before processing all
  vertices because the vertices inside the cycle can never have an in-degree
  of 0.

  So, if ans.size() != n, the graph contains a cycle.
*/


void topoSort(vector<vector<int>>& adj){
  int n = adj.size();
  vector<int> in_degree(n, 0);
  for(int i = 0; i<n; i++){
    for(int j: adj[i]){
      in_degree[j]++;
    }
  }

  queue<int> q;
  for(int i = 0; i<n; i++){
    if(in_degree[i] == 0){
      q.push(i);
    }
  }

  vector<int> ans;
  while(!q.empty()){
    int front = q.front();
    q.pop();
    ans.push_back(front);

    for(int x: adj[front]){
      in_degree[x]--;
      if(in_degree[x] == 0){
        q.push(x);
      }
    }
  }

  if(ans.size() != n) {
    cout << "The graph contains a cycle\n";
    return;
  }

  for(int x: ans){
    cout << x << ' ';
  }

}

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for(int i = 0; i<m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  topoSort(adj);
  return 0;
}