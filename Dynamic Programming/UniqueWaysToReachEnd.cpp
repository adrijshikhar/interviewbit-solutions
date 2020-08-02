#include <bits/stdc++.h>
#define ll long long
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> A)
{
  int n = A.size(), m = A[0].size();
  if (A[0][0] == 1)
    return 0;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (i == 1 && j == 1)
        dp[i][j] = 1;
      else if (A[i - 1][j - 1] == 1)
        continue;
      else
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
    }
  }

  return dp[n][m];
}

int main()
{
  vector<vector<int>> v{{1, 0}};
  int v2 = uniquePathsWithObstacles(v);

  cout << v2 << " ";

  return 0;
}
