#include <bits/stdc++.h>
using namespace std;

void getAns(vector<int> &ans, vector<vector<int>> &dp, int i, int j,
            vector<int> p) {
  if (i + 1 == j)
    return;
  for (int k = i + 1; k < j; k++)
    if (dp[i][k] + dp[k][j] + p[j] - p[i] == dp[i][j]) {
      ans.push_back(p[k]);
      getAns(ans, dp, i, k, p);
      getAns(ans, dp, k, j, p);
      return;
    }
  return;
}

vector<int> minRodCutting(int A, vector<int> &B) {
  B.insert(B.begin(), 0);
  B.push_back(A);

  int n = B.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int l = 2; l <= n; l++)
    for (int i = 0; i + l - 1 < n; i++) {
      dp[i][i + l - 1] = INT_MAX;
      for (int k = i + 1; k < i + l - 1; k++)
        dp[i][i + l - 1] = min(dp[i][i + l - 1], dp[i][k] + dp[k][i + l - 1] +
                                                     B[i + l - 1] - B[i]);
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  vector<int> ans;
  getAns(ans, dp, 0, n - 1, B);
  return ans;
}

int main() {
  vector<int> v1{
      1,
      2,
      5,
  };
  vector<int> v2 = minRodCutting(6, v1);
  for (int i = 0; i < v2.size(); i++) {
    cout << v2[i] << " ";
  }

  return 0;
}
