#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &A, vector<int> &B)
{
  int i = A.size() - 1, j = B.size() - 1;

  int lastPos = A.size() + B.size() - 1;

  A.resize(A.size() + B.size());

  while (j >= 0)
  {
    if (i >= 0 && A[i] > B[j])
      A[lastPos--] = A[i--];
    else
      A[lastPos--] = B[j--];
  }
}

int main()
{
  vector<int> v1{1, 5, 8};
  vector<int> v2{1, 2, 3};
  merge(v1, v2);
  for (int i = 0; i < v1.size(); i++)
  {
    cout << v1[i] << " ";
  }

  return 0;
}
