#include <bits/stdc++.h>

using namespace std;

void sortColors(vector<int> &A)
{
  int i = 0, j = 0, s = A.size(), n = A.size() - 1;
  vector<int> B(A.size(), 1);

  for (int i = 0; i < s; i++)
  {
    if (A[i] == 0)
    {
      B[j++] = A[i];
    }
    else if (A[i] == 2)
    {
      B[n--] = A[i];
    }
  }
  A = B;
}

int main()
{
  vector<int> v1{
      0, 0, 0, 1, 2, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 0, 0, 1, 1, 0, 2, 0};
  sortColors(v1);

  for (int i = 0; i < v1.size(); i++)
  {
    cout << v1[i] << " ";
  }

  return 0;
}
