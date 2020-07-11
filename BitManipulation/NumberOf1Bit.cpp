#include <bits/stdc++.h>

using namespace std;

int numSetBits(unsigned int A)
{
  unsigned int count = 0;
  while (A)
  {
    A &= (A - 1);
    count++;
  }
  return count;
}

int main()
{
  int v1 = 21;
  int v2 = numSetBits(v1);
  cout << v2;

  return 0;
}
