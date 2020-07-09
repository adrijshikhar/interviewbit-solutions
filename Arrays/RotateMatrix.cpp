#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>> &A)
{
  vector<vector<int>> B = A;
  int n = A.size();
  for (int i = 0; i < B.size(); i++)
  {
    for (int j = 0; j < B[i].size(); j++)
    {
      B[j][n - 1 - i] = A[i][j];
    }
  }
  A = B;
}

int main()
{
  vector<vector<int>> v1{{
                             1,
                             2,
                         },
                         {
                             4,
                             5,
                         }};

  rotate(v1);
  for (int i = 0; i < v1.size(); i++)
  {
    for (int j = 0; j < v1[i].size(); j++)
    {
      cout << v1[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
