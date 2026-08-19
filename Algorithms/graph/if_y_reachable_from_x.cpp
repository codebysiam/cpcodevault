#include <bits/stdc++.h>
using namespace std;

/* ----------------- DFS in Directed Graphs ----------------- */
/*
  The basic mechanism of DFS is the same for directed and
  undirected graphs. The main difference is how the adjacency
  list represents edges.

  In an undirected graph, if 0 and 1 are connected by an edge,
  then both adjacency lists contain each other:

      0 -- 1

  adj[0] contains 1
  adj[1] contains 0

  In a directed graph, if there is a directed edge

      0 -> 1

  then adj[0] contains 1, but adj[1] does not necessarily
  contain 0.

  Therefore, if we start DFS from 0, we can visit 1.
  But if we start DFS from 1, we cannot visit 0.
*/

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cout << R"(
      1 -> 0 --+
      |        v
      +-> 2 -> 3 -> 4 -> 5
  )" << endl;
  int x, y;
  cout << "To: " << flush;
  cin >> y;
  cout << "From: " << flush;
  cin >> x;
  vector<vector<int>> adj = {
    {3},
    {0, 2},
    {3},
    {0, 4},
    {5},
    {}
  };

  stack<int> s;
  vector<bool> visited(adj.size(), false);
  s.push(x);
  visited[x] = true;
  bool reachable = false;

  while(!s.empty()){
    int top = s.top();
    s.pop();

    if(top == y){
      reachable = true;
      break;
    }

    for(const int &v: adj[top]){
      if(!visited[v]){
        s.push(v);
        visited[v] = true;
      }
    }
  }

  cout << y << (reachable ? " is reachable" : " is not reachable") << " from " << x;
  return 0;
}