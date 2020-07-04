#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int A, int B)
{
  if (A < B)
    swap(A, B);

  if (B == 0)
    return A;

  return gcd(A % B, B);
}

int main()
{
  int A = 9, B = 10;
  int v2 = gcd(A, B);

  cout << v2;

  return 0;
}
