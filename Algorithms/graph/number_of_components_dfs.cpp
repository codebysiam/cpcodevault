#include <bits/stdc++.h>
using namespace std;

/* --------------------- Number of Connected Components O(V + E) --------------------- */
/*
  A graph can contain multiple groups of connected vertices. These groups are called
  connected components. Inside a connected component, there is a path between every
  pair of vertices, while the component is disconnected from all other components.

            0      3 -- 4
           / \     |  /     * 7
          1 - 2    6 -- 5

  In this code, we use DFS to count the number of connected components in the graph.
  In the graph above, there are 3 connected components. So, if we run our code
  in this graph, it will return 3.

  We loop through every vertex and check whether it has already been visited. If a
  vertex is already visited, it means that it belongs to a connected component that
  we have already explored, so we do not count it again.

  If a vertex has not been visited yet, it means that we have found a new connected
  component. We start DFS from that vertex, visit all vertices belonging to that
  component, mark them as visited, and increase the component count by 1.

  We implement DFS in two ways:
    1. Iterative DFS using a stack.
    2. Recursive DFS using the function call stack.

  We only need to use one of them.
*/

void dfs_itr(const vector<vector<int>>& adj, vector<bool>& visited, int start){
  stack<int> s;
  s.push(start);
  visited[start] = true;

  while(!s.empty()){
    int top = s.top();
    s.pop();

    for(const int &x: adj[top]){
      if(!visited[x]){
        s.push(x);
        visited[x] = true;
      }
    }
  }
}

void dfs_rec(vector<vector<int>>& adj, vector<bool>& visited, int strt){
  visited[strt] = true;
  for(const int &x: adj[strt]){
    if(!visited[x]){
      dfs_rec(adj, visited, x);
    }
  }
}


int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  vector<vector<int>> adj = {
    {1, 2},       // 0
    {0, 2, 3},    // 1
    {0, 1, 3},    // 2
    {1, 2},       // 3

    {5},          // 4
    {4},          // 5

    {7, 8},       // 6
    {6, 8},       // 7
    {6, 7, 9},    // 8
    {8},          // 9

    {},           // 10  <- isolated vertex

    {12},         // 11
    {11, 13},     // 12
    {12},         // 13

    {15, 16},     // 14
    {14},         // 15
    {14}          // 16
  };

  int n = adj.size();
  vector<bool> visited(n, false);
  int cnt = 0;
  for(int v = 0; v<n; v++){
    if(!visited[v]){
      dfs_itr(adj, visited, v);
      // dfs_rec(adj, visited, v);
      cnt++;
    }
  }
  cout << "There are " << cnt << " connected components in the graph";
  return 0;
}