#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> prettyPrint(int A)
{
  int n = (2 * A) - 1, m, k;
  vector<vector<int>> B(n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      m = abs((n - 1) / 2 - j) + 1;
      k = abs((n - 1) / 2 - i) + 1;
      if (j < k || j > n - 1 - k)
      {
        B[i].push_back(m);
      }
      else
      {
        B[i].push_back(abs(A - i));
      }
    }
  }

  return B;
}

int main()
{
  int A = 4;
  vector<vector<int>> v2 = prettyPrint(A);

  for (int i = 0; i < v2.size(); i++)
  {
    for (int j = 0; j < v2[i].size(); j++)
    {
      cout << v2[i][j] << ' ';
    }
    cout << endl;
  }

  // cout << v2[0][0] << " ";

  return 0;
}
