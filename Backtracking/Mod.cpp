#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int Mod(int A, int B, int C)
{
  if (A == 0)
    return 0;
  if (B == 0)
    return 1;

  long long int y;
  if (B % 2 == 0)
  {
    y = Mod(A, B / 2, C);
    y = (y * y) % C;
  }

  else
  {
    y = A % C;
    y = (y * Mod(A, B - 1, C) % C) % C;
  }

  return (int)((y + C) % C);
}

int main()
{
  int A = 71045970, B = 41535484, C = 64735492;
  long long int v2 = Mod(A, B, C);
  cout << v2 << " ";
  return 0;
}
