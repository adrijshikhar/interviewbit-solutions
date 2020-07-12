#include <bits/stdc++.h>

using namespace std;

int diffPossible(vector<int> &A, int B)
{
  int i = 0, j = 0;
  while (i < A.size() && j < A.size())
  {
    if ((A[j] - A[i]) == B && i != j)
    {
      return 1;
    }
    else if (A[j] - A[i] <= B)
    {
      j++;
    }
    else if (A[j] - A[i] > B)
    {
      i++;
    }
  }

  return 0;
}

int main()
{
  vector<int> v1{
      1, 3, 5};
  int v2 = 3;
  int v3 = diffPossible(v1, v2);
  cout << v3;

  return 0;
}
