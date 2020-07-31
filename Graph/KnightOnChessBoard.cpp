
#include <bits/stdc++.h>
using namespace std;

bool valid(int x, int y, int A, int B)
{
  if (x < 1 || x > A || y < 1 || y > B)
  {
    return false;
  }
  return true;
}

int knight(int A, int B, int C, int D, int E, int F)
{
  int dpx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
  int dpy[8] = {-2, 2, 1, -1, 2, -2, 1, -1};
  queue<pair<int, int>> myque;

  vector<vector<int>> path(A + 1, vector<int>(B + 1, 0));

  if (C == E && D == F)
    return 0;
  myque.push({C, D});
  while (!myque.empty())
  {
    pair<int, int> temp = myque.front();
    myque.pop();
    // checking all 8 possible moves
    for (int i = 0; i < 8; i++)
    {
      int a = temp.first + dpx[i];
      int b = temp.second + dpy[i];
      if (valid(a, b, A, B))
      {
        if (!path[a][b])
        {
          myque.push({a, b});
          path[a][b] = path[temp.first][temp.second] + 1;
        }
        else
        {
          if (path[temp.first][temp.second] + 1 < path[a][b])
            path[a][b] = path[temp.first][temp.second] + 1;
        }
      }
      if (a == E && b == F)
        return path[a][b];
    }
  }
  for (int i = 0; i < A + 1; i++)
  {
    for (int j = 0; j < B + 1; j++)
    {
      cout << path[i][j] << " ";
    }
    cout << endl;
  }

  if (path[E][F] == 0)
    return -1;

  return path[E][F];
}

int main()
{
  int A = 2, B = 20, C = 1, D = 18, E = 1, F = 5;
  int v2 = knight(A, B, C, D, E, F);
  cout << v2;
  return 0;
}
