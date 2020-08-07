#include <bits/stdc++.h>
using namespace std;

int numDistinct(string A, string B) {
  int m = B.size(), n = A.size();
  vector<vector<int>> mat(m + 1, vector<int>(n + 1, 0));

  if (m > n)
    return 0;

  for (int i = 1; i <= m; i++)
    mat[i][0] = 0;
  for (int j = 0; j <= n; j++)
    mat[0][j] = 1;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (B[i - 1] != A[j - 1])
        mat[i][j] = mat[i][j - 1];
      else
        mat[i][j] = (mat[i][j - 1] + mat[i - 1][j - 1]);
    }
  }

  return mat[m][n];
}

int main() {

  int v2 = numDistinct("rabbbit", "rabbit");

  cout << v2 << " ";

  return 0;
}
