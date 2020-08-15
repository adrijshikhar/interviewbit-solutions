#include <bits/stdc++.h>
using namespace std;

int lis(const vector<int> &A) {
  int total = 0, sz = A.size();
  for (int i = 0; i < sz - 1; i++) {
    if (A[i + 1] > A[i])
      total += A[i + 1] - A[i];
  }
  return total;
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
