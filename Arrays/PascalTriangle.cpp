#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solve(int A)
{
  int r = 1;
  vector<vector<int>> B(A, vector<int>(0));
  if (A == 0)
  {
    return B;
  }
  B[0].push_back(r);

  for (int i = 1; i < A; i++)
  {
    r = 1;
    for (int j = 0; j <= i; j++)
    {
      B[i].push_back(r);
      r = r * (i - j) / (j + 1);
    }
  }

  return B;
}

int main()
{
  int v1 = 0;
  vector<vector<int>> v2 = solve(v1);
  for (auto i = 0; i < v2.size(); i++)
  {
    for (auto j = 0; j < v2[i].size(); j++)
    {
      cout << v2[i][j] << " ";
    }

    cout << endl;
  }
  return 0;
}
