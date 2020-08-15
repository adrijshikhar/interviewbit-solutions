#include <bits/stdc++.h>
#define ll long long
using namespace std;

int minSum(vector<vector<int>> A) {
  int n = A.size(), mx = A[0][0];
  vector<vector<int>> dp = A;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == 0)
        dp[i][j] = A[i][j] + dp[i - 1][j];
      else
        dp[i][j] = A[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
      mx = max(mx, dp[i][j]);
    }
  }

  return mx;
}

int main() {
  vector<vector<int>> v{
      {8, 0, 0, 0},
      {4, 4, 0, 0},
      {2, 2, 6, 0},
      {1, 1, 1, 1},
  };
  int v2 = minSum(v);

  cout << v2 << " ";

  return 0;
}
