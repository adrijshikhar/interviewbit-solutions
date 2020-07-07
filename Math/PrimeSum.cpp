#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> primeSum(int A)
{
  vector<int> B;
  int flag1 = 0, flag2 = 0;
  if (A == 4)
  {
    B.push_back(2);
    B.push_back(2);
    return B;
  }
  for (int i = 3; i <= A; i += 2)
  {
    flag1 = 0;
    flag2 = 0;
    for (auto j = 2; j <= i / 2; j++)
    {
      if (i % j == 0 || (A - i) % j == 0)
      {
        flag1 = 1;
        break;
      }
    }
    for (auto j = 2; j <= (A - i) / 2; j++)
    {
      if ((A - i) % j == 0)
      {
        flag2 = 1;
        break;
      }
    }
    if (flag1 == 0 && flag2 == 0)
    {
      B.push_back(i);
      B.push_back(A - i);
      break;
    }
  }

  return B;
}

int main()
{
  int v1 = 16777214;
  vector<int> v2 = primeSum(v1);
  for (auto i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << " ";
  }
  return 0;
}
