#include <bits/stdc++.h>
using namespace std;
int maxp3(vector<int> &A)
{

  sort(A.begin(), A.end());
  int n = A.size();
  int p = A[n - 3] * A[n - 2] * A[n - 1];
  int ne = A[0] * A[1] * A[n - 1];
  return max(p, ne);
}

int main()
{
  vector<int> v1{1, 1, 0, 0, 1, 1, 0, 0, 1};
  int v2 = maxp3(v1);
  cout << v2;
  return 0;
}
