#include <bits/stdc++.h>

using namespace std;

int josephusIndex(int A, int k) {
  if (A == 0)
    return 0;

  return (josephusIndex(A - 1, k) + k) % A;
}

int main() {
  int v1 = 7, k = 3;
  int v2 = josephusIndex(v1, k);
  cout << v2;
  return 0;
}
