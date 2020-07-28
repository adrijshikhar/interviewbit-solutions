#include <bits/stdc++.h>
using namespace std;

int lcs(string A, string B)
{
  int row = A.size(), col = B.size();
  vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
  for (int i = 0; i <= row; i++)
  {
    for (int j = 0; j <= col; j++)
    {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (A[i - 1] == B[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  return dp[row][col];
}

int main()
{
  int v2 = lcs("wsdg", "addwdf");

  cout << v2 << " ";

  return 0;
}
