#include <bits/stdc++.h>
#define ll long long
using namespace std;

int minSum(vector<vector<int>> A)
{
  int m = A.size(), n = A[0].size(), dp[m][n];

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == 0 && j == 0)
        dp[i][j] = A[i][j];
      else if (i == 0)
        dp[i][j] = A[i][j] + dp[i][j - 1];
      else if (j == 0)
        dp[i][j] = A[i][j] + dp[i - 1][j];
      else
        dp[i][j] = A[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
    }
  }
  
  return dp[m-1][n-1];
}

int main()
{
  vector<vector<int>> v{{3, 2, 1, 3}, {1, 9, 2, 3}, {9, 1, 5, 4}};
  int v2 = minSum(v);

  cout << v2 << " ";

  return 0;
}
