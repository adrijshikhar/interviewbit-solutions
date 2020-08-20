#include <bits/stdc++.h>
using namespace std;
#define ll long long

int spi(vector<int> &A) {
  int sp = 0, curr = 0, n = A.size(), f = 0;
  while (curr < n) {

    if (A[sp] < A[curr] && f) {
      sp = curr;
      f = 0;
    }
    if (A[curr] < A[sp])
      f = 1;
    curr++;
  }

  return sp;
}

int main() {
  vector<int> v1{5, 1, 4, 3, 6, 8, 10, 7, 9};
  int v2 = spi(v1);
  cout << v2 << endl;

  return 0;
}
