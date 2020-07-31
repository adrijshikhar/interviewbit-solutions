#include <bits/stdc++.h>
using namespace std;
int mice(vector<int> &A, vector<int> &B)
{
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int maxx = INT_MIN;
  for (int i = 0; i < A.size(); i++)
    maxx = max(maxx, abs(A[i] - B[i]));
  return maxx;
}

int main()
{
  vector<int> v1{4, -4, 2};
  vector<int> v3{4, 0, 5};
  int v2 = mice(v1, v3);
  cout << v2;
  return 0;
}
