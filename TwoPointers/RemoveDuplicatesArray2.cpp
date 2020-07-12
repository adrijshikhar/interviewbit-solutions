#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &A)
{
  int i = 0, j = 0, s = A.size();
  if (s == 0 || s == 1)
  {
    return s;
  }
  for (int i = 0; i < s - 2; i++)
  {
    if (A[i] != A[i + 2])
    {
      A[j++] = A[i];
    }
  }
  A[j++] = A[s - 2];

  A[j++] = A[s - 1];
  return j;
}

int main()
{
  vector<int> v1{
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
  int v3 = removeDuplicates(v1);
  cout << v3 << endl;
  for (int i = 0; i < v3; i++)
  {
    cout << v1[i] << " ";
  }

  return 0;
}
