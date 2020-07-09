#include <bits/stdc++.h>
#include <math.h>
using namespace std;

vector<int> subUnsort(vector<int> &A)
{
  int s = 0, e = A.size() - 1, i, max1, min1;
  vector<int> B;

  for (s = 0; s < A.size() - 1; s++)
  {
    if (A[s] > A[s + 1])
      break;
  }
  if (s == A.size() - 1)
  {
    B.push_back(-1);
    return B;
  }

  for (e = A.size() - 1; e > 0; e--)
  {
    if (A[e] < A[e - 1])
      break;
  }

  max1 = A[s];
  min1 = A[s];
  for (i = s + 1; i <= e; i++)
  {
    max1 = max(max1, A[i]);
    min1 = min(min1, A[i]);
  }

  for (i = 0; i < s; i++)
  {
    if (A[i] > min1)
    {
      s = i;
      break;
    }
  }

  for (i = A.size() - 1; i >= e + 1; i--)
  {
    if (A[i] < max1)
    {
      e = i;
      break;
    }
  }
  B.push_back(s);
  B.push_back(e);
  return B;
}

int main()
{
  vector<int> A{2, 1, 3, 4, 5};

  vector<int> v2 = subUnsort(A);
  for (int i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << ' ';
  }

  return 0;
}
