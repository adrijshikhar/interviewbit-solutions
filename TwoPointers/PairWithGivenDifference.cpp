#include <bits/stdc++.h>
using namespace std;

int maxone(vector<int> &A, int B) {
  sort(A.begin(), A.end());
  B = abs(B);
  int left = 0, right = 0, diff = 0, n = A.size();
  while (right < n) {
    diff = A[right] - A[left];
    if (B < diff) {
      while (left <= right) {
        diff += A[left];
        left++;
        diff -= A[left];
        if (diff < B)
          break;
      }
    } else if (diff == B && right !=left)
      return 1;
    right++;
  }

  return 0;
}

int main() {
  vector<int> v1{
      20,
      500,
      1000,
      200,
  };
  int m = 0;

  int v2 = maxone(v1, m);
  cout << v2 << " ";

  return 0;
}
