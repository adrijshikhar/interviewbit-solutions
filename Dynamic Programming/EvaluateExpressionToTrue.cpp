#include <bits/stdc++.h>

using namespace std;

int cnttrue(string A) {
  int i, j, k, l, n = A.size(), mod = 1003;
  int T[n][n], F[n][n];
  memset(T, 0, sizeof(T));
  memset(F, 0, sizeof(F));
  for (i = 0; i < n; i++) {
    T[i][i] = (A[i] == 'T') ? 1 : 0;
    F[i][i] = (A[i] == 'F') ? 1 : 0;
  }

  for (l = 3; l <= n; l = l + 2) {
    for (i = 0; i < n - l + 1; i++) {
      j = i + l - 1;
      for (k = i + 1; k < j; k = k + 2) {
        if (A[k] == '^') {
          T[i][j] +=
              (T[i][k - 1] * F[k + 1][j] + F[i][k - 1] * T[k + 1][j]) % mod;
          F[i][j] +=
              (T[i][k - 1] * T[k + 1][j] + F[i][k - 1] * F[k + 1][j]) % mod;
        }
        if (A[k] == '&') {
          T[i][j] += (T[i][k - 1] * T[k + 1][j]) % mod;
          F[i][j] += (F[i][k - 1] * F[k + 1][j] + T[i][k - 1] * F[k + 1][j] +
                      F[i][k - 1] * T[k + 1][j]) %
                     mod;
        }
        if (A[k] == '|') {
          T[i][j] += (T[i][k - 1] * T[k + 1][j] + T[i][k - 1] * F[k + 1][j] +
                      F[i][k - 1] * T[k + 1][j]) %
                     mod;
          F[i][j] += (F[i][k - 1] * F[k + 1][j]) % mod;
        }
      }
    }
  }
  return T[0][n - 1] % mod;
}

int main() {
  string v = "T|F";
  int v2 = cnttrue(v);

  cout << v2 << " ";

  return 0;
}
