#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int trailingZeroes(int A)
{
  int res = 0;
  while (A)
  {
    A = A / 5;
    res += A;
  }
  return res;
}

int main()
{
  int A = 25;
  int v2 = trailingZeroes(A);

  cout << v2;

  return 0;
}
