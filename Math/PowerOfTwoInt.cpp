#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int isPower(int A)
{
  int flag2 = 0;
  if (A == 1)
  {
    return 1;
  }
  for (long long i = 2; i <= sqrt(A); i++)
  {
    int B = A;
    flag2 = 0;
    while (B > 1 && flag2 != 1)
    {
      if (B % i == 0)
      {
        B = B / i;
      }
      else
      {
        flag2 = 1;
      }
    }
    if (flag2 == 0)
    {
      return 1;
    }
  }
  return 0;
}

int main()
{
  int v1 = 16808;
  int v2 = isPower(v1);
  cout << v2;

  return 0;
}
