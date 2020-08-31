#include <bits/stdc++.h>
#define ll long long
using namespace std;

int minSum(vector<vector<int>> A) {
  int m = A.size(), n = A[0].size(), k;
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
  dp[m - 1][n] = 1;
  dp[m][n - 1] = 1;

  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      k = min(dp[i + 1][j], dp[i][j + 1]) - A[i][j];
      dp[i][j] = k <= 0 ? 1 : k;
    }
  }

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++)
      cout << setw(12) << dp[i][j];
    cout << endl;
  }

  return dp[0][0];
}

int main() {
  vector<vector<int>> v{
      {-2, -3, 3},
      {-5, -10, 1},
      {10, 30, -5},
  };
  int v2 = minSum(v);

  cout << v2 << " ";

  return 0;
}
