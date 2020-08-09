#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int numDecodings(string A) {
  int ans = 0, n = A.size();
  vector<int> dp(n + 1, 0);
  if (A[0] == '0')
    return 0;
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    if ('0' < A[i - 1])
      dp[i] = dp[i - 1];
    if (A[i - 2] == '1' || (A[i - 2] == '2' && A[i - 1] < '7'))
      dp[i] = (dp[i] % mod + dp[i - 2] % mod) % mod;
  }

  return dp[n];
}

int main() {
  string A = "10";
  int v2 = numDecodings(A);

  cout << v2 << " ";

  return 0;
}
