#include <bits/stdc++.h>

using namespace std;

int strStr(const string A, const string B)
{
  int sa = A.size(), sb = B.size(), l = 0;

  if (sa < sb || sb == 0 || sa == 0)
  {
    return -1;
  }
  for (int i = 0; i < sa; i++)
  {
    if (A[i] == B[0])
    {
      for (int j = 0; j < sb; j++)
      {
        if (A[j + i] == B[j])
        {
          l++;
        }
      }
      if (l == sb)
      {
        return i;
      }
      l = 0;
    }
  }

  return -1;
}

int main()
{
  string v1 = "bbbbbbbbab";
  string v3 = "baba";
  int v2 = strStr(v1, v3);
  cout << v2;

  return 0;
}
