#include <bits/stdc++.h>

using namespace std;

vector<int> intersect(const vector<int> &A, const vector<int> &B)
{
  vector<int> C;
  int i = 0, sa = A.size(), j = 0, sb = B.size();
  while (i < sa && j < sb)
  {
    if (A[i] == B[j])
    {
      C.push_back(A[i]);
      i++;
      j++;
    }
    else if (B[j] < A[i])
    {
      j++;
    }
    else if (A[i] < B[j])
    {
      i++;
    }
  }

  return C;
}

int main()
{
  vector<int> v1{1, 3, 8, 10, 13, 13, 16, 16, 16, 18, 21, 23, 24, 31, 31, 31, 33, 35, 35, 37, 37, 38, 40, 41, 43, 47, 47, 48, 48, 52, 52, 53, 53, 55, 56, 60, 60, 61, 61, 63, 63, 64, 66, 67, 67, 68, 69, 71, 80, 80, 80, 80, 80, 80, 81, 85, 87, 87, 88, 89, 90, 94, 95, 97, 98, 98, 100, 101};
  vector<int> v2{5, 7, 14, 14, 25, 28, 28, 34, 35, 38, 38, 39, 46, 53, 65, 67, 69, 70, 78, 82, 94, 94, 98};
  vector<int> v3 = intersect(v1, v2);
  for (int i = 0; i < v3.size(); i++)
  {
    cout << v3[i] << " ";
  }

  return 0;
}
