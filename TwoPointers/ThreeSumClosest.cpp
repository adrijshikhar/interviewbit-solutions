#include <bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int> &A, int B)
{
  sort(A.begin(), A.end());

  int ans = INT_MAX, low = 0, high = A.size() - 1, s = 0, minDiff = INT_MAX;
  for (int i = 0; i < A.size() - 2; i++)
  {
    low = 0;
    high = A.size() - 1;
    while (low < high)
    {
      s = A[low] + A[high] + A[i];
      int diff = abs(B - s);
      if (diff < minDiff)
      {
        minDiff = diff;
        ans = s;
      }
      if (s > B)
      {
        high--;
      }
      else
      {
        low++;
      }
    }
  }

  return ans;
}

int main()
{
  vector<int> v1{
      10, -6, 3, 4, -8, -5};
  int v2 = 3;
  int v3 = threeSumClosest(v1, v2);
  cout << v3;

  return 0;
}
