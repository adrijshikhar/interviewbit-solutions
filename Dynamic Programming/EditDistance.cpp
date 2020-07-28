#include <bits/stdc++.h>
#define ll long long
using namespace std;

int min3(int x, int y, int z)
{
  return min(min(x, y), z);
}
int minDistance(string A, string B)
{
  int m = A.size(), n = B.size(), dp[m + 1][n + 1];

  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i == 0)
        dp[i][j] = j; // Min. operations = j

      else if (j == 0)
        dp[i][j] = i; // Min. operations = i

      else if (A[i - 1] == B[j - 1])
        dp[i][j] = dp[i - 1][j - 1];

      else
        dp[i][j] = 1 + min3(dp[i][j - 1],      // Insert
                            dp[i - 1][j],      // Remove
                            dp[i - 1][j - 1]); // Replace
    }
  }

  return dp[m][n];
}

int main()
{
  int v2 = minDistance("wsdg", "asdf");

  cout << v2 << " ";

  return 0;
}
