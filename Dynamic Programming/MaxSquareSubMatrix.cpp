#include <bits/stdc++.h>
#define ll long long
using namespace std;

int minSum(vector<vector<int>> A) {
  int r = A.size();
  int c = A[0].size();
  int ans = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (i < 1 || j < 1) { 
        ans = max(ans, 1);
      } else {
        if (A[i][j] == 1) {
          A[i][j] = 1 + min(A[i - 1][j], min(A[i - 1][j - 1], A[i][j - 1]));
          ans = max(A[i][j], ans);
        }
      }
    }
  }
  ans *= ans;
  return ans;
}

int main() {
  vector<vector<int>> v{{1, 1, 1}, {0, 1, 1}, {1, 0, 0}};

  int v2 = minSum(v);

  cout << v2 << " ";

  return 0;
}
