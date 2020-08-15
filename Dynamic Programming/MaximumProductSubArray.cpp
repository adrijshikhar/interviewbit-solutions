#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &A) {
  int n = A.size();
  int dp1[n]; // to maintain max product uptil n
  int dp2[n]; // to maintain min product uptil n
  dp1[0] = A[0];
  dp2[0] = A[0];
  for (int i = 1; i < n; i++) {
    dp1[i] = max(A[i], max(A[i] * dp1[i - 1], A[i] * dp2[i - 1]));
    dp2[i] = min(A[i], min(A[i] * dp1[i - 1], A[i] * dp2[i - 1]));
  }
  int ans = INT_MIN;
  for (int i = 0; i < n; i++) {
    cout << dp1[i] << " " << dp2[i] << endl;
    ans = max(ans, dp1[i]);
  }
  return ans;
}

int main() {

  vector<int> v1{
      2,
      3,
      -2,
      4,
  };
  int v2 = maxProduct(v1);
  cout << v2 << " ";

  return 0;
}
