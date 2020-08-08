#include <bits/stdc++.h>
using namespace std;

int median(vector<int> &A, vector<int> &B) {

  if (A.size() > B.size()) {
    vector<int> t = A;
    A = B;
    B = t;
  }

  int a = A.size(), b = B.size();
  int s = (a + b + 1) / 2;
  int px, py, start = 0, end = a - 1, maxlx, minry, maxly, minrx;
  int ans;
  while (start <= end) {
    px = start + (end - start) / 2;
    py = s - px;
    maxlx = A[px - 1];
    minrx = A[px];
    maxly = B[py - 1];
    minry = B[py];
    if (maxlx <= minry && maxly <= minrx)
      break;
    else if (maxlx > minry)
      end = px;
    else
      start = px + 1;
  }
  if ((a + b) % 2 == 0)
    ans = (max(maxlx, maxly) + min(minrx, minry)) / 2;
  else
    ans = max(maxlx, maxly);

  return ans;
}

int main() {
  vector<int> A{1, 3}, B{2};
  int v2 = median(A, B);

  cout << v2 << " ";

  return 0;
}
