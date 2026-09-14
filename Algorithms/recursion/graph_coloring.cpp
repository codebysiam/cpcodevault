#include <bits/stdc++.h>
using namespace std;

bool valid(int v, int color, vector<vector<int>>& adj, vector<int>& colors){
  for(int x: adj[v]){
    if(color == colors[x]) return false;
  }
  return true;
}

bool color_graph(int v, vector<vector<int>>& adj, vector<int>& colors){
  if(v == adj.size()) return true;

  for(int color = 1; color<=3; color++){
    if(valid(v, color, adj, colors)){
      colors[v] = color;
      if(color_graph(v+1, adj, colors)) return true;
      colors[v] = 0;
    }
  }

  return false;
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  while(m--){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> colors(n, 0);
  if(color_graph(0, adj, colors)){
    for(int x: colors){
      cout << x << ' ';
    }
  }else{
    cout << "This graph can't be colored.";
  }
  return 0;
}