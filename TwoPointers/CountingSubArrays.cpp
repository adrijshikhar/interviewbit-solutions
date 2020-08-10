#include <bits/stdc++.h>

using namespace std;

int numSumArrays(vector<int> &A, int B) {
  int s = 0, e = 0, ans = 0;
  int n = A.size();
  int sum = A[0];

  while (s < n && e < n) {
    if (sum < B) {
      e++;
      ans += max(0, e - s);
      sum += A[e];
    }
    if (sum >= B) {
      sum -= A[s];
      s++;
    }
  }
  return ans;
}

int main() {
  vector<int> v1{
      1, 11, 2, 3, 15,
  };
  int v2 = 10;
  int v3 = numSumArrays(v1, v2);
  cout << v3;

  return 0;
}
