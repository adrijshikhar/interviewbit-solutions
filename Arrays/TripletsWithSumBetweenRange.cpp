#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int tripletSum(vector<string> &A)
{
  int n = A.size(), i;
  vector<float> B;
  for (i = 0; i < n; i++)
  {
    B.push_back(stof(A[i]));
  }
  float a = B[0], b = B[1], c = B[2];
  for (i = 3; i < n; i++)
  {
    if (a + b + c < 2 && a + b + c > 1)
      return 1;
    else if (a + b + c > 2)
    {
      if (a > b && a > c)
        a = B[i];
      else if (b > a && b > c)
        b = B[i];
      else
        c = B[i];
    }
    else
    {
      if (a < b && a < c)
        a = B[i];
      else if (b < a && b < c)
        b = B[i];
      else
        c = B[i];
    }
  }
  if (a + b + c > 1 && a + b + c < 2)
    return 1;
  else
    return 0;
}

int main()
{
  vector<string> v1{"0.8", "0.2", "0.3"};
  int v2 = tripletSum(v1);
  cout << v2;

  return 0;
}
