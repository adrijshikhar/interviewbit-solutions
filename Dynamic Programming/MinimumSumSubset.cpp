#include <bits/stdc++.h>
using namespace std;

int minSumSubset(vector<int> &A) {
  int n = A.size();
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += A[i];

  bool t[n + 1][sum + 1];
  for (int i = 0; i < sum + 1; i++)
    t[0][i] = 0;
  for (int i = 1; i < n + 1; i++)
    t[i][0] = 1;

  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < sum + 1; j++) {
      if (A[i - 1] <= j)
        t[i][j] = (t[i - 1][j - A[i - 1]] || t[i - 1][j]);
      else
        t[i][j] = t[i - 1][j];
    }

  vector<int> temp;
  int ans = INT_MAX;
  for (int i = 0; i <= (sum / 2); i++) {
    if (t[n][i] == true)
      ans = min(ans, sum - (2 * i));
  }

  return ans;
}

int main() {
  vector<int> v1{
      68, 35, 1,   70, 25, 79, 59, 63, 65, 6,  46, 82, 28, 62, 92, 96, 43,
      28, 37, 92,  5,  3,  54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70,
      13, 68, 100, 36, 95, 4,  12, 23, 34, 74, 65, 42, 12, 54, 69, 48, 45,
  };
  int v2 = minSumSubset(v1);

  cout << v2 << " ";

  return 0;
}
