#include <bits/stdc++.h>
#define ll long long
using namespace std;

int minSum(vector<vector<int>> A) {
  int n = A.size(), minCost = 0;
  vector<vector<int>> dp(n + 1, vector<int>(3, 0));

  for (int i = 1; i <= n; i++) {
    dp[i][0] = A[i - 1][0] + min(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = A[i - 1][1] + min(dp[i - 1][0], dp[i - 1][2]);
    dp[i][2] = A[i - 1][2] + min(dp[i - 1][0], dp[i - 1][1]);
  }

  minCost = min(min(dp[n][0], dp[n][1]), dp[n][2]);
  return minCost;
}

int main() {
  vector<vector<int>> v{
      {1, 2, 3},
      {10, 11, 12},
  };

  int v2 = minSum(v);

  cout << v2 << " ";

  return 0;
}
