#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

int color3xN(int A) {
  if (A == 0)
    return 0;
  int dpu[A + 1], dps[A + 1];
  dpu[1] = 24;
  dps[1] = 12;
  for (int i = 2; i <= A; i++) {
    dpu[i] =
        ((long long)dpu[i - 1] * 11 + (long long)dps[i - 1] * 10) % 1000000007;
    dps[i] =
        ((long long)dpu[i - 1] * 5 + (long long)dps[i - 1] * 7) % 1000000007;
  }
  return ((long long)dpu[A] + dps[A]) % 1000000007;
}

int main() {

  ll v2 = color3xN(2);

  cout << v2 << " ";

  return 0;
}
