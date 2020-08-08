#include <bits/stdc++.h>
using namespace std;

double median(vector<int> &A, vector<int> &B) {

  if (A.size() > B.size()) {
    vector<int> t = A;
    A = B;
    B = t;
  }

  int a = A.size(), b = B.size();
  int s = (a + b + 1) / 2;
  int px, py, start = 0, end = a, maxlx, minry, maxly, minrx;
  double ans;
  while (start <= end) {
    px = start + (end - start) / 2;
    py = s - px;

    maxlx = px == 0 ? INT_MIN : A[px - 1];
    minrx = px == a ? INT_MAX : A[px];

    maxly = py == 0 ? INT_MIN : B[py - 1];
    minry = py == b ? INT_MAX : B[py];

    if (maxlx <= minry && maxly <= minrx)
      break;
    else if (maxlx > minry)
      end = px - 1;
    else
      start = px + 1;
  }

  if ((a + b) % 2 == 0)
    ans = (max(maxlx, maxly) + min(minrx, minry)) / 2.0;
  else
    ans = max(maxlx, maxly);

  return ans;
}

int main() {
  vector<int> A{1, 2}, B{3, 4};
  double v2 = median(A, B);

  cout << v2 << " ";

  return 0;
}
