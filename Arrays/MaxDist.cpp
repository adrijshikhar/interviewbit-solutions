#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int maximumGap(const vector<int> &A)
{
  if (A.size() == 1)
    return 0;
  if (A.size() == 0)
    return -1;
  int lr[A.size()];
  int rr[A.size()];
  lr[0] = A[0];
  rr[A.size() - 1] = A[A.size() - 1];
  int maxa = A[A.size() - 1], mini = A[0];
  for (int i = 1; i < A.size(); i++)
  {
    lr[i] = min(A[i], mini);
    mini = lr[i];
  }
  for (int i = A.size() - 2; i >= 0; i--)
  {
    rr[i] = max(A[i], maxa);
    maxa = rr[i];
  }

  int i = 0, j = 0, res = -1;
  while (i < A.size() && j < A.size())
  {
    if (lr[i] <= rr[j])
    {
      res = max(res, j - i);
      j++;
    }
    else
      i++;
  }
  return res;
}

int main()
{
  vector<int> A{3, 4, 1, 4, 1};

  int v2 = maximumGap(A);

  cout << v2 << " ";
  return 0;
}
