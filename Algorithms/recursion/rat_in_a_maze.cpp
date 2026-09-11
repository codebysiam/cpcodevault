#include <bits/stdc++.h>
using namespace std;

const vector<tuple<int, int, char>> dir = {{-1, 0, 'U'}, {0, 1, 'R'}, {1, 0, 'D'}, {0, -1, 'L'}};
void solve_maze(pair<int, int> start, vector<vector<int>>& maze, vector<vector<bool>>& visited, string& path){
  auto [r, c] = start;
  const int n = maze.size();

  if(r == n-1 && c == n-1){
    cout << path << '\n';
    return;
  }

  visited[r][c] = true;

  for(auto [row, col, direction]: dir){
    row+=r;
    col+=c;
    if(row >= 0 && col >= 0 && row < n && col < n && !visited[row][col] && maze[row][col] != 0){
      path.push_back(direction);
      solve_maze({row, col}, maze, visited, path);
      path.pop_back();
    }
  }

  visited[r][c] = false;
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> maze(n, vector<int>(n));
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      cin >> maze[i][j];
    }
  }
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  string path;
  solve_maze({0, 0}, maze, visited, path);
  return 0;
}