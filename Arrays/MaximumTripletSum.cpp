#include <bits/stdc++.h>
using namespace std;

int getLowValue(set<int> &lowValue, int &n) {
  auto it = lowValue.lower_bound(n);
  --it;
  return (*it);
}
int maximumGap(vector<int> &A) {
  set<int> s;
  s.insert(INT_MIN);
  int n = A.size(), ma = 0;
  int m[n];
  m[n - 1] = A[n - 1];
  for (int i = n - 2; i >= 0; i--)
    m[i] = max(A[i], m[i + 1]);

  for (int i = 0; i < n - 1; i++) {
    if (A[i] < m[i + 1]) {
      ma = max(ma, A[i] + m[i + 1] + getLowValue(s, A[i]));

      s.insert(A[i]);
    }
  }

  return ma;
}

int main() {
  vector<int> v1{2, 5, 3, 1, 4, 9};
  int v2 = maximumGap(v1);
  cout << v2;
  return 0;
}
