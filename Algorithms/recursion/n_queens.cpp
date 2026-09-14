#include <bits/stdc++.h>
using namespace std;

bool safe(int row, int col, vector<vector<char>>& board){
  int n = board.size();

  for(int r = 0; r<row; r++){
    if(board[r][col] == 'Q') return false;
  }
  for(int r = row-1, c = col+1; r>=0 && c<n; r--, c++){
    if(board[r][c] == 'Q') return false;
  }

  for(int r = row-1, c = col-1; r>=0 && c>=0; r--, c--){
    if(board[r][c] == 'Q') return false;
  }

  return true;
}

bool place_queens(int row, vector<vector<char>>& board){
  int n = board.size();

  if(row == n) return true;

  for(int i = 0; i<n; i++){
    if(safe(row, i, board)){
      board[row][i] = 'Q';
      if(place_queens(row+1, board)) return true;
      board[row][i] = '.';
    }
  }
  
  return false;
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<char>> board(n, vector<char>(n, '.'));
  if(place_queens(0, board)){
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