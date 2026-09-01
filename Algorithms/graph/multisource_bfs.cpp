#include <bits/stdc++.h>
using namespace std;

/* -------------------------------- Multisource BFS -------------------------------- */
/*
  We normally use BFS when we have one starting point and want to explore the
  graph level by level.

  But what if we have multiple starting points?

  We can simply put all of them into the queue at the beginning and let BFS
  do its thing. That's basically Multisource BFS.
  You can think of it like multiple people starting to walk through the grid
  at the same time. Everyone takes one step at a time, and whoever reaches a
  cell first claims it.

  In this example, we have a grid with walls and paths, and several sources.
  Each source has its own label and color. The goal is to figure out which
  source reaches each cell first.

  So there isn't really any special BFS trick here. The main idea is just:
    Single source -> put one source in the queue.
    Multiple sources -> put all sources in the queue.
    
  The `dist` array keeps track of how far each cell is from its nearest source,
  while `source` remembers which source reached that cell.

  I also added some colors to make the result a little more fun to look at.
*/


int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m, s;
  cin >> n >> m >> s;

  map<string, string> colors = {
    {"reset",   "\033[0m"},
    {"red",     "\033[31m"},
    {"green",   "\033[32m"},
    {"yellow",  "\033[33m"},
    {"blue",    "\033[34m"},
    {"dim",       "\033[2m"},
    {"magenta",      "\033[35m"},
    {"cyan",         "\033[36m"},
  };

  vector<vector<char>> grid(n, vector<char>(m));
  vector<vector<int>> dist(n, vector<int>(m, -1));
  vector<vector<string>> source(n, vector<string>(m, colors["dim"]+'#'+colors["reset"]));
  for(int r = 0; r<n; r++){
    for(int c = 0; c<m; c++){
      cin >> grid[r][c];
    }
  }
  queue<pair<int, int>> q;
  for(int i = 0; i<s; i++){
    int r, c;
    string l, color;
    cin >> r >> c >> l >> color;
    q.push({r, c});
    dist[r][c] = 0;
    source[r][c] = colors[color]+l+"\033[0m";
  }

  vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  while(!q.empty()){
    auto [r, c] = q.front();
    q.pop();

    for(int i = 0; i<4; i++){
      int nr = directions[i][0] + r;
      int nc = directions[i][1] + c;
      if(nr >= 0 && nc >= 0 && nr < n && nc < m && dist[nr][nc] < 0 && grid[nr][nc] != '#'){
        q.push({nr, nc});
        dist[nr][nc] = dist[r][c]+1;
        source[nr][nc] = source[r][c];
      }
    }
  }

  for(int r = 0; r<n; r++){
    for(int c = 0; c<m; c++){
      cout << source[r][c] << ' ';
    }
    cout << '\n';
  }
  return 0;
}


/* ---------------- A Simple Test Case ----------------*/
/*


11 21 6
.....................
.....................
....#####............
.....................
..........###........
.....................
..............#####..
.....................
...######............
.....................
.....................
0 0 A red
0 20 B green
10 0 C yellow
10 20 D blue
5 3 E magenta
5 17 F cyan


*/