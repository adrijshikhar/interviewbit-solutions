#include <bits/stdc++.h>
using namespace std;

int uniqueCoinChange(const vector<int> &A, int B)
{
  int n = A.size();
  if (n == 0)
    return 0;
  vector<vector<int>> mat(n + 1, vector<int>(B + 1, 0));

  for (int i = 0; i < mat.size(); i++)
    mat[i][0] = 1;

  for (int j = 1; j < mat[0].size(); j++)
    mat[0][j] = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= B; j++)
    {
      if (j < A[i - 1])
        mat[i][j] = mat[i - 1][j];
      else
        mat[i][j] = mat[i - 1][j] + mat[i][j - A[i - 1]];
    }
  }
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= B; j++)
      cout << mat[i][j] << " ";
    cout << endl;
  }

  return mat[n][B];
}

int main()
{
  vector<int> v1{1, 2, 5};
  int v2 = uniqueCoinChange(v1, 5);

  cout << v2 << " ";

  return 0;
}
