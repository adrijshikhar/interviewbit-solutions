#include <bits/stdc++.h>

using namespace std;

int charVal(char ch)
{
  switch (ch)
  {
  case 'M':
    return 1000;
  case 'D':
    return 500;
  case 'C':
    return 100;
  case 'L':
    return 50;
  case 'X':
    return 10;
  case 'V':
    return 5;
  case 'I':
    return 1;
  default:
    return -1;
  }
}

int romanToInt(string A)
{
  int ans = 0, s = A.size();

  for (int i = 0; i < s; i++)
  {
    int ch = charVal(A[i]);
    cout << ch << " ";
    if (i + 1 < s)
    {
      int chNext = charVal(A[i + 1]);
      if (ch >= chNext)
      {
        ans += ch;
      }
      else
      {
        ans += chNext - ch;
        i++;
      }
    }
    else
    {
      ans += ch;
    }
  }
  return ans;
}

int main()
{
  string v1 = "MDCCCIV";
  int v2 = romanToInt(v1);
  cout << v2;

  return 0;
}
