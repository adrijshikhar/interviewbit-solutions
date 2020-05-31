#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int plusOne(vector<int> &A)
{
  int sum = A[0];
  int max = A[0];

  for (int i = 0; i < A.size(); i++)
  {
    sum += A[i];
    if (sum > max)
    {
      max = sum;
    }
    if (sum < 0)
    {
      sum = 0;
    }
  }

  return max;
}

int main()
{
  vector<int> v1{
      -8, 2, 3, 7, 2, -12};
  int v2 = plusOne(v1);

  cout << v2;

  return 0;
}
