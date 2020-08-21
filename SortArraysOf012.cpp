#include <bits/stdc++.h>

using namespace std;

vector<int> sort(vector<int> &A) {
  int n = A.size();
  int lo = 0;
  int hi = n - 1;
  int mid = 0;

  while (mid <= hi) {
    switch (A[mid]) {

    case 0:
      swap(A[lo++], A[mid++]);
      break;

    case 1:
      mid++;
      break;

    case 2:
      swap(A[mid], A[hi--]);
      break;
    }
  }

  return A;
}

int main() {
  vector<int> m = {
      0, 2, 1, 2, 0,
  };

  vector<int> v = sort(m);
  for (int i = 0; i < m.size(); i++) {
    cout << v[i] << " ";
  }

  return 0;
}
