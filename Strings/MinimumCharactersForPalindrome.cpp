#include <bits/stdc++.h>

using namespace std;

int minChar(string A)
{
  int ans = 0, s = A.size(), low = 0, i;
  for (i = s - 1; i >= 0; i--)
  {

    if (A[low] == A[i])
    {
      if (low == i)
      {
        return s - 1 - (2 * i);
      }
      if ((i - low) == 1)
      {
        return s - (2 * i);
      }

      low++;
    }
    else
    {
      low = 0;
      if (A[low] == A[i])
      {
        low++;
      }
    }
  }
  return ans;
}

int main()
{
  string v1 = "babb";
  int v2 = minChar(v1);
  cout << v2;

  return 0;
}
