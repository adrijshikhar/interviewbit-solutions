#include <bits/stdc++.h>

using namespace std;

int a[4] = {1, 0, -1, 0};
int b[4] = {0, -1, 0, 1};
bool safe(int x, int y, vector<vector<char>> &A) {
  return (x >= 0 && x < A.size() && y >= 0 && y < A[0].size() &&
          A[x][y] == 'O');
}

void dfs(int x, int y, vector<vector<char>> &A) {
  A[x][y] = '#';
  for (int i = 0; i < 4; i++)
    if (safe(x + a[i], y + b[i], A))
      dfs(x + a[i], y + b[i], A);
}

void stepnum(vector<vector<char>> &A) {
  int r = A.size(), c = A[0].size();
  for (int j = 0; j < c; j++) {
    if (A[0][j] == 'O')
      dfs(0, j, A);
    if (A[r - 1][j] == 'O')
      dfs(r - 1, j, A);
  }

  for (int i = 0; i < r; i++) {
    if (A[i][0] == 'O')
      dfs(i, 0, A);
    if (A[i][c - 1] == 'O')
      dfs(i, c - 1, A);
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (A[i][j] == '#')
        A[i][j] = 'O';
      else
        A[i][j] = 'X';
    }
  }
}

int main() {
  vector<vector<char>> A{
      {'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'O', 'O', 'O'},
      {'X', 'O', 'O', 'O'}, {'X', 'O', 'O', 'O'}, {'X', 'O', 'O', 'X'},
      {'X', 'O', 'O', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'},
      {'X', 'O', 'X', 'X'},
  };
  stepnum(A);
  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < A[i].size(); j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
