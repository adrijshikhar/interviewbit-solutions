#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int findMin(int A)
{
  if (A == 0 || A == 1)
  {
    return A;
  }

  long int start = 1, end = A / 2, ans;
  while (start <= end)
  {
    long int mid = (start + end) / 2;

    if (mid * mid == A)
    {
      return mid;
    }
    if (mid * mid < A)
    {
      start = mid + 1;
      ans = mid;
    }
    else
    {
      end = mid - 1;
    }
  }
  return ans;
}

int main()
{
  int v1 = 20;
  int v2 = findMin(v1);
  cout << v2;

  return 0;
}
