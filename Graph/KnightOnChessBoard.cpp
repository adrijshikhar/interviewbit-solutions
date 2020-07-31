
#include <bits/stdc++.h>
using namespace std;

int dpx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dpy[8] = {-2, 2, 1, -1, 2, -2, 1, -1};

// this function is used to check wheter the i,j column lies inside the rectangle or not
bool valid(int x, int y, int A, int B)
{
  if (x < 0 || x > A || y < 0 || y > B)
  {
    return false;
  }
  return true;
}

// this function check wheter the point x,y lies inside any circle or not

int knight(int A, int B, int C, int D, int E, int F)
{
  // visited array
  queue<pair<int, int>> myque;
  int path[A][B];
  memset(path, 0, sizeof(path));

  if (C == E && D == F)
    return 0;
  myque.push({C - 1, D - 1});
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
        if (a == E && b == F)
        {
          return path[a][b];
        }
      }
    }
  }


  if (path[E - 1][F - 1] == 0)
    return -1;

  return path[E - 1][F - 1];
}



int main()
{
  int A = 8, B = 8, C = 1, D = 1, E = 8, F = 8;
  int v2 = knight(A, B, C, D, E, F);
  cout << v2;
  return 0;
}
