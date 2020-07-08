#include <bits/stdc++.h>
#define mod 1000003;

using namespace std;

long long int fact(long long int A)
{
  return A <= 1 ? 1 : (A * (fact(A - 1))) % mod;
}

int fR(string str, int low, int high)
{
  int c = 0;

  for (int i = low + 1; i < high; i++)
  {
    if (str[i] < str[low])
    {
      c++;
    }
  }
  return c;
}

int findRank(string A)
{
  long long int result = 1, n = A.size();
  int c = 0;
  for (int i = 0; i < n; ++i)
  {
    c = fR(A, i, n);
    result = (result + (c * fact(n - 1 - i))) % mod;
  }

  return result;
}

int main()
{
  string v1 = "DTNGJPURFHYEW";
  int v2 = findRank(v1);
  cout << v2 << " ";
  return 0;
}
