#include <bits/stdc++.h>

using namespace std;

int numRange(vector<int> &A, int B, int C)
{
  int ans = 0, j = 0, s = 0;
  for (int i = 0; i < A.size(); i++)
  {
    s = 0;
    j = i;
    while (j < A.size())
    {
      s += A[j];
      j++;
      if (B <= s && s <= C)
      {
        ans += 1;
      }
      if (C < s)
      {
        break;
      }
    }
  }

  return ans;
}

int main()
{
  vector<int> v1{10, 5, 1, 0, 2};
  int v2 = numRange(v1, 6, 8);
  cout << v2;

  return 0;
}
