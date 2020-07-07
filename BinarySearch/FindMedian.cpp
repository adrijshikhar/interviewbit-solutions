#include <bits/stdc++.h>

using namespace std;

int findMedian(vector<vector<int>> &A)
{
  int min = INT_MAX, max = INT_MIN;
  int r = A.size(), c = A[0].size();

  for (auto i = 0; i < A.size(); i++)
  {
    if (A[i][0] < min)
    {
      min = A[i][0];
    }
    if (A[i][c - 1] > max)
    {
      max = A[i][c - 1];
    }
  }

  int d = (r * c + 1) / 2;
  while (min < max)
  {
    int mid = min + (max - min) / 2;
    int count = 0;
    for (auto i = 0; i < A.size(); i++)
    {
      count += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
    }
    if (count < d)
    {
      min = mid + 1;
    }
    else
    {
      max = mid;
    }
  }
  return min;
}

int main()
{
  vector<vector<int>> v1{{1, 3, 5}, {
                                        2,
                                        6,
                                        9,
                                    },
                         {3, 6, 9}};

  int v2 = findMedian(v1);
  cout << v2;

  return 0;
}
