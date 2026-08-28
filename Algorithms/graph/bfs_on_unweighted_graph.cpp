#include <bits/stdc++.h>
using namespace std;

/* ----------------- BFS on Unweighted Graph O(V + E) -----------------
  BFS can be used to find the shortest path in an unweighted graph.
  BFS explores vertices level by level, so the first time a vertex is
  visited, it is reached using the minimum number of edges from the
  starting vertex.

  We store the parent of each visited vertex so that after reaching the
  destination, we can reconstruct the shortest path.

  Time Complexity:  O(V + E)
*/

vector<int> shortest_path(int start, int end, const vector<vector<int>>& adj){
  int n = adj.size();
  if(start >= n || start < 0 || end >= n || end < 0) throw new invalid_argument("Invalid start or end");
  queue<int> q;
  vector<int> parent(n, -1);
  vector<bool> visited(n);
  q.push(start);
  visited[start] = true;
  while(!q.empty()){
    int front = q.front();
    q.pop();
    if(front == end) break;

    for(const int &x: adj[front]){
      if(!visited[x]){
        q.push(x);
        parent[x] = front;
        visited[x] = true;
      }
    }
  }

  if(!visited[end]){
    return {};
  }

  vector<int> path;
  for(int p = end; p!=-1; p=parent[p]){
    path.push_back(p);
  }
  reverse(path.begin(), path.end());
  return path;
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
  int start, end;
  cin >> start >> end;
  for(int x: shortest_path(start, end, adj)){
    cout << x << ' ';
  }
  return 0;
}