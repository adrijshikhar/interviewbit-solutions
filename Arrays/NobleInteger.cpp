#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int nobleInteger(vector<int> &A)
{
  sort(A.begin(), A.end());
  if (!A[A.size() - 1])
  {
    return 1;
  }
  for (int i = 0; i < A.size(); i++)
  {
    if (A[i] == A[i + 1])
    {
      continue;
    }

    if (A[i] == A.size() - i - 1)
    {
      return 1;
    }
  }
  return -1;
}

int main()
{
  vector<int> v1{0};
  int v2 = nobleInteger(v1);
  cout << v2;

  return 0;
}
