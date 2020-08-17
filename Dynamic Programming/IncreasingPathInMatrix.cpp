#include <bits/stdc++.h>
using namespace std;

int maxPath(vector<vector<int>> A) {
  int m = A.size(), n = A[0].size();
  vector<vector<int>> dp(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 && j == 0)
        dp[i][j] = 1;
      else if (i == 0) {
        if (A[i][j - 1] < A[i][j] && dp[i][j - 1] != -1)
          dp[i][j] = 1 + dp[i][j - 1];
        else
          dp[i][j] = -1;
      } else if (j == 0) {
        if (A[i - 1][j] < A[i][j] && dp[i - 1][j] != -1)
          dp[i][j] = 1 + dp[i - 1][j];
        else
          dp[i][j] = -1;
      } else if (A[i - 1][j] < A[i][j] || A[i][j - 1] < A[i][j])
        if (min(dp[i - 1][j], dp[i][j - 1]) == -1)
          dp[i][j] = -1;
        else
          dp[i][j] = 1 + max(dp[i - 1][j], dp[i][j - 1]);
      else {
        if (min(dp[i - 1][j], dp[i][j - 1]) == -1)
          dp[i][j] = -1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  return dp[m - 1][n - 1];
}

int main() {
  vector<vector<int>> v{
      {63, 56, 11, 60, 25, 38, 49, 84, 96, 42, 3, 51},

  };
  int v2 = maxPath(v);

  cout << v2 << " ";

  return 0;
}
