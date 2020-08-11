#include <bits/stdc++.h>
using namespace std;

int maxcoin(vector<int> &A) {
  int n = A.size(), dp[n][n];

  for (int k = 0; k < n; ++k) {
    for (int i = 0, j = k; j < n; ++i, ++j) {
      int x = ((i + 2) <= j) ? dp[i + 2][j] : 0;
      int y = ((i + 1) <= (j - 1)) ? dp[i + 1][j - 1] : 0;
      int z = (i <= (j - 2)) ? dp[i][j - 2] : 0;

      dp[i][j] = max(A[i] + min(x, y), A[j] + min(y, z));
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << dp[i][j] << " ";
    cout << endl;
  }

  return dp[0][n - 1];
}

int main() {
  vector<int> v1{5, 4, 8, 10};
  int v2 = maxcoin(v1);
  cout << v2;
  return 0;
}
