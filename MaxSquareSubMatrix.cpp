#include <bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &A) {

  int m = A.size(), n = A[0].size(), maxx = INT_MIN;
  vector<vector<int>> dp = A;
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = min(A[i][j - 1], min(A[i - 1][j - 1], A[i - 1][j])) + 1;
      if (maxx < dp[i][j])
        maxx = dp[i][j];
    }
  }
  return maxx;
}

int main() {
  vector<vector<int>> A{
      {0, 1, 1},
      {0, 1, 1},
      {0, 0, 0},
  };
  int v2 = median(A);

  cout << v2 << " ";

  return 0;
}
