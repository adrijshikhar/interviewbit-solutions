#include <bits/stdc++.h>
using namespace std;
int canJump(vector<int> &A)
{
  int ind = 0;
  for (int i = A.size() - 1; i >= 0; i--)
  {
    if (A[i] + i >= ind)
      ind = i;
  }
  return ind == 0;
}

int main()
{
  vector<int> v1{2, 1, 2};
  int v2 = canJump(v1);
  cout << v2;
  return 0;
}
