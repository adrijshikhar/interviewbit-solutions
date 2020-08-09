#include <bits/stdc++.h>
using namespace std;

int lis(const vector<int> &A) {
  int n = A.size(), ans = 0;
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  vector<int> lis(n, 1);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++)
      if (A[i] > A[j] && lis[i] < lis[j] + 1)
        lis[i] = lis[j] + 1;
    ans = max(ans, lis[i]);
  }
  return ans;
}

int main() {
  vector<int> v1{
      14, 24, 18, 46, 55, 53,  82, 18, 101, 20, 78,
      35, 68, 9,  16, 93, 101, 85, 81, 28,  78,
  };
  int v2 = lis(v1);

  cout << v2 << " ";

  return 0;
}
