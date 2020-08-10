#include <bits/stdc++.h>
using namespace std;

int maxone(vector<int> &A, int B) {
  int ans = 0, left = 0, right = 0, n = A.size(), c = B;

  while (right < n) {
    if (A[right] == 0)
      c--;
    if (c < 0) {
      while (c < 0) {
        if (A[left] == 0) {
          c++;
        }
        left++;
      }
    }

    ans = max(ans, right - left + 1);
    right++;
  }

  return ans;
}

int main() {
  vector<int> v1{
      1, 0, 0, 1, 1, 1, 1,
  };
  int m = 1;

  int v2 = maxone(v1, m);
  cout << v2 << " ";

  return 0;
}
