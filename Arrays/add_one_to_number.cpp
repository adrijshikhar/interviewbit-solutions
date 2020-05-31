#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &A)
{
  vector<int> B;

  int i = 0;

  int inc = A[A.size() - 1] + 1;

  for (int j = A.size() - 1; j >= 0; j--)
  {
    if (inc > 9)
    {
      A[j] = 0;
      if (j == 0)
      {
        B.push_back(1);
        for (int k = 0; k < A.size(); k++)
        {
          B.push_back(0);
        }
        return B;
      }
      inc = A[j - 1] + 1;
      A[j - 1] = inc;
    }
    else
    {
      A[j] = inc;
      break;
    }
  }

  for (i = 0; i < A.size(); i++)
  {
    if (A[i] != 0)
    {
      break;
    }
  }

  for (; i < A.size(); i++)
  {
    B.push_back(A[i]);
  }

  return B;
}

int main()
{
  vector<int> v1{
      9,
  };
  vector<int> v2 = plusOne(v1);

  for (auto i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << " ";
  }

  return 0;
}
