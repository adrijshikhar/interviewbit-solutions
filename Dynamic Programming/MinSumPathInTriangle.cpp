#include <bits/stdc++.h>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &A)
{
  int n = A.size();
  vector<int> minlen(A.back());
  for (int k = n - 2; k >= 0; k--)
  {
    for (int i = 0; i <= k; i++)
      minlen[i] = min(minlen[i], minlen[i + 1]) + A[k][i];
  }
  return minlen[0];
}

int main()
{
  vector<vector<int>> v{
      {7},
      {1, 8},
  };
  int v2 = uniquePathsWithObstacles(v);

  cout << v2 << " ";

  return 0;
}
