#include <bits/stdc++.h>
#define ll long long
using namespace std;

int minSum(vector<vector<int>> A)
{
  int ans, i, j, dn, rig, r, c, sum;
  int n = A.size();
  int m = A[0].size();
  vector<vector<int>> rsum = A;
  for (r = 0; r < n; r++)
  {
    for (c = m - 2; c >= 0; c--)
    {
      rsum[r][c] = A[r][c] + rsum[r][c + 1];
    }
  }
  // for (r = 0; r < n; r++)
  // {
  //   for (c = 0; c < m; c++)
  //     cout << rsum[r][c] << " ";
  //   cout << endl;
  // }

  int ma = A[n - 1][m - 1];
  int dp[n][m];
  memset(dp, 0, sizeof(dp));

  for (j = m - 1; j >= 0; j--)
  {
    for (i = n - 1; i >= 0; i--)
    {
      rig = 0;
      dn = 0;
      if (i != n - 1)
        dn = dp[i + 1][j];

      if (j != m - 1)
        rig = rsum[i][j + 1];

      dp[i][j] = A[i][j] + rig + dn;
      ma = max(ma, dp[i][j]);
    }
  }

  // for (r = 0; r < n; r++)
  // {
  //   for (c = 0; c < m; c++)
  //     cout << dp[r][c] << " ";
  //   cout << endl;
  // }

  return ma;
}

int main()
{
  vector<vector<int>> v{{-5, -4, -1}, {-3, 2, 4}, {2, 5, 8}};
  int v2 = minSum(v);

  cout << v2 << " ";

  return 0;
}
