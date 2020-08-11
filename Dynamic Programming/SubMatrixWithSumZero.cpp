#include <bits/stdc++.h>
#define ll long long
using namespace std;

int fn(vector<int> &arr) {
  int n = arr.size();
  unordered_map<int, int> prevSum;
  int res = 0;
  int currsum = 0;
  for (int i = 0; i < n; i++) {
    currsum += arr[i];
    if (currsum == 0)
      res++;
    if (prevSum.find(currsum) != prevSum.end())
      res += (prevSum[currsum]);
    prevSum[currsum]++;
  }
  return res;
}

int minSum(vector<vector<int>> A) {
  if (A.size() == 0)
    return 0;
  int m = A.size(), n = A[0].size();
  int ans = 0;
  for (int i = 0; i < m; i++) {
    vector<int> t(n, 0);
    for (int j = i; j < m; j++) {
      for (int k = 0; k < n; k++) {
        t[k] += A[j][k];
      }
      ans += fn(t);
    }
  }
  return ans;
}

int main() {
  vector<vector<int>> v{
      {-8, 5, 7},
      {3, 7, -8},
      {5, -8, 9},
  };

  int v2 = minSum(v);

  cout << v2 << " ";

  return 0;
}
