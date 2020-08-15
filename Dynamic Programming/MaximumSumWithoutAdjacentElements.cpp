#include <bits/stdc++.h>
using namespace std;

int myMax(int a, int b, int c, int d, int e) {

  return max(a, max(b, max(c, max(d, e))));
}

int adjacent(vector<vector<int>> &A) {
  int n = A[0].size();
  for (int i = 0; i < n; i++)
    A[0][i] = max(A[0][i], A[1][i]);

  A[0][1] = max(A[0][0], A[0][1]);

  for (int i = 2; i < n; i++)
    A[0][i] = max(A[0][i - 1], A[0][i - 2] + A[0][i]);

  return max(A[0][n - 1], A[0][n - 2]);
}

int main() {
  vector<vector<int>> v1{{16, 5, 54, 55, 36, 82, 61, 77, 66, 61},
                         {31, 30, 36, 70, 9, 37, 1, 11, 68, 14}};
  int v2 = adjacent(v1);

  cout << v2 << " ";
  return 0;
}
