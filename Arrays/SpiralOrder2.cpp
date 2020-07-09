#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int A)
{
  vector<vector<int>> B(A, vector<int>(A));
  int t = 0, b = A - 1, l = 0, r = A - 1, k = 1;
  int dir = 0;

  while (t <= b && l <= r)
  {
    switch (dir)
    {
    case 0:
      for (int i = l; i <= r; i++)
      {
        B[t][i] = k;
        k++;
      }
      t++;
      break;
    case 1:
      for (int i = t; i <= b; i++)
      {
        B[i][r] = k;
        k++;
      }
      r--;
      break;
    case 2:
      for (int i = r; i >= l; i--)
      {
        B[b][i] = k;
        k++;
      }
      b--;
      break;
    case 3:
      for (int i = b; i >= t; i--)
      {
        B[i][l] = k;
        k++;
      }
      l++;
      break;
    default:
      break;
    }
    dir = (dir + 1) % 4;
  }

  return B;
}

int main()
{
  int v1 = 0;
  vector<vector<int>> v2 = generateMatrix(v1);
  for (auto i = 0; i < v2.size(); i++)
  {
    for (int j = 0; j < v2[i].size(); j++)
    {
      cout << v2[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
