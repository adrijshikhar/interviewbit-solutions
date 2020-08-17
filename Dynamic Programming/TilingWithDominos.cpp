#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

int tilingWithDominos(int A) {
  if (A % 2)
    return 0;
  vector<long long int> a(A + 1, 0), c(A + 1, 0);
  a[1] = 1, c[1] = 0, a[2] = 0, c[2] = 3;

  for (int i = 3; i <= A; i++) {
    c[i] = (2 * a[i - 1] + c[i - 2]) % mod;
    a[i] = (c[i - 1] + a[i - 2]) % mod;
  }
  return c[A];
}

int main() {

  ll v2 = tilingWithDominos(3);

  cout << v2 << " ";

  return 0;
}
