#include <bits/stdc++.h>

using namespace std;

vector<int> maximiseProfit(vector<int> &p, vector<int> &w, int m) {

  int n = w.size();
  vector<int> ans(n, 0);
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (w[i - 1] > j)
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + p[i - 1]);
    }
  }
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < m + 1; j++)
      cout << dp[i][j] << " ";
    cout << endl;
  }
  return ans;
}

int main() {
  vector<int> p{1, 2, 5, 6};
  vector<int> w{2, 3, 4, 5};
  int m = 8;
  vector<int> v2 = maximiseProfit(p, w, m);
  for (int i = 0; i < v2.size(); i++)
    cout << v2[i];

  return 0;
}
