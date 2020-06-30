#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int isPrime(int A)
{
  if (A == 1)
  {
    return 0;
  }
  for (int i = 2; i <= sqrt(A); i++)
  {
    if (A % i == 0)
    {
      return 0;
    }
  }
  return 1;
}

int main()
{
  int v1 = 1;
  int v2 = isPrime(v1);
  cout << v2;
  return 0;
}
