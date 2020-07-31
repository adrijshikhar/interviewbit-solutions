
#include <bits/stdc++.h>
using namespace std;
int bulbs(vector<int> &A)
{
  int flips = 0, val;

  for (int i = 0; i < A.size(); i++)
  {
    val = flips % 2;
    if (A[i] == val)
    {
      flips++;
    }
  }

  return flips;
}

int main()
{
  vector<int> v1{1, 1, 0, 0, 1, 1, 0, 0, 1};
  int v2 = bulbs(v1);
  cout << v2;
  return 0;
}
