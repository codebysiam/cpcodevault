#include <bits/stdc++.h>
using namespace std;

/* ------------------------- Topological Sort Using DFS O(V + E) ------------------------- */
/*
  Topological sort is a technique where we arrange the vertices of a directed graph in an
  order such that, for every directed edge u -> v, u comes before v in the result. In simple
  words, if v depends on u, then u should come before v.

  Here we use DFS. The key idea is that we do NOT put a vertex into the result when we first
  visit it. We first explore all of its outgoing neighbors. Only after all of them are finished
  do we push the current vertex into the stack.

  Therefore, for an edge u -> v, v is finished before u. Since we use a stack, u will be popped
  before v, giving the required order.

  We run DFS from every unvisited vertex because the graph may contain multiple disconnected
  components.

  Topological sorting is only possible for a Directed Acyclic Graph (DAG), meaning the graph
  must not contain any cycle.

  This implementation assumes the graph is a DAG; it does not detect cycles.

  Time Complexity: O(V + E)
  Space Complexity: O(V)
*/

void topoSort(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st){
  visited[v] = true;
  for(const int &x: adj[v]){
    if(!visited[x]){
      topoSort(x, adj, visited, st);
    }
  }
  st.push(v);
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
  }
  vector<bool> visited(n);
  stack<int> st;
  for(int i = 0; i<n; i++){
    if(visited[i]) continue;
    topoSort(i, adj, visited, st);
  }

  while(!st.empty()){
    cout << st.top() << ' ';
    st.pop();
  }
  return 0;
}