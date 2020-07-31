#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int meeting(vector<vector<int>> &A)
{
  vector<pair<int, int>> ans;

  for (int i = 0; i < A.size(); i++)
  {
    ans.push_back({A[i][0], 1});
    ans.push_back({A[i][1], 0});
  }

  sort(ans.begin(), ans.end());

  int curr = 0, max1 = 0;

  for (int i = 0; i < ans.size(); i++)
  {
    if (ans[i].second == 1)
    {
      curr++;
      max1 = max(max1, curr);
    }
    else
      curr--;
  }
  return max1;
}

int main()
{
  vector<vector<int>> v1{{1, 18}, {18, 23}, {15, 29}, {4, 15}, {2, 11}, {5, 13}};
  int v3 = meeting(v1);
  cout << v3;

  return 0;
}
