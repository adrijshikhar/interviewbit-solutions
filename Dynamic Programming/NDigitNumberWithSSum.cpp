#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int digNumSum(int A, int B) {
  vector<vector<long long>> dp(A + 1, vector<long long>(B + 1, 0));
  for (int i = 1; i <= B; i++) {
    dp[1][i] = 1;
  }

  for (int i = 2; i <= A; i++) {
    for (int j = 1; j <= B; j++) {
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
    }
  }

  for (int i = 0; i <= A; i++) {
    for (int j = 0; j <= B; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  return dp[A][B] % mod;
}

int digNumSum2(int n, int s) {
  long long int dp[n][s];
  if (s < 1 || s > 9 * n)
    return 0;

  for (int i = 0; i < s; i++) {
    if (i + 1 <= 9)
      dp[0][i] = 1;
    else
      dp[0][i] = 0;
  }
  for (int j = 0; j < n; j++) {
    dp[j][0] = 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < s; j++) {
      dp[i][j] = 0;
      int k = 0;
      if (j >= 9)
        k = j - 9;
      for (; k <= j; k++)
        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
    }
  }
  return dp[n - 1][s - 1];
}

int main() {
  int A = 75, B = 22;
  int v2 = digNumSum(A, B);
  cout << v2;
  return 0;
}
