#include <bits/stdc++.h>
using namespace std;
int majorityElement(const vector<int> &A)
{
  int maj_index = 0, c = 1, n = A.size();
  for (int i = 1; i < n; i++)
  {
    if (A[maj_index] == A[i])
      c++;
    else
      c--;
    if (c == 0)
    {
      maj_index = i;
      c = 1;
    }
  }

  return A[maj_index];
}

int main()
{
  vector<int> v1{2, 1, 2};
  int v2 = majorityElement(v1);
  cout << v2;
  return 0;
}
