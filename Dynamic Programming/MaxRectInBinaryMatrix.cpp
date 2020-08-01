#include <bits/stdc++.h>
#define ll long long
using namespace std;

int minSum(vector<vector<int>> A)
{
  int n = A.size();
  int m = A[0].size();
  int ans = INT_MIN;

  for (int i = 0; i < m; i++)
  {
    vector<int> temp(n, 0);
    for (int j = i; j < m; j++)
    {
      for (int k = 0; k < n; k++)
      {
        temp[k] += A[k][j];
      }

      int ctr = 0;
      for (int k = 0; k < n; k++)
      {
        if (temp[k] == j - i + 1)
        {
          ctr += temp[k];
        }
        else
        {
          ans = max(ans, ctr);
          ctr = 0;
        }
      }
      ans = max(ans, ctr);
    }
  }
  return ans;
}

int main()
{
  vector<vector<int>> v{{1, 1, 1}, {0, 1, 1}, {1, 0, 0}};

  int v2 = minSum(v);

  cout << v2 << " ";

  return 0;
}
