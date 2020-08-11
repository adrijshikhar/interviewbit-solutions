#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> minSum(int A, vector<vector<int>> &B) {
  int rows = B.size();
  if (rows == 0)
    return B;
  int cols = B[0].size();
  if (cols == 0)
    return B;
  while (A--) {
    vector<vector<int>> dp = B;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (i - 1 > -1)
          dp[i][j] = max(dp[i][j], B[i - 1][j]);
        if (i + 1 < rows)
          dp[i][j] = max(dp[i][j], B[i + 1][j]);
        if (j - 1 > -1)
          dp[i][j] = max(dp[i][j], B[i][j - 1]);
        if (j + 1 < cols)
          dp[i][j] = max(dp[i][j], B[i][j + 1]);
      }
    }
    B = dp;
    for (int i = 0; i < dp.size(); i++) {
      for (int j = 0; j < dp[i].size(); j++) {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }
  }
  return B;
}

int main() {
  vector<vector<int>> v{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int k = 2;
  vector<vector<int>> v2 = minSum(k, v);

  for (int i = 0; i < v2.size(); i++) {
    for (int j = 0; j < v2[i].size(); j++) {
      cout << v2[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
