#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> prettyPrint(int A)
{
  int n = (2 * A) - 1, p, q;
  vector<vector<int>> B(n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      p = abs((n - 1) / 2 - j) + 1;
      q = abs((n - 1) / 2 - i) + 1;
      B[i].push_back(max(p, q));
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

  return 0;
}
