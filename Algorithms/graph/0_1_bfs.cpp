#include <bits/stdc++.h>
using namespace std;

/* ----------------- 0-1 BFS (Shortest Path) -----------------*/
/*
  0-1 BFS finds shortest paths in a graph where every edge has
  a weight of either 0 or 1.

  It is similar to BFS, but instead of treating every edge equally,
  we prioritize edges with less cost:
    - weight 0 -> push the vertex to the front of the deque
    - weight 1 -> push the vertex to the back of the deque

  When we find a more efficient path to a vertex, we relax it by
  updating its distance and parent. We then put the vertex back
  into the deque so that its improved distance can be used to
  potentially relax its neighboring vertices.

  The parent array keeps track of how each vertex was reached.
  We can later use it to reconstruct the shortest path.
*/

void print_shortest_path(int start, int end, vector<vector<pair<int, int>>>& adj){
  int n = adj.size();
  if(start >= n || start < 0 || end >= n || end < 0) throw invalid_argument("Invalid start or end");
  deque<int> dq;
  vector<int> dist(n, INT_MAX);
  vector<int> parent(n, -1);
  dq.push_back(start);
  dist[start] = 0;

  while(!dq.empty()){
    int front = dq.front();
    dq.pop_front();

    for(auto [v, w]: adj[front]){
      if(dist[front] + w < dist[v]){
        dist[v] = dist[front] + w;
        parent[v] = front;

        if(w){
          dq.push_back(v);
        }else{
          dq.push_front(v);
        }
      }
    }
  }

  if(dist[end] == INT_MAX) {
    cout << "unreachable" << '\n';
    return;
  }

  stack<int> st;
  for(int p = end; p!=-1; p = parent[p]){
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
    if(w > 1 || w < 0) throw invalid_argument("Weight must be 0 or 1");
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  int start, end;
  cin >> start >> end;

  print_shortest_path(start, end, adj);
  return 0;
}