#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>> &A) {

  int m = A.size(), n = A[0].size();
  int r1 = 0, c1 = 0;
  for (int i = 0; i < n; i++)
    if (A[0][i] == 0) {
      r1 = 1;
      break;
    }

  for (int i = 0; i < m; i++)
    if (A[i][0] == 0) {
      c1 = 1;
      break;
    }

  for (int i = 1; i < m; i++)
    for (int j = 1; j < n; j++)
      if (A[i][j] == 0) {
        A[i][0] = 0;
        A[0][j] = 0;
      }

  for (int i = 1; i < m; i++)
    for (int j = 1; j < n; j++)
      if (A[i][0] == 0 || A[0][j] == 0)
        A[i][j] = 0;

  if (r1 == 1)
    for (int i = 0; i < n; i++)
      A[0][i] = 0;

  if (c1 == 1)
    for (int i = 0; i < m; i++)
      A[i][0] = 0;
}

int main() {
  vector<vector<int>> v1{{1, 0, 1}, {1, 1, 1}, {1, 1, 1}};

  rotate(v1);
  for (int i = 0; i < v1.size(); i++) {
    for (int j = 0; j < v1[i].size(); j++) {
      cout << v1[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
