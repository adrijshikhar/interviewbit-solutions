
#include <bits/stdc++.h>
using namespace std;

int dpx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dpy[8] = {-1, 1, 0, 1, -1, 0, -1, 1};

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
bool inCircle(int x, int y, int C, int D, vector<int> &E, vector<int> &F)
{
  for (int i = 0; i < C; i++)
  {
    if (((x - E[i]) * (x - E[i]) + (y - F[i]) * (y - F[i])) <= (D * D))
      return true;
  }
  return false;
}

string validPath(int A, int B, int C, int D, vector<int> &E, vector<int> &F)
{
  // visited array
  bool vis[A + 1][B + 1];
  memset(vis, false, sizeof(vis));
  queue<pair<int, int>> myque;
  myque.push({0, 0});
  vis[0][0] = true;
  // first checking wheter the point (0,0) lies in circle or not
  if (inCircle(0, 0, C, D, E, F))
    return "NO";

  while (myque.size())
  {
    // pick first element of queue
    pair<int, int> temp = myque.front();
    myque.pop();
    // checking all 8 possible moves
    for (int i = 0; i < 8; i++)
    {
      int a = temp.first + dpx[i];
      int b = temp.second + dpy[i];
      if (!vis[a][b] && valid(a, b, A, B) && !inCircle(a, b, C, D, E, F))
      {

        myque.push({a, b});
        vis[a][b] = true;
      }
    }
  }
  if (vis[A][B])
    return "YES";
  else
    return "NO";
}

int main()
{
  // Create a graph given in the above diagram
  int x = 2, y = 3, N = 1, R = 1;
  vector<int> A{2}, B{3};
  string v2 = validPath(x, y, N, R, A, B);
  cout << v2;
  return 0;
}
