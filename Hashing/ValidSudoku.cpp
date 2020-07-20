#include <bits/stdc++.h>

using namespace std;
bool isRowValid(const vector<string> &A, int row)
{
  set<int> s;
  for (int j = 0; j < 9; j++)
  {
    char ch = A[row][j];
    if (s.find(ch) != s.end())
    {
      return false;
    }
    if (ch != '.')
      s.insert(ch);
  }
  return true;
}
bool isColValid(const vector<string> &A, int col)
{
  set<int> s;
  for (int i = 0; i < 9; i++)
  {
    char ch = A[i][col];
    if (s.find(ch) != s.end())
    {
      return false;
    }
    if (ch != '.')
      s.insert(ch);
  }
  return true;
}
bool isBoxValid(const vector<string> &A, int row, int col)
{
  set<int> s;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      char ch = A[i + row][j + col];
      if (s.find(ch) != s.end())
      {
        return false;
      }
      if (ch != '.')
        s.insert(ch);
    }
  }
  return true;
}
bool isValid(const vector<string> &A, int row, int col)
{
  return isRowValid(A, row) && isColValid(A, col) && isBoxValid(A, row - row % 3, col - col % 3);
}
int isValidSudoku(const vector<string> &A)
{
  for (int i = 0; i < A.size(); i++)
  {
    for (int j = 0; j < A[i].size(); j++)
    {
      if (A[i][j] != '.')
      {
        if (!isValid(A, i, j))
        {
          return 0;
        }
      }
    }
  }
  return 1;
}

int main()
{
  vector<string> v1{"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};
  int v2 = isValidSudoku(v1);

  cout << v2;

  return 0;
}
