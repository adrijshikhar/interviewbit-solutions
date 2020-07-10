#include <bits/stdc++.h>

using namespace std;

int pow(int x, int n, int d)
{
  int ans = 0, parsedPow = n % 4, multipliedVal = 1;
  if (parsedPow == 0)
  {
    parsedPow = 4;
  }

  for (int i = 1; i <= parsedPow; i++)
  {
    multipliedVal = multipliedVal * x;
  }

  return ans;
}

int main()
{
  int x = 2, n = 3, d = 3;
  int v2 = pow(x, n, d);
  cout << v2;

  return 0;
}
