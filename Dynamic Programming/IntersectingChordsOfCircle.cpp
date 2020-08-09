#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int chordCnt(int A) {
  int ans = 0, n = 2 * (A + 1), t = 0;
  vector<long long> dp(n + 1, 0);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;
  for (int i = 4; i <= n; i += 2) {
    t = 0;
    for (int j = i - 2; j >= 0; j -= 2) {
      t = (t % mod + (dp[j] * dp[i - j]) % mod) % mod;
    }
    dp[i] = t;
  }

  return dp[n];
}

int main() {
  int A = 22;
  int v2 = chordCnt(A);

  cout << v2 << " ";

  return 0;
}
