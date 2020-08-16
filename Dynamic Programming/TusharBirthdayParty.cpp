using namespace std;
#include <bits/stdc++.h>


int minCost(vector<vector<int>> A) {
  int n, m;
  if (A[0][0] == 1)
    return 0;
  int ans = 0;
  for (int k = 0; k < A[0].size(); k++) {
    m = A[0][k];
    n = A[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (A[1][i - 1] > j)
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        else
          dp[i][j] =
              max(dp[i - 1][j], dp[i - 1][j - A[1][i - 1]] + A[2][i - 1]);
      }
    }

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++)
        cout << dp[i][j] << " ";
      cout << endl;
    }
    cout << endl;

    ans += dp[n][m];
  }
  return ans;
}

int main() {
  vector<vector<int>> v{
      {4, 6},
      {1, 3},
      {5, 3},
  };
  int v2 = minCost(v);

  cout << v2 << " ";

  return 0;
}
