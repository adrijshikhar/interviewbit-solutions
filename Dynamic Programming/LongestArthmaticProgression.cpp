#include <bits/stdc++.h>
using namespace std;

int lap(vector<int> &A)
{
  unordered_map<int, int> cd;
  int n = A.size();
  if (n <= 2)
    return n;

  for (int i = 1; i < n; i++)
  {
    unordered_map<int, int> temp;
    for (int j = i - 1; j >= 0; j--)
    {
      if (temp[A[i] - A[j]] <= 0)
        cd[A[i] - A[j]]++;
      temp[A[i] - A[j]]++;
    }
  }

  int mx = 0;
  for (auto it = cd.begin(); it != cd.end(); ++it)
    mx = max(mx, it->second);
  return mx + 1;
}

int main()
{
  vector<int> v1{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
  int v2 = lap(v1);
  cout << v2;
  return 0;
}
