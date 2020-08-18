#include <bits/stdc++.h>
using namespace std;

int subsetSum(vector<int> &A, int B) {
  vector<int> t(B + 1, 0);
  t[0] = 1;
  for (auto num : A) {
    for (int i = B; i > 0; i--) {
      if (num <= i) {
        t[i] = t[i] || t[i - num];
      }
    }
  }
  return t[B];
}

int main() {
  vector<int> v1{
      3, 34, 4, 12, 5, 2,
  };
  int k = 9;
  int v2 = subsetSum(v1, k);

  cout << v2 << " ";

  return 0;
}
