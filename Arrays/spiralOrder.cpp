#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> spiralOrder(const vector<vector<int>> &A)
{
  vector<int> B;
  int t = 0, b = A.size() - 1, l = 0, r = A[0].size() - 1;
  int dir = 0;

  while (t <= b && l <= r)
  {
    if (dir == 0)
    {
      for (int i = t; i <= r; i++)
      {
        B.push_back(A[t][i]);
      }
      t++;
      dir = 1;
    }
    else if (dir == 1)
    {
      for (int i = t; i <= b; i++)
      {
        B.push_back(A[i][r]);
      }
      r--;
      dir = 2;
    }
    else if (dir == 2)
    {
      for (int i = r; i >= l; i--)
      {
        B.push_back(A[b][i]);
      }
      b--;
      dir = 3;
    }
    else if (dir == 3)
    {
      for (int i = b; i >= t; i--)
      {
        B.push_back(A[i][l]);
      }
      l++;
      dir = 0;
    }
  }

  return B;
}

int main()
{
  vector<vector<int>> v1{{1, 2, 3}, {
                                        4,
                                        5,
                                        6,
                                    },
                         {7, 8, 9},
                         {10, 11, 12}};
  vector<int> v2 = spiralOrder(v1);
  for (auto i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << " ";
  }

  return 0;
}
