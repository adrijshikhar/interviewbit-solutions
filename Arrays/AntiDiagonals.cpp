#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> diagonal(vector<vector<int>> &A)
{
  int n = A.size();
  int dir = (2 * n) - 1;
  vector<vector<int>>
      B(dir, vector<int>());
  for (int i = 0; i < dir; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (j < n && i - j < n)
      {
        B[i].push_back(A[j][i - j]);
      }
    }
  }

  return B;
}

int main()
{
  vector<vector<int>> v1{
      {1, 2, 3},
      {
          4,
          5,
          6,
      },
      {7, 8, 9},
  };
  vector<vector<int>> v2 = diagonal(v1);
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
