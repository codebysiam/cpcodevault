#include <bits/stdc++.h>
using namespace std;

/* -------------- Floyd-Warshall (all-pairs shortest path) -------------- */
/*
  In Floyd-Warshall algorithm, we try every vertex as an intermediate 
  between every pair.

  We first allow 0 and keep every cheaper path we find.
  Then allow 1 and use all the cheaper paths we already found.
  Then allow 2 and use everything found so far, and so on.

  In other words, we keep expanding the set of vertices that can
  be used in the middle of a path, while continuously improving
  the distances.

  Once every vertex has been allowed, we have considered every
  possible intermediate vertex, so the distances are shortest.

  transition:
  start -> end
  vs.
  start -> via -> end
*/

bool floyd_warshall(vector<vector<int>>& dist){
  int n = dist.size();

  for(int via = 0; via<n; via++){
    for(int start = 0; start<n; start++){
      for(int end = 0; end<n; end++){
        if(dist[start][via] != INT_MAX && dist[via][end] != INT_MAX){
          dist[start][end] = min(dist[start][end], dist[start][via] + dist[via][end]);
        }
      }
    }
  }

  for(int i = 0; i<n; i++){
    if(dist[i][i] < 0) return false;
  }

  return true;
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
  for(int i = 0; i<n; i++){
    dist[i][i] = 0;
  }
  for(int i = 0; i<m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    dist[u][v] = min(dist[u][v], w);
  }
  if(floyd_warshall(dist)){
    for(int start = 0; start<n; start++){
      for(int end = 0; end<n; end++){
        cout << dist[start][end] << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}