#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int> &A, int B)
{
  int i = 0, j = 0, s = A.size();
  if (s == 0)
  {
    return s;
  }
  for (int i = 0; i < s ; i++)
  {
    if (A[i] != B)
    {
      A[j++] = A[i];
    }
  }
  return j;
}

int main()
{
  vector<int> v1{
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
  int v3 = removeElement(v1, 1);
  cout << v3 << endl;
  for (int i = 0; i < v3; i++)
  {
    cout << v1[i] << " ";
  }

  return 0;
}
