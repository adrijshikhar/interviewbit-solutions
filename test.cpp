#include <bits/stdc++.h>

using namespace std;

int main()
{
  int x = 30;
  for (int i = 0; i < 30; i++)
  {
    if ((x & 1 << i) != 0)
    {
      cout << i << " ";
    }
  }

  return 0;
}
