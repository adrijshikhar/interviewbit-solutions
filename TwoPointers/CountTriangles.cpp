#include <bits/stdc++.h>
#define mod 1000000007;
using namespace std;

int nTriang(vector<int> &A)
{
  sort(A.begin(), A.end());
  int n = A.size(), ans = 0, k = 0;

  for (int i = n - 1; i >= 1; i--)
  {
    int l = 0, r = i - 1;
    while (l < r)
    {
      if (A[l] + A[r] > A[i])
      {
        ans = (ans + r - l) % mod;
        r--;
      }
      else
      {
        l++;
      }
    }
  }
  return ans % mod;
}

int main()
{
  vector<int> v1{1, 1, 1, 2, 2};
  int v3 = nTriang(v1);
  cout << v3;

  return 0;
}
