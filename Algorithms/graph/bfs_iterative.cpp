#include <bits/stdc++.h>
using namespace std;

/* --------------------- BFS (Breadth-First Search) Iterative O(V + E) --------------------- */
/*
  BFS prioritizes breadth over depth.
  Consider the graph:
              0
             / \
            1   2
           / \
          3   4

  BFS visits the graph level by level:
      0 -> 1 -> 2 -> 3 -> 4
  Unlike DFS, which goes as deep as possible before backtracking,
  BFS first visits all neighbours of a vertex, then their neighbours.
  We implement BFS using a queue (FIFO):
    1. Push the starting vertex into the queue and mark it visited.
    2. Remove the front vertex, process it, and add its unvisited neighbours.
    3. Repeat until the queue is empty.

  Time Complexity: O(V + E)
*/


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
  queue<int> q;
  vector<bool> visited(n);
  for(int i = 0; i<n; i++){
    if(visited[i]) continue;

    q.push(i);
    visited[i] = true;
    while(!q.empty()){
      int front = q.front();
      cout << front << ' ';
      q.pop();

      for(const int &x: adj[front]){
        if(!visited[x]){
          q.push(x);
          visited[x] = true;
        }
      }
    }
  }
  return 0;
}