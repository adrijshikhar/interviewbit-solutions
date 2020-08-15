#include <bits/stdc++.h>
using namespace std;
#define m 1000007

int coinchange2(vector<int> &A, int B) {
  int n = A.size();
  vector<int> dp(B + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= n; i++)
    for (int j = A[i - 1]; j <= B; j++)
      dp[j] += dp[j - A[i - 1]] % m;

  return dp[B] % m;
}

int main() {

  vector<int> v1{
      1,
      2,
      3,
  };
  int v2 = coinchange2(v1, 4);
  cout << v2 << " ";

  return 0;
}
