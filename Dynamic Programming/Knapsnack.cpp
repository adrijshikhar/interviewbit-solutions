#include <bits/stdc++.h>

using namespace std;

int maximiseProfit(vector<int> &p, vector<int> &w, int m) {
  int n = w.size();
  vector<int> ans(n, 0);
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++)
      if (w[i - 1] > j)
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + p[i - 1]);

  return dp[n][m];
}

int main() {
  vector<int> p{60, 100, 120};
  vector<int> w{10, 20, 30};
  int m = 50;
  int v2 = maximiseProfit(p, w, m);
  cout << v2;

  return 0;
}
