#include <bits/stdc++.h>
#define ll long long
using namespace std;

string convertToTitle(int A)
{
  int d;
  string str;

  while (A)
  {
    d = A % 26;

    if (d == 0)
    {
      str += 'Z';
      A = (A / 26) - 1;
    }
    else
    {
      str += 'A' + (d - 1);
      A = A / 26;
    }
  }
  reverse(str.begin(), str.end());
  return str;
}
int main()
{
  int v1 = 702;
  string v2 = convertToTitle(v1);
  cout << v2 << " ";
  return 0;
}
