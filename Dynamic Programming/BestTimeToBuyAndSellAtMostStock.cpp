#include <bits/stdc++.h>
using namespace std;

int bestTimetobuyandsellstock(const vector<int> &A, int B) {
  int n = A.size();
  if (n == 0 || n == 1)
    return 0;
  if (B > n)
    B = n;
  vector<long long> dp(n);
  while (B--) {

    long long prevtrans = -A[0];
    vector<long long> newdp(n, 0);
    for (int i = 1; i < n; ++i) {

      newdp[i] = max(newdp[i - 1], A[i] + prevtrans);
      prevtrans = max(prevtrans, dp[i] - A[i]);
    }

    dp = newdp;
  }
  return dp[n - 1];
}

int main() {
  vector<int> v1{
      11, 7, 11, 17, 12, 12, 16, 10, 11,
  };

  int v2 = bestTimetobuyandsellstock(v1, 2);

  cout << v2 << " ";
  return 0;
}
