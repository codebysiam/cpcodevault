#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ BFS on Grids ------------------------------ */
/*
  In this code, we use BFS on a grid where each cell can move in 4 directions:
  up, right, down, and left.
  We use BFS to find the shortest path starting from S and ending at E. A valid
  path cannot pass through '#', so we can think of '#' as an obstacle.
  BFS on a grid follows the exact same concept as normal BFS on a graph. The
  only difference is how we find the neighbors of a node.
  In a normal graph, we take the front node from the queue and check all of its
  neighbors. If a neighbor has not been visited, we mark it as visited and push
  it into the queue.
  In a grid, each cell can be thought of as a node. Instead of having an
  adjacency list that explicitly stores its neighbors, we find the neighbors by
  checking the cells in the possible directions.
  So, when we take the front cell from the queue, we check whether we can move
  up, right, down, or left from that cell.

  For every direction:
  - We calculate the coordinates of the next cell.
  - We check whether the cell is inside the grid.
  - We check whether it has already been visited.
  - We check whether it is an obstacle ('#').

  If the cell is valid, we mark it as visited and push it into the queue.
  BFS explores cells level by level. It first visits all cells that are 1 move
  away from S, then all cells that are 2 moves away, then all cells that are
  3 moves away, and so on.
  Therefore, when BFS reaches E for the first time, we know that it has reached
  E using the minimum possible number of moves. This is why BFS can find the
  shortest path in an unweighted grid.
  We also use an extra parent vector to keep track of how we reached each cell.
  Whenever we move from a cell (i, j) to a new cell (ni, nj), we store:

    parent[ni][nj] = {i, j};

  This means that (i, j) is the cell from which we reached (ni, nj).
  After reaching E, we can reconstruct the path by repeatedly moving to the
  parent of the current cell:

    E -> parent[E] -> parent[parent[E]] -> ...

  Eventually, we reach S.
  This gives us the path in reverse order, from E to S. Therefore, we use a
  stack to reverse the order and print the path correctly from S to E.
*/

void bfs(pair<int, int> start, vector<vector<char>>& grid){
  int n = grid.size();
  int m = grid[0].size();
  queue<pair<int, int>> q;
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  vector<pair<int, int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
  q.push(start);
  visited[start.first][start.second] = true;

  pair<int, int> end = {-1, -1};

  while(!q.empty()){
    auto [i, j] = q.front();
    q.pop();
    if(grid[i][j] == 'E'){
      end = {i, j};
      break;
    }
    
    for(int x = 0; x<4; x++){
      int ni = direction[x].first + i;
      int nj = direction[x].second + j;

      if(ni >= 0 && nj >= 0 && ni < n && nj < m && !visited[ni][nj] && grid[ni][nj] != '#'){
        q.push({ni, nj});
        visited[ni][nj] = true;
        parent[ni][nj] = {i, j};
      }
    }
  }

  if(end.first == -1) return;

  stack<pair<int, int>> st;
  auto [i, j] = end;
  while(i != -1 && j != -1){
    st.push({i, j});
    auto [pi, pj] = parent[i][j];
    i = pi;
    j = pj;
  }

  while(!st.empty()){
    cout << st.top().first << ' ' << st.top().second << '\n';
    st.pop();
  }
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  pair<int, int> start = {0, 0};
  vector<vector<char>> grid(n, vector<char>(m));
  for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
      char x;
      cin >> x;
      if(x == 'S') start = {i, j};
      grid[i][j] = x;
    }
  }
  bfs(start, grid);
  return 0;
}