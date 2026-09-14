#include <bits/stdc++.h>
using namespace std;

bool safe(int x, int row, int col, const vector<vector<int>>& board){
  int n = 9;

  for(int r = 0; r<n; r++){
    if(board[r][col] == x) return false;
  }

  for(int c = 0; c<n; c++){
    if(board[row][c] == x) return false;
  }

  int sr = (row/3)*3;
  int sc = (col/3)*3;
  for(int r = sr; r<sr+3; r++){
    for(int c = sc; c<sc+3; c++){
      if(board[r][c] == x) return false;
    }
  }

  return true;
}

bool solve_sudoku(int row, int col, vector<vector<int>>& board){
  int n = 9;

  if(row == n) return true;

  if(col == n) return solve_sudoku(row+1, 0, board);

  if(board[row][col] != 0) return solve_sudoku(row, col+1, board);

  for(int x = 1; x<=n; x++){
    if(safe(x, row, col, board)){
      board[row][col] = x;
      if(solve_sudoku(row, col+1, board)) return true;
      board[row][col] = 0;
    }
  }

  return false;
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n = 9;
  vector<vector<int>> board(n, vector<int>(n));
  for(auto &row: board){
    for(auto &col: row){
      cin >> col;
    }
  }
  if(solve_sudoku(0, 0, board)){
    for(auto row: board){
      for(auto col: row){
        cout << col << ' ';
      }
      cout << '\n';
    }
  }else{
    cout << "No solution exists.";
  }
  return 0;
}